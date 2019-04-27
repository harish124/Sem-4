#!/bin/bash
fib()
{
	n=$1
	a=0
	b=1
	for((i=0;i<n;i++))
	do
		echo "$a"
		new=$((a+b))
		a=$b
		b=$new
	done
}

fib 10
#hello this is fibonacci
