#!/bin/bash

count=0

while read line 	#Line is any variable name
do
	count=$((count+1))
done < fibonacci.sh		#Instead of reading from stdin read from this file
echo "$count"
echo -e "No of lines = ${count}\nEnd of correct version" #-e denotes escape sequences can be used

#****************************************************************************************
readLine2()	#A problematic version, this wont work, written just to understand the concept
{
	count=0
	cat fibonacci.sh|while read line
do
	count=$((count+1))
	
	echo "$count"
done

echo "No of lines = ${count}"
}

readLine2	#calling this fn
echo "End of 2version (wrong one) cat this file to understand the error"

<<-EOF
Multi-line comment:
Why did we get the no. of lines as 0 in this fn.?
It's because when we piped the next command will run in a new shell, so while will run in a new shell which has it's own copy of the local variable count and increments it.
As soon as it finishes it's work it returns back to the original shell,
where the count variable (local to this shell) is still 0,
that's why we get the no. of lines as 0.

EOF

#End the multi-line comment with EOF
#****************************************************************************************

