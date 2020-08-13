package main

import "fmt"

func main() {
	var s = []int{1}
	fmt.Printf("cap of slice %d\n", cap(s))

	s[0] = 2

	fmt.Printf("cap of slice %d\n", cap(s))

	var ar [5]int
	printArray(ar, "5 item array")

	var sl = ar[:4]
	printSlice(sl, "4 item slice")

	var slcopy = sl[:3]
	printSlice(slcopy, "3 item slice copy")

	slcopy[2] = 1

	printArray(ar, "5 item array")
	printSlice(sl, "4 item slice")
	printSlice(slcopy, "3 item slice copy")

	weekdays := []string{"Mon", "Tues", "Wed", "Thur", "Fri"}
	longweekend := weekdays[3:]
	friday := longweekend[1:]
	printSSlice(weekdays, "weekdays")
	printSSlice(longweekend, "longweekend")
	printSSlice(friday, "friday")
}

func printArray(arr [5]int, message string) {
	fmt.Println(message)
	for i, a := range arr {
		fmt.Printf("%d: %d\n", i, a)
	}
}

func printSlice(slice []int, message string) {
	fmt.Println(message)
	for i, a := range slice {
		fmt.Printf("%d: %d\n", i, a)
	}
}

func printSSlice(slice []string, message string) {
	fmt.Println(message)
	for i, a := range slice {
		fmt.Printf("%d: %s\n", i, a)
	}
}
