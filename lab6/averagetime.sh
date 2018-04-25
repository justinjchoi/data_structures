#!/bin/bash
#Justin Choi (jc8mc) 
#March 15th 2017 
#CS 2150 - 106 Lab 6: Hashing 

echo "Enter the dictionary file you wish to read in: " 
read dictionary_file 
echo "Enter the grid file you wish to read in: "
read grid_file 

runtime_1=`./a.out $dictionary_file $grid_file | tail -1`
runtime_2=`./a.out $dictionary_file $grid_file | tail -1`
sum=`expr $runtime_1 + $runtime_2`
runtime_3=`./a.out $dictionary_file $grid_file | tail -1`
sum=`expr $sum + $runtime_3`
runtime_4=`./a.out $dictionary_file $grid_file | tail -1`
sum=`expr $sum + $runtime_4`
runtime_5=`./a.out $dictionary_file $grid_file | tail -1`
sum=`expr $sum + $runtime_5`

echo "The average running time for 5 runs: " 
echo $((sum/5))


