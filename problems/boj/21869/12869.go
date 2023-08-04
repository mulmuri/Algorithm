package main

import (
	"bufio"
	"fmt"
	"os"
)



var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)


func main() {
	defer writer.Flush()

	var n int32

	fmt.Fscanf(reader, "%d\n", &n)

	if n == 1 {
		fmt.Fprintf(writer, "1\n1 1")
		return
	}

	fmt.Fprintf(writer, "%d\n", n*2-2)
	for  i  := int32(1); i < n; i++ {
		fmt.Fprintf(writer, "%d 1\n", i)
	}

	for i := int32(1); i < n; i++ {
		fmt.Fprintf(writer, "%d %d\n", i, n)
	}
}