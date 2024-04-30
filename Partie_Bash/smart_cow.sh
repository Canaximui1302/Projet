#!/bin/bash
clear
if [ $# -eq 0 ]
then
    exit 0
else 
    if [ $(($1)) -ge 10 ]
    then 
        cowsay -e $(($1)) $1
    #si le résultat est une seule chiffre, on va ajouter un espace pour formatter les yeux
    else 
        cowsay -e "$(($1)) " $1 
    fi
fi