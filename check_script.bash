#!/bin/bash

echo  "Push_Swap:"
./push_swap $@;
if valgrind -s --leak-check=full --show-mismatched-frees=yes ./push_swap "$@" 2>&1 | grep -E "All heap blocks were freed -- no leaks are possible" && ! grep -E "ERROR SUMMARY: [1-9]" <<< "$(valgrind -s --leak-check=full --show-mismatched-frees=yes ./push_swap "$@" 2>&1)"; then
	echo "Valgrind check: OK"
else
	echo "Valgrind KO"
fi

echo -ne "Checker: ";
./push_swap $@ | ./checker_linux $@;
echo -ne "Instructions: "
./push_swap $@ | wc -l;
