package main

import (
	"bufio"
	"fmt"
	"os"
)

// Count the number of duplicated lines
func main() {
	counts := make(map[string]int)
	input := bufio.NewScanner(os.Stdin)
	for input.Scan() {
		counts[input.Text()]++
	}
	for text, count := range counts {
		if count > 1 {
			fmt.Printf("%s: %d\n", text, count)
		}
	}
}
