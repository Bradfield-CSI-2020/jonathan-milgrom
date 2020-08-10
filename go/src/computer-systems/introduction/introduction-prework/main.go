package main

import (
	"computer-systems/introduction/introduction-prework/vm"
	"fmt"
)

func main() {
	var memory = make([]byte, 256)
	memory[1] = 3
	memory[2] = 5
	memory[8] = vm.Load
	memory[9] = byte(vm.R1)
	memory[10] = 0x02
	memory[11] = vm.Store
	memory[12] = byte(vm.R1)
	memory[13] = 0x00
	memory[14] = vm.Halt

	vm.Compute(memory)

	printMemory(memory[:20])
}

func printMemory(memory []byte) {
	for i, b := range memory {
		fmt.Printf("%d: %x\n", i, b)
	}
}
