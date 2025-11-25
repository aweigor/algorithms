package main

import (
	"fmt"
	"strings"
)

func Tribonacci(signature [3]float64, n int) (r []float64) {
	r = signature[:]
	for i := 0; i < n; i++ {
		l := len(r)
		r = append(r, r[l-1]+r[l-2]+r[l-3])
	}
	return r[:n]
}

// www.codewars.com/kata/52fba66badcd10859f00097e
func Disemvowel(comment string) string {
	isConsonant := func(letterRune rune) (bool) {
		vowels := "aeiouAEIOU"
		return !strings.ContainsRune(vowels, letterRune)
	}
	var builder strings.Builder
	for _, r := range comment {
		if (isConsonant(r)) {
			builder.WriteRune(r)
		}
	}
	return builder.String()
}

func DisemvowelClean(comment string) string {
	for _,c := range "aiueoAIUEO"{
		 comment = strings.ReplaceAll(comment, string(c), "")
	 }
	 return comment
}

// https://www.codewars.com/kata/5648b12ce68d9daa6b000099/
func Passengers(busStops [][2]int) int {
  var result int
	for _, inout := range busStops {
		result += inout[0]
		result -= inout[1]
		if (result < 0) {
			return 0
		}
	}
  return result
}

func Passengers_clean(busStops [][2]int) (inBus int) {
  for _, stopInfo := range busStops {
    inBus += stopInfo[0] - stopInfo[1]
  }  
  return
}

// https://www.codewars.com/kata/56747fd5cb988479af000028/
func GetMiddle(s string) string {
	mid := len(s) / 2
	if len(s) < 2 {
		return s
	}
	if len(s) % 2 == 0 {
		return s[mid-1:mid+1]
	} else {
		return s[mid:mid+1]
	}	
}

func GetMiddle_clean(s string) string {
	n := len(s)
	if n==0 {return s}
	return s[(n - 1) / 2 : n / 2 + 1]
}

func main() {
	result := Tribonacci([3]float64{1, 1, 1}, 10)
  fmt.Println("Tribonacci:", result)
	result2 := Disemvowel("This website is for losers LOL!")
	fmt.Println("Disemvowel:", result2)
	result3 := GetMiddle("Test")
	fmt.Println("GetMiddle:", result3)
}
