#!/bin/bash

pattern1()
{
	i=$1
	j=$i
	while test $i -gt 0
	do
		j=$1
		while test $j -ge $i
		do

			echo -n $j
			j=$((j-1))
		done
		
		i=$((i-1))

		echo ""
	done
}
pattern2()
{
	n=$1	
	temp=$n
	while test $n -gt 0
	do
		j=$temp
		space=0
		while test $space -lt $n
		do
			echo -n " "
			space=$((space+1))
		done

		while test $j -ge $n
		do
			echo -n "$2 "
			j=$((j-1))
		done

		n=$((n-1))
		echo ""
	done


}
echo -e "\nPattern 1 below: \n"
echo "Enter any no: "
read a
echo ""
pattern1 $a

echo -e "\nPattern 2 below:\n "
echo -e "\nEnter any no:"
read a
echo -e "\nEnter any character:"
read c
pattern2 $a $c
