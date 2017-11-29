package main

import (
	"fmt"
	"os"
	"regexp"
	"strconv"
	"strings"
)

func getValue(data [][]string) []float64 {
	var pow int
	var value float64
	var tab []float64
	for count := 0; count < len(data); count++ {
		pow, _ = strconv.Atoi(data[count][2])
		for len(tab) <= pow {
			tab = append(tab, 0)
		}
		value, _ = strconv.ParseFloat(data[count][1], 64)
		tab[pow] += value
	}
	return tab
}

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Need to pass equation like this: ./ComputorV1 \"5 * X^1 = 0\"")
		os.Exit(0)
	}
	equ := os.Args[1]
	str := strings.Replace(equ, " ", "", -1)
	str = strings.ToUpper(str)
	s := strings.Split(str, "=")
	if len(s) != 2 {
		fmt.Println("Equation not well formated")
		os.Exit(0)
	}

	re1, _ := regexp.Compile(`(\-?[0-9]+|\-?[0-9]+\.[0-9]+)\*X\^([0-9]+)`)
	left, right := re1.FindAllStringSubmatch(s[0], -1), re1.FindAllStringSubmatch(s[1], -1)
	var valueLeft, valueRight []float64
	valueLeft = getValue(left)
	valueRight = getValue(right)
	for len(valueLeft) != len(valueRight) {
		if len(valueLeft) < len(valueRight) {
			valueLeft = append(valueLeft, 0)
		} else {
			valueRight = append(valueRight, 0)
		}
	}
	fmt.Println(valueLeft)
	fmt.Println(valueRight)
	for index := 0; index < len(valueLeft); index++ {
		valueLeft[index] -= valueRight[index]
	}
	if len(valueLeft) > 3 {
		fmt.Println()
	}
	delta :=
		fmt.Println(valueLeft)

}
