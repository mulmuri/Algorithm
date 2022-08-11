package main

import (
	"fmt"
	"strings"
)

func main(){
    var a, b string
    fmt.Scan(&a, &b)

	if strings.Contains(a, b) {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}