#!/bin/bash
vowels()
{
	vow=$(eval "grep -o [aeiou] fibonacci.sh |wc -l")
	# grep -o prints the matching chars/words in a new line andthen counting the no. of lines
	return $vow
}
vowels
vow=$?
echo "No. of vowels = $vow"

consonants()
{       
	eval "grep -o [a-z] fibonacci.sh|grep -v [aeiou]"       

	temp=$(eval "grep -o [a-z] fibonacci.sh|grep -v [aeiou]|wc -l")
	echo "No.of consonants = $temp"

	<<-EOF
        Another way : grep -ov [aeiou] fibonacci.sh|wc -l --> no. of consonants
	== for string comparisons
	-eq for integer comparisons

	These are comments

	if test $temp -eq 21
	then
		temp=$((temp+1-10))
		echo "temp = $temp"
	fi
	
	if test temp=="21"
	then
		temp=$((temp+1-10))
		echo "temp = $temp"
	fi

	EOF

}
consonants
