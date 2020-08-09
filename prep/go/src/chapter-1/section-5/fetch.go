package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
)

func main() {
	if len(os.Args) == 1 {
		fmt.Println("Give me a url yo.")
		return
	}
	url := os.Args[1]
	resp, err := http.Get(url)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error fetching %s: %v\n", url, err)
		return
	}
	body, err := ioutil.ReadAll(resp.Body)
	resp.Body.Close()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error reading response %s: %v\n", url, err)
		return
	}
	fmt.Printf("%s\n", body)
}
