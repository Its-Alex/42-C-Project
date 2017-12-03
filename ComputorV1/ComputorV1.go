package main

import (
	"fmt"
	"math"
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

func printData(equa []float64) {
	fmt.Print("Reduced form:")
	for count := len(equa) - 1; count >= 0; count-- {
		if equa[count] < 0 {
			fmt.Printf(" - %g * X^%d", -equa[count], count)
		} else {
			if count == len(equa)-1 {
				fmt.Printf(" %g * X^%d", equa[count], count)
			} else {
				fmt.Printf(" + %g * X^%d", equa[count], count)
			}
		}
	}
	fmt.Println(" = 0")
	fmt.Printf("Polynomial degree: %d\n", len(equa)-1)
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
	for index := 0; index < len(valueLeft); index++ {
		valueLeft[index] -= valueRight[index]
	}

	/*
	** Print reduced and degree
	 */
	printData(valueLeft)
	if len(valueLeft) > 3 {
		fmt.Println("The polynomial degree is stricly greater than 2, I can't solve.")
		os.Exit(0)
	}

	if len(valueLeft) == 2 {
		fmt.Printf("Need to resolve!")
	}
	if len(valueLeft) == 1 {
		fmt.Printf("The solution is:\n%g", valueLeft[0])
	}
	delta := valueLeft[1]*valueLeft[1] - 4*valueLeft[0]*valueLeft[2]
	// fmt.Println(delta)
	if delta > 0 {
		result := make([]float64, 2)
		result[0] = (-valueLeft[1] - math.Sqrt(delta)) / (2 * valueLeft[2])
		result[1] = (-valueLeft[1] + math.Sqrt(delta)) / (2 * valueLeft[2])
		fmt.Printf("Discriminant is strictly positive, the two solutions are:\n%g\n%g\n", result[0], result[1])
	} else if delta < 0 {
		fmt.Println("Discriminant is strictly negative")
	} else {
		fmt.Printf("Discriminant is null, the solution is:\n%g\n", -valueLeft[1]/(2*valueLeft[2]))
	}
}
