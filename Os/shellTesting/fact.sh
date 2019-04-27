#!/bin/bash

fact()
{
	n=$1
	a=1
	while test $n -gt 0
	do
		a=$((a*n))
		n=$((n-1))
	done
	echo "$a"
}
echo -e "\nEnter any no: "
read n
fact $n
