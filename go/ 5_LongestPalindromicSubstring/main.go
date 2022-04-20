package main

import "fmt"

func main() {
	//fmt.Println("test")
	cases := []string{"babad", "cbbd"}
	for _, c := range cases {
		s := longestPalindrome(c)
		fmt.Println(s)
	}
}

func longestPalindrome(s string) string {
	le := len(s)
	dp := make([][]bool, le)
	for i := 0; i < le; i++ {
		dp[i] = make([]bool, le)
		for j := 0; j < le; j++ {
			if i == j {
				dp[i][j] = true
			} else {
				dp[i][j] = false
			}
		}
	}

	var l, r int
	for d := 1; d < le; d++ {
		for i := 0; i < le-d; i++ {
			j := i + d
			dp[i][j] = (s[i] == s[j]) && ((j-i < 3) || dp[i+1][j-1])
			if dp[i][j] {
				//fmt.Printf("i:%d, j:%d, dp:%v\n", i, j, dp[i][j])
				l = i
				r = j
			}
		}
	}

	return s[l : r+1]
}
