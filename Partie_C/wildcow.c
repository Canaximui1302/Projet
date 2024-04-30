#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//Fonctions pour rafraîchir l'écran de console et 
//pour mettre la souris à position voulue
void update(){printf("\033[H\033[J");}

void gotoxy(int x,int y){printf("\033[%d;%dH",x,y);}

//-------------------------------------------------------------------------------

void moonwalk_vache1(int i) //1ere animation de la vache 
{
    gotoxy(1, i);
    printf(" ^__^\n");
    gotoxy(2, i);
    printf(" (==)\\_______\n");
    gotoxy(3, i);
    printf(" (__)\\       )\\/\\\n");
    gotoxy(4, i);
    printf("     /|----w |\n");
    gotoxy(5, i);
    printf("     \\|     \\|\n");
    
}

void moonwalk_vache2(int i) //2eme animation de la vache 
{
    gotoxy(1, i);
    printf(" ^__^\n");
    gotoxy(2, i);
    printf(" (==)\\_______\n");
    gotoxy(3, i);
    printf(" (__)\\       )---\n");
    gotoxy(4, i);
    printf("     |/----w /\n");
    gotoxy(5, i);
    printf("     |\\     |\\\n");
    
}

void moonwalk_cow() //l'animation complète de moonwalk_cow
{
    int step = 1;
    for (int i = 1; i < 9; i++)
    {
        
        update();
        moonwalk_vache1(step);
        sleep(1);
        update();
        step += 5;
        moonwalk_vache2(step);
        sleep(1);
        update();
        step += 5;
    }
    moonwalk_vache1(step);
}

//-------------------------------------------------------------------------------

void moonwalk_mvache1(int l, int c, int num) //1ere animation de mutiple vaches
{
    gotoxy(l, c);
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
    gotoxy(l+1, c);
    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf(" (==)\\_______      \n");
            break;
        }
        else
            printf(" (==)\\_______      ");   //deuxieme ligne
    }
    gotoxy(l+2, c);
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
    gotoxy(l+3, c);
    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf("     /|----w |\n");
            break;
        }
        else
            printf("     /|----w |     "); //quatrieme ligne
    }
    gotoxy(l+4, c);
    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf("     \\|     \\|\n");
            break;
        }
        else
            printf("     \\|     \\|     ");         //cinquieme ligne
    }
}

//-----------------------------------------------------------------------------------------
void moonwalk_mvache2(int l, int c, int num) //2eme animation de mutiple vaches
{
    gotoxy(l, c);
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
    gotoxy(l+1, c);
    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf(" (==)\\_______      \n");
            break;
        }
        else
            printf(" (==)\\_______      ");   //deuxieme ligne
    }
    gotoxy(l+2, c);
    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf(" (__)\\       )---\n");
            break;
        }
        else
            printf(" (__)\\       )---  ");       //troisieme ligne
    }
    gotoxy(l+3, c);
    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf("     |/----w /\n");
            break;
        }
        else
            printf("     |/----w /     "); //quatrieme ligne
    }
    gotoxy(l+4, c);
    for (int i = 1; i <= num; i++)
    {
        if (i == num)
        {
            printf("     |\\     |\\\n");
            break;
        }
        else
            printf("     |\\     |\\     ");          //cinquieme ligne
    }
}
//-----------------------------------------------------------------------------------------

void moonwalk_troupeau1(int c, int num) //1ere animation du troupeau
{

    if (num <= 5)
        moonwalk_mvache1(1, c, num);
    else 
    {
        int l = 1;
        for (int j = 1; j <= num / 5; j++){
            moonwalk_mvache1(l, c, 5);
            l += 5;
            gotoxy(l, c);}
        moonwalk_mvache1(l, c, num % 5);
        }
    }
    
void moonwalk_troupeau2(int c, int num) //2eme animation du troupeau
{

    if (num <= 5)
        moonwalk_mvache2(1, c, num);
    else 
    {
        int l = 1;
        for (int j = 1; j <= num / 5; j++){
            moonwalk_mvache2(l, c, 5);
            l += 5;
            gotoxy(l, c);}
        moonwalk_mvache2(l, c, num % 5);
        }
    }

//-----------------------------------------------------------------------------------------
 
void moonwalk_troupeau(int n) //l'animation complète de moonwalk_troupeau
{
    int step = 1;
    for (int i = 1; i < 7; i++)
    {
        
        update();
        moonwalk_troupeau1(step, n);
        sleep(1);
        update();
        step += 5;
        moonwalk_troupeau2(step, n);
        sleep(1);
        update();
        step += 5;
    }
    moonwalk_troupeau1(step, n);
}

//----------------------------------------------------------------------------------------

int main(int argc, char *argv[]){
    if (argc == 1)
        moonwalk_cow();
    else if (argc == 2)
        {int n = atoi(argv[1]);
        moonwalk_troupeau(n);}
    return 0;
}