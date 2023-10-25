package main

import "strings"

func reverseWords(s string) string {
	list := strings.Fields(s)
	for i := 0; i < len(list)/2; i += 1 {
		list[i], list[len(list)-1-i] = list[len(list)-1-i], list[i]
	}
	return strings.Join(list, " ")
}
