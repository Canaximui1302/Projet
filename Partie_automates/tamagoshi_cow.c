#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void update(){printf("\033[H\033[J");}

void gotoxy(int x,int y){printf("\033[%d;%dH",x,y);}

//----------------------------------------------------------------

//etat byebyelife (0)
void cow_die(){
    gotoxy(4, 8);
    printf("     \\\n");
    gotoxy(5, 8);
    printf("      \\       //     //      \n");
    gotoxy(6, 8);
    printf("       \\      \\\\----M \\      \n");
    gotoxy(7, 8);
    printf("          (--)/_______)      \n");
    gotoxy(8, 8);
    printf("          (xx)/        \\/\\ \n");
    gotoxy(9, 8);
    printf("          v--v               \n");
}

//etat lifesucks (1)
void cow_sad(){
    gotoxy(4, 8);
    printf("      \\    __               \n");
    gotoxy(5, 8);
    printf("       \\ <(@@)>_______      \n");
    gotoxy(6, 8);
    printf("          (**)\\       )\\   \n");
    gotoxy(7, 8);
    printf("           U  /\\----w \\ \\ \n");
    gotoxy(8, 8);
    printf("             /  \\   /  \\   \n");
}

//etat liferocks (2)
void cow_normal(){
    gotoxy(4, 8);
    printf("      \\   ^__^               \n");
    gotoxy(5, 8);
    printf("       \\  (==)\\_______      \n");
    gotoxy(6, 8);
    printf("          (__)\\       )\\/\\\n");
    gotoxy(7, 8);
    printf("              ||----w |     \n");
    gotoxy(8, 8);
    printf("              ||     ||    \n");
}

void affiche_vache(int etat){
    if (etat == 0)
        cow_die();
    else if (etat == 1)
        cow_sad();
    else if (etat == 2)
        cow_normal();
}

//-----------------------------------------------------

//les variables globales
int stock = 5;
int fitness = 5; //crop et fitness sont comprises entre 0 et 10

void stock_update(int lunchfood){
    srand(time(NULL));
    int crop = (rand() % 10) % 7 - 3; //variable aléatoire crop entre -3 et 3
    stock = stock + crop - lunchfood;
    if (stock > 10)
        stock = 10;
    else if (stock < 0)
        stock = 0;
}

void fitness_update(int lunchfood){
    srand(time(NULL));
    int digestion = rand() % 4; //variable aléatoire digestion entre -3 et 0
    fitness = fitness + (lunchfood - digestion);
    if (fitness > 10)
        fitness = 10;
    else if (fitness < 0)
        fitness = 0;
}

//---------------------------------------------------------

//les paroles de la vache
char parole[50];
void parole_update(){
    srand(time(NULL));
    int n = rand() % 5; //génere un entier aléatoire entre 0 et 5 pour choisir les paroles
    if (fitness >= 4 && fitness <= 6){ // parole pour l'état liferocks
        if (n == 0){
            strcpy(parole, "        Rock'n roll babe!!       ");}
        else if (n == 1){
            strcpy(parole, "         LA VIE EN ROSE!         ");}
        else if (n == 2){
            strcpy(parole, "      Rien n'est impossible!     ");}
        else if (n == 3){
            strcpy(parole, "    Reste inspiré. Reste fou!    ");}
        else if (n == 4){
            strcpy(parole, "Quoi que tu fasses, fais le bien!");}}
    else{
        if (n == 0){
            strcpy(parole, "     I don't feel good, bro!     ");}
        else if (n == 1){
            strcpy(parole, "     Life is meaningless :(      ");}
        else if (n == 2){
            strcpy(parole, "    La vie n'est pas en rose!    ");}
        else if (n == 3){
            strcpy(parole, "L'avenir de la vie c'est la mort!");}
        else if (n == 4){
            strcpy(parole, "Si on est pessimiste, on est fini");}
    } 
        
}

//-----------------------------------------------------

int main(){
    int etat = 2;
    int day = 1;
    int lunchfood; 
    strcpy(parole, " Yo what's up dude, I'm lil'cow! ");
    while (etat != 0) // initialisation de jeu
    {
        update();
        printf(" ___________________________________\n");
        printf("< %s >\n", parole);
        printf(" -----------------------------------\n");
        affiche_vache(etat);
        printf("\n");
        printf("/--------------------------\\\n");
        printf("| Days: %d        Stock: %d  |\n", day, stock);
        printf("\\--------------------------/\n");
        printf("Feed the cow: ");
        scanf("%d", &lunchfood);

        //Une boucle while pour vérifier si la quantité de lunchfood est valide

        while (lunchfood > stock || lunchfood < 0)
        {
            if (lunchfood > stock)
                printf("not enough food!");
            else
                printf("invalid amount of food!");
            scanf("%d", &lunchfood);
        }

            //mettre à jour les variables globales

        fitness_update(lunchfood);
        stock_update(lunchfood);

            //mettre à jour l'état de la vache

        if (fitness == 0 || fitness == 10)
            etat = 0;
        else {
            if (fitness >= 4 && fitness <= 6)
                etat = 2;
            else
                etat = 1;
            day++;      //incrémenter le nombre du jour si la vache survive
            parole_update();    //mettre à jour les parole de la vache
        }
    }
    update();      
    strcpy(parole, "         See ya next time!       ");
    printf(" ___________________________________\n");
    printf("< %s >\n", parole);
    printf(" -----------------------------------\n");
    affiche_vache(0);
    printf("\n");
    printf("/--------------------------\\\n");
    //les conditions pour formater l'affichage du résultat de joueur
    if (day >= 10)
        printf("|       Days lived: %d     |\n", day);
    else
        printf("|       Days lived: %d      |\n", day); 
    printf("\\--------------------------/\n");

    return 0;
}