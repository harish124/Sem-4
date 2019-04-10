max=$1

for((i=1;i<=max;i++))
do
	for((j=max;j>i;j--))
	do
		echo -n " "
	done

	for((k=1;k<=i;k++))
	do
		echo -n "* "
	done

	echo 

done