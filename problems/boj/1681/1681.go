package main

import (
	"fmt"
	"strconv"
	"strings"
)



func main() {

	var n int
	var l int

	fmt.Scanf("%d %d", &n, &l)

	var ans = 1

	for ; n != 0; n-- {
		for {
			str := strconv.Itoa(ans)
			ans++
			if strings.Contains(str, strconv.Itoa(l)) {
				continue
			}
			break
		}		
	}

	fmt.Println(ans-1)
}