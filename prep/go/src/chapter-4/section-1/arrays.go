package main

import "fmt"

type currency int

const (
	usd currency = iota
	eur
	gb
)

func main() {
	fmt.Println(gb)
	fmt.Printf("%d\n", gb)

	var a = [...]string{usd: "$", gb: "g", eur: "e"}
	fmt.Println(a[2]) // => g

	var b = [...]int{99: -1}
	fmt.Println(b[45]) // => 0

	var c = [100]int{1, 2, 3}
	fmt.Println(c[1])  // => 2
	fmt.Println(c[65]) // => 0
}
