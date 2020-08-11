package vm

import (
	"errors"
	"fmt"
	"os"
)

const (
	// Load a value into memory
	// usage: Load R1 0x01	# Load data from byte 1 into register 1
	Load = 0x01
	// Store a value in the output byte (0x00) of memory from a register
	// usage: Store R1 0x00	# Place the value in R1 into the output location
	Store = 0x02
	// Add two values and store in first
	// usage: add R1 R2 	# Add the two register values, store the result in r1
	Add = 0x03
	// Sub (tract) two values and store in first
	// usage: sub R1 R2		# Set r1 = r1 - r2
	Sub = 0x04
	// Halt program
	// usage: halt
	Halt = 0xff
)

// Stretch goals
const (
	// Addi (add) for immediate args
	// usage: Addi R1 4 	# r1 = r1 + 4
	Addi = 0x05
	// Subi (sub) for immediate args
	// usage: Subi R1 4 	# r1 = r1 - 4
	Subi = 0x06
	// Jump to an instruction
	// usage: Jump 0xXX		# Jump 40 will cause the program to continue from the 40th byte in memory
	Jump = 0x07
	// Beqz is a conditional instruction: if register is zero offset program counter by supplied amount
	// usage: Beqz R1 9		# if R1 is 0, increase program counter by 9
	Beqz = 0x08
)

// Register is a enumeration of register addresses
type register int

const (
	PC register = iota // PC is pogram counter
	R1                 // R1 is the first general purpose register
	R2                 // R2 is the second general purpose register
)

type arity int

const (
	nullary arity = iota
	unary
	binary
)

var instructionArity = map[byte]arity{
	Load:  binary,
	Store: binary,
	Add:   binary,
	Sub:   binary,
	Halt:  nullary,
	Addi:  binary,
	Subi:  binary,
	Jump:  unary,
	Beqz:  binary,
}

// OutputAddress is the address reserved for the progam output
const OutputAddress = 0x00

// Compute the result of a set of instructions
//
// Given a 256 byte array of "memory", run the stored program
// to completion, modifying the data in place to reflect the result
//
// The memory format is:
//
// 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f ... ff
// __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ ... __
// ^==DATA===============^ ^==INSTRUCTIONS==============^
//
func Compute(memory []byte) {

	registers := [3]byte{
		PC: 8, // Program Counter: address of next instruction
		R1: 0, // R1: a value
		R2: 0, // R2: a value
	}

	maxAddress := cap(memory) - 1

	// Keep looping, like a physical computer's clock
	for {
		address := int(registers[PC])
		op, err := fetch(memory, address, maxAddress)
		if err != nil {
			fmt.Fprintf(os.Stderr, err.Error())
			return
		}

		// decode and execute
		switch instructionArity[op] {
		case nullary:
			switch op {
			case Halt:
				return
			}
		case unary:
			a, err := fetch(memory, address+1, maxAddress)
			if err != nil {
				fmt.Fprintf(os.Stderr, err.Error())
				return
			}

			switch op {
			case Jump:
				registers[PC] = a
			}
		case binary:
			a, _ := fetch(memory, address+1, maxAddress)
			b, err := fetch(memory, address+2, maxAddress)
			if err != nil {
				fmt.Fprintf(os.Stderr, err.Error())
				return
			}

			switch op {
			case Load:
				registers[a] = memory[b]
			case Store:
				memory[OutputAddress] = registers[a]
			case Add:
				registers[a] += registers[b]
			case Sub:
				registers[a] -= registers[b]
			case Addi:
				registers[a] += b
			case Subi:
				registers[a] -= b
			case Beqz:
				if registers[a] == 0 {
					registers[PC] += b
				}
			}
			registers[PC] += 3
		default:
			fmt.Fprintf(os.Stderr, "Unsupported operation %x\n", op)
			return
		}
	}
}

func fetch(memory []byte, index int, maxIndex int) (byte, error) {
	if index > maxIndex {
		return 0, errors.New("memory allocation exceeded")
	}
	return memory[index], nil
}
