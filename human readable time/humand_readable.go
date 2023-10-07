package main

import "fmt"

func HumanReadableTime(s int) string {
	m, s := s/60, s%60
	h, m := m/60, m%60
	return fmt.Sprintf("%02d:%02d:%02d", h, m, s)
}
