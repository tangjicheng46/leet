package main

import (
	"fmt"
)

func isMatch(s string, p string) bool {
	if p == "" {
		return s == ""
	}

	firstMatch := false
	if s != "" && (s[0] == p[0] || p[0] == '.') {
		firstMatch = true
	}

	if len(p) >= 2 && p[1] == '*' {
		return (isMatch(s, p[2:]) || (firstMatch && isMatch(s[1:], p)))
	} else {
		return firstMatch && isMatch(s[1:], p[1:])
	}
}

func main() {
	s := "b"
	p := "a*b"
	result := isMatch(s, p)
	fmt.Println(result) // 输出：true
}
