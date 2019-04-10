if test $# -ne 1
then
	echo "Enter the filename and try again"
else
	if test -f $1
	then 
		echo "File Exists"
	else
		echo "File does not exist"
	fi
fi