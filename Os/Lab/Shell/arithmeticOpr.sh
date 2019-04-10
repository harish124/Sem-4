if test $# -ne 3
then
	echo "Not enough arguments"
else
	case $2 in
		'+')
			echo `expr $1 + $3`
			;;
		'-')
			echo `expr $1 - $3`
			;;
		'@')
			echo `expr $1 \\* $3`
			;;
		'/')
			echo `expr $1 / $3`
			;;

	esac
fi