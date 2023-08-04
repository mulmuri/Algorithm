package main

import "fmt"



func reverse(str string) string {
	var rev string

	for i := len(str)-1; i >= 0; i-- {
		rev += string(str[i])
	}

	return rev
}


func main() {
	var str string

	var list [26]int

	fmt.Scan(&str)

	for _, char := range str {
		list[char-'A']++
	}

	var mid string
	var ans string

	for char, cnt := range list {
		for i := 0; i < cnt/2; i++ {
			ans += string(rune(char + 'A'))
		}
		if cnt%2 != 0 {
			if mid == "" {
				mid = string(rune(char + 'A'))
			} else {
				fmt.Println("I'm Sorry Hansoo")
				return
			}
		}
	}

	fmt.Println(ans + mid + reverse(ans))
}