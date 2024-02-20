#!/bin/bash

echo  "Push_Swap:"
./push_swap $@;

echo -n "Checker: ";
./push_swap $@ | ./checker_linux $@;
echo -n "Instructions: "
./push_swap $@ | wc -l;
