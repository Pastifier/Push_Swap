#!/bin/bash

echo  "Push_Swap:"
valgrind -s --leak-check=full --show-mismatched-frees=yes ./push_swap $@;

echo -n "Checker: ";
./push_swap $@ | ./checker_linux $@;
echo -n "Instructions: "
./push_swap $@ | wc -l;
