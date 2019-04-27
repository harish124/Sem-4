#!/bin/bash

echo "Enter any filename(with extension): "
read filename
echo "No. of spaces in the file = "
grep -o " " $filename|wc -l

# The grep -o will o/p the matching spaces in a new line then piping the o/p to wc which will count the no. of lines which
# is desired o/p.
