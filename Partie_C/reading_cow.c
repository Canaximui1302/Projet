#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

//---------------------------------------------------------------------------------------

//Fonctions pour rafraîchir l'écran de console et 
//pour mettre la souris à position voulue
void update(){printf("\033[H\033[J");}

void gotoxy(int x,int y){printf("\033[%d;%dH",x,y);}

//----------------------------------------------------------------------------------------

//Fonction pour afficher la vache 
void reading_vache(int x, int y, char c)
{
    gotoxy(x, y);
    printf(" \\   ^__^               \n");
    gotoxy(x+1, y);
    printf("  \\  (oo)\\_______      \n");
    gotoxy(x+2, y);
    printf("     (__)\\       )\\/\\\n");
    gotoxy(x+3, y);
    printf("      %c  ||----w |     \n", c);
    gotoxy(x+4, y);
    printf("         ||     ||    \n");
}

void read_file (char nom[]){
    FILE *f, *des;
    f = fopen(nom, "r");
    des = stdout;
    char c;
    int position = 3;
    fscanf(f, "%c", &c);
    update();
    gotoxy(1, 1);
    printf(" _\n<\n -\n");
    reading_vache(4, position, ' ');
    while (!feof(f))
    {
        //Les codes suivants sont pour but d'afficher le bulle de text 
        //contenant les mots dans le fichier 
        sleep(1);
        gotoxy(1, position);
        printf("_");
        gotoxy(2, position);
        printf("%c", c);
        gotoxy(3, position);
        printf("-");
        fscanf(f, "%c", &c);
        position++;
        gotoxy(1, position);
        printf("_");
        gotoxy(2, position);
        printf(" >");
        gotoxy(3, position);
        printf("-\n");
        reading_vache(4, position, c);
        
    }
    reading_vache(4, position, ' ');
}



int main(int argc, char *argv[]){
    if (argc <= 1)
        exit(1);
    read_file(argv[1]);

    return 0;
}