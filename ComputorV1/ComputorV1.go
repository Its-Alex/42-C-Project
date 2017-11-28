package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func findFromX(str string) (int, int, int) {
	posx := make([]int, 3)
	for pow := 0; pow < 3; pow++ {
		pos := strings.Index(str, "*x^"+strconv.Itoa(pow))
		if pos != -1 {
			posx[pow] = 0
		} else {
			for count := pos; str[count] >= '0' && str[count] >= '9' && count >= 0; count-- {
				fmt.Println(str[count])
			}
		}
	}
	return posx[0], posx[1], posx[2]
}

func parseEqua(equa string) []int {
	value := make([]int, 6)

	str := strings.Replace(equa, " ", "", -1)
	str = strings.ToLower(str)
	s := strings.Split(str, "=")
	value[0], value[1], value[2] = findFromX(s[0])
	value[3], value[4], value[5] = findFromX(s[1])
	fmt.Println(s)

	return value
}

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Need to pass equation like this: ./ComputorV1 \"5 * X^1 = 0\"")
		os.Exit(0)
	}
	equ := strings.Split(os.Args[1], "=")
	if len(equ) != 2 {
		fmt.Println("os.Args[1]tion not well formated")
		os.Exit(0)
	}

	parsed := parseEqua(os.Args[1])
	fmt.Println(parsed)
	// for index := 0; index < len(split); index++ {
	// 	fmt.Println(split[index])
	// }
}
