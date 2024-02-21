#!/bin/bash

echo  "Push_Swap:"
./push_swap $@;
if valgrind -s --leak-check=full --show-mismatched-frees=yes ./push_swap "$@" 2>&1 | grep -E "ERROR SUMMARY: 0 errors|definitely lost: 0 bytes"; then
	echo "Valgrind check: OK"
else
	echo "Valgrind KO"
fi

echo -ne "Checker: ";
./push_swap $@ | ./checker_linux $@;
echo -ne "Instructions: "
./push_swap $@ | wc -l;
