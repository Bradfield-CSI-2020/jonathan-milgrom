package main

import (
	"fmt"
	"os"
	"strings"
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

	s = ""
	for _, arg := range os.Args[1:] {
		s += " " + arg
	}
	fmt.Println("range:", s)

	fmt.Println("join:", strings.Join(os.Args[1:], " "))
}
