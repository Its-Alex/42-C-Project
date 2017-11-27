package main

import (
	"fmt"
	"os"
	"strings"
)

func findFromX(str *string, index int) []int {
	begin, end := 0, index+3

	for ; (*str)[index] >= '0' && (*str)[index] <= '9'; index-- {
		begin = index
	}
	fmt.Println(begin, end)
	fmt.Println((*str)[begin:end])
	return make([]int, 6)
}

func parseEqua(equa string) []int {
	value := make([]int, 6)

	str := strings.Replace(equa, " ", "", -1)
	str = strings.ToLower(str)
	s := strings.Split(str, "=")
	findFromX(&s[0], strings.Index(s[0], "x^1"))
	fmt.Printf("%c\n", s[0][6])
	fmt.Println(strings.Index(s[0], "x^1"))

	return value
}

func main() {
	if len(os.Args) < 2 {
		fmt.Println("Need to pass equation like this: ./ComputorV1 \"5X^1 = 0\"")
		os.Exit(0)
	}
	equa := os.Args[1:2][0]

	if equa == "" || strings.Index(equa, "=") == -1 {
		fmt.Println("Equation not well formated")
		os.Exit(0)
	}

	parsed := parseEqua(equa)
	fmt.Println(parsed)
	// for index := 0; index < len(split); index++ {
	// 	fmt.Println(split[index])
	// }
}
