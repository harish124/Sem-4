echo "Enter any 3 nos"
read a b c

if [ $a -gt $b -a $a -gt $c ]
 then
	echo "Grt = $a"
elif [ $b -gt $a -a $b -gt $c ]
then
	echo "Grt = $b"
else
	echo "Grt = $c"

fi