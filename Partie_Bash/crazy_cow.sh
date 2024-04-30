#!/bin/bash
n=$1
clear
cowsay "Avec E = mc^2 on a..."
sleep 2 
clear 
cowsay "$1 * (299 792 458)^2 = ..."
sleep 2
clear
cowsay -e 00 $(($1 * (299792458 ** 2))) J