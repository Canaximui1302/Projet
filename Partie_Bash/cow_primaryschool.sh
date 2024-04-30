#!/bin/bash
n=$1
clear
for i in $(seq 1 $n)
do 
    if [ $i -eq $n ]
    then 
        cowsay -T U $i
    else 
        cowsay $i
        sleep 1
        clear
    fi
done 