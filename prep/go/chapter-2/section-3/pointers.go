package main

import (
	"flag"
	"fmt"
	"os"
	"strings"
)

var n = flag.Bool("n", false, "omit trailing newline")
var sep = flag.String("s", " ", "separator")

// echo the arguments, now with flags n, s
func main() {
	flag.Parse()
	fmt.Print(strings.Join(flag.Args() /* looks like this automatically skips first of os.Args */, *sep))
	if !*n {
		fmt.Println()
	}

	fmt.Println("sanity check:", strings.Join(os.Args, " "))
}
