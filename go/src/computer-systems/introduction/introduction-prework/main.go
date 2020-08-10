package main

import (
	"computer-systems/introduction/introduction-prework/vm"
	"fmt"
)

func main() {
	var memory = make([]byte, 256)
	memory[8] = vm.Load
	fmt.Printf("Load instruction test %s", vm.Compute(memory))
}
