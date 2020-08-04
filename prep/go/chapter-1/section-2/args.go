package main

import (
	"fmt"
	"os"
)

func main() {
	var s string

	l := len(os.Args)

	if l == 1 {
		fmt.Println("no args!")
		return
	}

	for i := 1; i < l; i++ {
		s += " " + os.Args[i]
	}
	fmt.Println(s)
}
