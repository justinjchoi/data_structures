#!/bin/bash
# Justin Choi (jc8mc) 
# March 24th 2017 
# CS 2150 - 106, Lab 7: IBCM 

numIter=5

echo "enter the exponent for counter.cpp"
read input

if [ $input == "quit" ]
then
    exit 0
fi

total=0

for (( i=1; i<=numIter; i++ ))
do
    echo "Running iteration ${i}..."
    time=`./a.out ${input}`
    total=`expr $total + $time`
    echo "time taken: ${time} ms"
done

echo "${numIter} iterations took ${total} ms"
echo "Average time was "`expr $total / 5` ms