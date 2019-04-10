if [ $2 -gt $3 ]
then	
	echo "Error"
else
	cat $1 | head -$3 |tail -`expr $3 - $2 + 1`
		
fi