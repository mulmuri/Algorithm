package main

import "fmt"



var n int = 5

var arr [5][5]int

var list map[int]struct{}



var dy []int = []int{0, 0, 1, -1}
var dx []int = []int{1, -1, 0, 0}

func bfs(lv int, x int, y int, v int) {
	v += arr[x][y]
	defer func() {
		v %= 10
	}()

	if lv == 0 {
		list[v] = struct{}{}
		return
	}

	for i := 0; i<4; i++ {
		nx := x + dx[i]
		ny := y + dy[i]

		if nx < 0 || nx >= n || ny < 0 || ny >= n {
			continue
		}

		bfs(lv-1, nx, ny, v * 10)
	}
}


func main() {

	list = make(map[int]struct{})

	for i := 0; i<n; i++ {
		for j := 0; j<n; j++ {
			fmt.Scanf("%d", &arr[i][j])
		}
	}

	for i := 0; i<n; i++ {
		for j := 0; j<n; j++ {
			bfs(5, i, j, 0)
		}
	}

	fmt.Printf("%d\n", len(list))
}