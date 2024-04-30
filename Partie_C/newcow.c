
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Affichage de la vache
void affiche_vache(char eyes[], char tongue[])
{
    printf(" ^__^\n");
    printf(" (%s)\\_______\n", eyes);
    printf(" (__)\\       )\\/\\\n");
    printf("  %s  ||----w |\n", tongue);
    printf("     ||     ||\n");
    
}

//----------------------------------------------------------

//Affichage de plusieurs vaches sur une ligne (max 5 vaches)

void affiche_mvache(int num, char eyes[], char tongue[])
{
    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf(" ^__^               \n");
            break;
        }
        else
            printf(" ^__^              ");          //premier ligne
    }

    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf(" (%s)\\_______      \n", eyes);
            break;
        }
        else
            printf(" (%s)\\_______      ", eyes);   //deuxieme ligne
    }

    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf(" (__)\\       )\\/\\\n");
            break;
        }
        else
            printf(" (__)\\       )\\/\\  ");       //troisieme ligne
    }

    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf("  %s  ||----w |     \n", tongue);
            break;
        }
        else
            printf("  %s  ||----w |     ", tongue); //quatrieme ligne
    }

    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf("     ||     ||    \n");
            break;
        }
        else
            printf("     ||     ||     " );         //cinquieme ligne
    }
}


//Affichage d'un troupeau de vaches 
void affiche_troupeau(int num, char eyes[], char tongue[]) 
{
    
    if (num <=5)
        affiche_mvache(num, eyes, tongue);
    else
    {
        for (int i = 1; i <= num/5;i++)
            affiche_mvache(5,eyes, tongue);
        affiche_mvache(num % 5, eyes,tongue);
    }
}

//---------------------------------------------------------------------------------

//Fonction pour alterner les yeux et la langue de la vache
//basée sur les options originales de cowsay linux
void basic_options(int c, int *num, char * v[], char eyes[], char tongue[])
{
for (int i = 0; i < c; i++)
    {
        if (strcmp(v[i], "-b") == 0)
        {
            strcpy(eyes, "==");
            break;
        }
        else if (strcmp(v[i], "-d") == 0)
        {
            strcpy(eyes, "xx");
            strcpy(tongue, "U");

        }
        else if (strcmp(v[i], "-g") == 0)
        {
            strcpy(eyes, "$$");

        }
        else if (strcmp(v[i], "-p") == 0)
        {
            strcpy(eyes, "@@");

        }
        else if (strcmp(v[i], "-s") == 0)
        {
            strcpy(eyes, "**");
            strcpy(tongue, "U");

        }
        else if (strcmp(v[i], "-t") == 0)
        {
            strcpy(eyes, "--");

        }
        else if (strcmp(v[i], "-w") == 0)
        {
            strcpy(eyes, "OO");

        }
        else if (strcmp(v[i], "-y") == 0)
        {
            strcpy(eyes, "..");

        }
        else if (strcmp(v[i], "-e") == 0 || strcmp(v[i], "-eyes") == 0)
        {
            strcpy(eyes, "");
            strncat(eyes, v[i + 1], 2);
        }
        else if (strcmp(v[i], "-T") == 0)
        {
            strcpy(tongue, "");
            strncat(tongue, v[i + 1], 1);
        }
        else if (strcmp(v[i], "-m") == 0) //option bonus "-m" pour afficher un troupeau de vaches
        {
            *num = (atoi(v[i + 1]));
        }
    }
}
//---------------------------------------------------------------------------------------

//Fonctions pour rafraîchir l'écran de console et 
//pour mettre la souris à position voulue
void update(){printf("\033[H\033[J");}

void gotoxy(int x,int y){printf("\033[%d;%dH",x,y);}

//----------------------------------------------------------------------------------------
//MAIN  
int main(int argc, char *argv[]){
    char eyes[3] = "oo";
    char tongue[2] = " ";
    int n = 1;      //le nombre de vaches par défaut est 1
    //l'appel de cette fonction est pour changer les yeux, la langue et 
    //le nombre de vache selon les options dans la commande de l'utilisateur
    basic_options(argc, &n, argv, eyes, tongue); 
    affiche_troupeau(n, eyes, tongue);
}
