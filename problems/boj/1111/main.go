package main

import "fmt"

/*

ax + b = y
ay + b = z
az + b = t

x y z t 가 주어짐

(y-x)a = z-y
a = (z-y)/(y-x)

b = y - ax


*/

var n int
var arr []int

func main() {
	fmt.Scan(&n)

	arr = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	if n == 1 {
		fmt.Println("A")
		return
	}

	if n == 2 {
		if arr[0] == arr[1] {
			fmt.Println(arr[0])
		} else {
			fmt.Println("A")
		}
		return
	}

	if arr[1] == arr[0] {
		for i := 1; i < n; i++ {
			if arr[i] != arr[i-1] {
				fmt.Println("B")
				return
			}
		}
		fmt.Println(arr[0])
		return
	}

	a := (arr[2] - arr[1]) / (arr[1] - arr[0])
	b := arr[1] - arr[0]*a

	for i := 1; i < n; i++ {
		if arr[i] != arr[i-1]*a+b {
			fmt.Println("B")
			return
		}
	}

	fmt.Println(a*arr[n-1] + b)
}