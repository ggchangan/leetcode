package main

import (
	"fmt"
)

func main() {
	cases := [][]int{
		{2, 3, 1, 1, 4},
		{3, 2, 1, 0, 4},
	}
	for _, c := range cases {
		if canJump(c) {
			fmt.Println("true")
		} else {
			fmt.Println("false")
		}
	}
}

func canJump(nums []int) bool {
	le := len(nums)
	if le == 0 {
		return false
	}

	if le == 1 {
		return true
	}

	maxJump := nums[0]
	for i, v := range nums {
		if i > maxJump {
			return false
		}
		if maxJump < i+v {
			maxJump = i + v
		}
	}

	return true
}
