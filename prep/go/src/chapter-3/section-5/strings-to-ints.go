package main

import (
	"bytes"
	"fmt"
	"strconv"
)

func main() {
	a := "123"
	i, _ := strconv.Atoi(a)
	fmt.Printf("%d\n", i)

	var buf bytes.Buffer
	fmt.Fprintf(&buf, "%d", i)
	fmt.Println(buf.String())

	fmt.Printf("%b\n", i)
}
