package main

import (
	"chapter-2/section-5/temperature"
	"fmt"
)

func main() {
	var c temperature.Celcius = 100
	fmt.Printf("to fahr: %s\n", c.ToF())
	fmt.Printf("back to celc: %s\n", c.ToF().ToC())
}
