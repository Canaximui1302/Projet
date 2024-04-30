#!/bin/bash
n=$1
clear
for i in $(seq 1 $n)
do 
    if [ $i -eq $n ]
    then 
        cowsay -T U $(($n**2))
    else 
        cowsay $(($i**2))
        sleep 1
        clear
    fi
done
