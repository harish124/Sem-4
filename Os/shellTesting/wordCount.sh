#!/bin/bash

#Aim: to list all the files whose size is greater than 10M and less than 15M

find . -type f -iname "*.*" -size 1k|xargs wc -w|awk '{print $1}'

test1()
{
	for i in *
	do
		echo -n "$i "
		op=$(eval "find . -type f -iname "$i" -size 1k|xargs wc -w"|awk '{print $1}')
		echo -e "\nop = $op\n"

		if test $op -gt 10240
		then
			echo "hello world"
		fi
	done
}
test1
