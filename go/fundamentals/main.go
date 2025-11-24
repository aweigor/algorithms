package fundamentals

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

func main() {
	result := Tribonacci([3]float64{1, 1, 1}, 10)
  fmt.Println("Tribonacci:", result)
	result2 := Disemvowel("This website is for losers LOL!")
	fmt.Println("Disemvowel:", result2)

}
