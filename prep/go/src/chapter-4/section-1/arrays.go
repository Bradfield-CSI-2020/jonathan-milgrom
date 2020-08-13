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

	fmt.Printf("Array literal archetypal[45]: %d\n", archetypal2[45])

	var a = [...]string{usd: "$", gb: "g", eur: "e"}
	fmt.Println(a[2]) // => g

	var b = [...]int{99: 0}
	fmt.Println(b[45]) // => 0
	fmt.Printf("typeof [...]int{99: 0}: %T \n", b)
	fmt.Printf("typeof [100]int{}: %T \n", archetypal2)
	fmt.Printf("var archetypal [100]int: %T \n", archetypal)
	fmt.Printf("[...]int{99: 0} == [100]int{}: %t \n", b == archetypal2)
	fmt.Printf("[100]int == [100]int{}: %t \n", archetypal == archetypal2)

	var c = [100]int{1, 2, 3}
	fmt.Println(c[1])  // => 2
	fmt.Println(c[65]) // => 0
}
