#!/bin/bash
clear
for i in $(seq 1 10)
do 
    if [ $i -eq 10 ]
    then    
        cowsay -T U $i 
    else 
        cowsay $i
        sleep 1
        clear
    fi
done 
