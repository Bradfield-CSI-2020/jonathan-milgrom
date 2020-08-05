package main

import (
	"bufio"
	"fmt"
	"os"
)

// Count the number of duplicated lines
// read files as well as standard input; when no arguments are provided, assume client will input stdio
func main() {
	counts := make(map[string]int)
	files := os.Args[1:] // ignore first argument, the program itself and assume the rest are file names
	if len(files) == 0 {
		countlines(os.Stdin, counts)
		printdups(counts)
		return
	}

	for _, f := range files {
		file, err := os.Open(f)
		if err != nil {
			fmt.Fprintf(os.Stderr, "dup: %v\n", err)
			continue
		}
		countlines(file, counts)
		file.Close()
	}
	printdups(counts)
}

func countlines(file *os.File, counts map[string]int) {
	input := bufio.NewScanner(file)
	for input.Scan() {
		counts[input.Text()]++
	}
}

func printdups(counts map[string]int) {
	fmt.Println()
	for text, count := range counts {
		if count > 1 {
			fmt.Printf("%d\t%s\n", count, text)
		}
	}
}
