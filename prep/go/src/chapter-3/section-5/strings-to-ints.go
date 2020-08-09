package main

import (
	"bytes"
	"fmt"
	"strconv"
)

func main() {
	a := "123"
	i, _ := strconv.Atoi(a) // string to int through strconv.Atio
	fmt.Printf("%d\n", i)
	x, _ := strconv.ParseInt(a, 10, 64) // string to string through strconv.ParseInt
	fmt.Println(x)

	var buf bytes.Buffer
	fmt.Fprintf(&buf, "%d", i)
	fmt.Println(buf.String()) // int to string through buffer.String

	fmt.Printf("%b\n", i) // int to binary
}
