#!/bin/bash
n=$1
clear
if [ $n -ge 2 ]
then
    cowsay 2
    sleep 1
    clear
fi
for i in $(seq 1 $n)
do 
    for j in $(seq 2 $(expr $i - 1))
    do 
        if [ $(expr $i % $j) -eq 0 ]
        then 
            break
        fi
        if [ $j -eq $(expr $i - 1) ]
        then 
            cowsay $i
            sleep 1
            clear
        fi
    done
done
