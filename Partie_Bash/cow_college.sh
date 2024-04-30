#!/bin/bash
n=$1
s1=0
s2=1
clear
while [ $s2 -lt $n ]
do  
    cowsay "$s1 "
    sleep 1
    clear
    s2=$(expr $s2 + $s1)
    s1=$(expr $s2 - $s1)
done
cowsay -T U "$s1 "
