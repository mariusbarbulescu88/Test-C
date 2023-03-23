#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void afisareJoc(char* arrayJoc, int nrCaractere);
void convUpper(char* litera);
int aiCastigat(char* tablaJoc, int lungimeCuvant);
void checkLitera(char* literaJucator,char* cuvantAles, char*tablaJoc, int lungimeCuvant);

int vieti = 6;
int flag = 0;
int checkWin = 0;
int winCondition = 0;

int main(){
    srand(time(0)); // seed random

    char literaJucator;
    char cuvantAles[15];
    char tablaJoc[15];

    char listaCuvinte[4][15] = {
        "FERICIRE",
        "ARDUINO",
        "PROGRAMARE",
        "PORTOCALE"
    };

    strcpy(cuvantAles, listaCuvinte[rand()%4] );
    int lungimeCuvant = strlen(cuvantAles);

    for(int i=0; i<=lungimeCuvant; i++) {
        if(i == 0) {                        //prima litera
            tablaJoc[i] = cuvantAles[i];
        } else if(i == lungimeCuvant-1) {   // penultima litera
            tablaJoc[i] = cuvantAles[i];
        } else if(i == lungimeCuvant) {     // incheierea corecta de string
            tablaJoc[i] = '\0';
        } else {
            tablaJoc[i] = '_';
        }
    }

    do {

        // partea de afisare o implementam in functie
        afisareJoc(tablaJoc, lungimeCuvant);


        printf("\n");
        printf("Ghiceste o litera: ");
        scanf("%c", &literaJucator);
        fflush(stdin);

        //functie de convertire litera mare la litera mica
        convUpper(&literaJucator);
checkLitera(&literaJucator, cuvantAles, tablaJoc, lungimeCuvant);

        system("CLS"); // sterge ce e pe ecran

    } while( (vieti>0) && aiCastigat(tablaJoc, lungimeCuvant) );

    afisareJoc(tablaJoc, lungimeCuvant);


    return 0;
}

int aiCastigat(char* tablaJoc, int lungimeCuvant) {
        checkWin = 0;
        for(int i=0; i<=lungimeCuvant; i++) {
            if(*(tablaJoc + i) == '_'){  // AICI AM SCHIMBAT
                checkWin=1;
            }
        }
        if(checkWin == 0) {
           return 0;
        }
        return 1;
}

void checkLitera(char* literaJucator,char* cuvantAles, char*tablaJoc, int lungimeCuvant) {

int flag = 0;
        for(int i=0; i<=lungimeCuvant; i++) {
            if(*literaJucator == *(cuvantAles+i) ){
                *(tablaJoc+i)= *(cuvantAles+i);
                flag = 1; // daca am ghicit o litera il setam ca 1
            }
        }

        if(flag == 0) {
            vieti--;
        }
}

void convUpper(char* litera) {
    if(*litera >= 97 && *litera <= 122) {
        *litera -= 32;
    }
}
void afisareJoc(char* arrayJoc, int nrCaractere) {

    printf("Ai %d vieti! \n\n", vieti);

    printf(" |-----|      \n");
    switch(vieti) {
        case 6:
            printf(" |            \n");
            printf(" |            \n");
            printf(" |            \n");
            break;
        case 5:
            printf(" |     O      \n");
            printf(" |            \n");
            printf(" |            \n");
            break;
        case 4:
            printf(" |     O      \n");
            printf(" |     |      \n");
            printf(" |            \n");
            break;
        case 3:
            printf(" |     O      \n");
            printf(" |    /|      \n");
            printf(" |            \n");
            break;
        case 2:
            printf(" |     O      \n");
            printf(" |    /|\\    \n");
            printf(" |            \n");
            break;
        case 1:
            printf(" |     O      \n");
            printf(" |    /|\\    \n");
            printf(" |    /       \n");
            break;
        case 0:
            printf(" |     O      \n");
            printf(" |    /|\\    \n");
            printf(" |    / \\    \n");
            break;
        default:
            printf(" |            \n");
            printf(" |            \n");
            printf(" |            \n");
            break;
    }
    printf("=O=======O=|\n");

    // Afisam tabla de joc
    for(int i=0; i<=nrCaractere; i++) {
        printf("%c ", *(arrayJoc+i) );
    }
    printf("\n");

    if( !aiCastigat(arrayJoc, nrCaractere) ) {
        printf("AI CASTIGAT ! FELICITARI!");
    }
    if(vieti == 0) {
        printf("AI PIERDUT ! NU MAI AI VIETI!");
    }
} // afisareJoc()

