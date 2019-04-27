#!/bin/bash

isPrime()
{
	n=$1
	if test $n -le 1
	then
		return 0
	elif test $n -lt 4
	then
		return 1
	elif test $((n%2)) -eq 0
	then
		return 0
	elif test $((n%3)) -eq 0
	then
		return 0
	elif test $n -lt 8
	then 
		return 1
	fi

	r=$(echo "sqrt($n)"|bc)
	#echo "root = $r"

	if test $((r*r)) -eq $n
	then
		return 0
	fi

	f=5
	while test $f -le $r
	do
		if test $((n%f)) -eq 0
		then
			return 1
		elif test $((n%(f+2))) -eq 0
		then
			return 0
		fi
		f=$((f+6))
	done

	return 1

}
echo "Enter any no: "
read n
isPrime $n
if test $? -eq 1
then 
	echo "${n} is a prime number"
else
	echo "${n} is not a prime number"
fi
