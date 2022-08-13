package main

import (
	"fmt"
	"bufio"
	"os"
)



const SIZE int = 32001


var (
	n, m int
	vst [SIZE]int
	adj [SIZE][]int
	stk []int
)



func dfs(now int) {
	vst[now] = 1
	for _, nxt := range adj[now] {
		if vst[nxt] == 0 {
			dfs(nxt)
		}
	}

	stk = append(stk, now)
}

func sol1() {
	reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

	fmt.Fscan(reader, &n, &m)
	for i := 1; i <= m; i++ {
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

	for _, v := range stk {
		fmt.Fprint(writer, v, " ")
	}

}

