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

	var archetypal [100]int

	for i := 0; i < len(archetypal); i++ {
		archetypal[i] = i
	}
	fmt.Printf("archetypal[45]: %d\n", archetypal[45])

	var archetypal2 = [100]int{}

	for i := 0; i < len(archetypal2); i++ {
		archetypal2[i] = i
	}
	fmt.Printf("Array literal archetypal[45]: %d\n", archetypal2[45])

	var a = [...]string{usd: "$", gb: "g", eur: "e"}
	fmt.Println(a[2]) // => g

	var b = [...]int{99: -1}
	fmt.Println(b[45]) // => 0

	var c = [100]int{1, 2, 3}
	fmt.Println(c[1])  // => 2
	fmt.Println(c[65]) // => 0
}
