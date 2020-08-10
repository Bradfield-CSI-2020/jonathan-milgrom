package vm

import (
	"errors"
	"fmt"
	"os"
)

const (
	// Load a value into memory
	// usage: Load R1 0x01 		# Load data from byte 1 into register 1
	Load = 0x01
	// Store a value in the output byte (0x00) of memory from a register
	// usage: Store R1 0x00     # Place the value in R1 into the output location
	Store = 0x02
	// Add two values and store in first
	// usage: add R1 R2       	# Add the two register values, store the result in r1
	Add = 0x03
	// Sub (tract) two values and store in first
	// usage: sub R1 R2			# Set r1 = r1 - r2
	Sub = 0x04
	// Halt program
	// usage: halt
	Halt = 0xff
)

// Stretch goals
const (
	Addi = 0x05
	Subi = 0x06
	Jump = 0x07
	Beqz = 0x08
)

// Register is a enumeration of register addresses
type register int

const (
	// PC is pogram counter
	PC register = iota
	// R1 is the first general purpose register
	R1
	// R2 is the second general purpose register
	R2
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
		if address > maxAddress {
			return
		}

		op := memory[address]

		// decode and execute
		switch instructionArity[op] {
		case nullary:
			switch op {
			case Halt:
				registers[PC]++
				return
			}
		case binary:
			a, b, err := fetchTwo(memory, address, maxAddress)
			if err != nil {
				fmt.Fprintf(os.Stderr, err.Error())
				return
			}
			handleBinaryInstructions(&registers, memory, op, a, b)
		default:
			fmt.Fprintf(os.Stderr, "Unsupported operation %x\n", op)
			return
		}
	}
}

func handleBinaryInstructions(registers *[3]byte, memory []byte, op byte, a byte, b byte) {
	switch op {
	case Load:
		register, dataAddress := a, b
		registers[register] = memory[dataAddress]
	case Store:
		register, _ := a, b
		memory[OutputAddress] = registers[register]
	case Add:
		registerA, registerB := a, b
		registers[registerA] += registers[registerB]
	case Sub:
		registerA, registerB := a, b
		registers[registerA] -= registers[registerB]
	}
	registers[PC] += 3
}

func fetchTwo(memory []byte, start int, max int) (byte, byte, error) {
	second := start + 2
	if second > max {
		return 0, 0, errors.New("memory allocation exceeded")
	}
	return memory[start+1], memory[second], nil
}
