package main

import (
	"fmt"
	"bufio"
	"os"
)

const SIZE int = 32001

var (
	reader = bufio.NewReader(os.Stdin)
    writer = bufio.NewWriter(os.Stdout)
)


func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}



func solve() {

	var (
		n  = 2
		
		arr [SIZE]int
		vst [SIZE]int
		adj [SIZE][]int
		stk []int
		dp [SIZE]int
	)

	for i := 1; i <= n; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	for i := 1; i <= k; i++ {
		var u,v int
		fmt.Fscan(reader, &u, &v)

		adj[u] = append(adj[u], v)
	}

	for i := 1; i <= n; i++ {
		if vst[i] == 0 {
			dfs(i)
		}
	}

	for l, r := 0, n-1; l <= r; l, r = l+1, r-1 {
	    stk[l], stk[r] = stk[r], stk[l]
	}

	for _, now := range stk {
		dp[now] = max(dp[now], arr[now])
		for _, nxt := range adj[now] {
			dp[nxt] = max(dp[nxt], dp[now] + arr[nxt])
		}
	}



}

func main() {
	defer writer.Flush()

	var t int
	for fmt.Fscan(reader, &t); t >= 0; t-- {
		solve()
	}

}

