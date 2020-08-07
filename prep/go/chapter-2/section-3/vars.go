package main

import (
	"fmt"
	"strings"
)

func main() {
	var a, b, c = 1, 1.2, "hey"
	fmt.Printf("%d, %g, %s\n", a, b, c)

	d, e, f := 1, 1.2, "hey"
	fmt.Printf("%d, %g, %s\n", d, e, f)

	var g string = "hey"
	fmt.Printf("%s\n", g)

	s := []string{g, "y"}
	fmt.Printf("%s\n", strings.Join(s, ""))

	var h = "hey"
	fmt.Printf("%s\n", h)
}
