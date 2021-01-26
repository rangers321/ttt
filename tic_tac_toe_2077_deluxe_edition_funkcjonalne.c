#include "tic_tac_toe_2077_deluxe_edition_funkcjonalne.h"

void wypisz(struct pole p)
{
 
    for(int i = 0; i < szer; i++)
    printf("%4d", i+1);
    printf("\n");

    for(int i = 0; i< wys; i++)
    {
        printf(" ");
        for(int i = 0; i<wys; i++)
            printf("+---");
        printf("+\n");
        printf("%d|", i+1);
        for(int j=0; j<szer; j++)
            printf(" %1c |", p.plansza[i][j]);
        printf("\n");
    }
    printf(" ");
    for(int i=0; i<szer; i++)
    {
        printf("+---");
    }
    printf("+\n");
}

struct pole zeruj(void)
{
    struct pole wyzerowana;    
    
    for(int i = 0; i< wys; i++)
    {
        for(int j = 0; j<szer; j++)
        {
            wyzerowana.plansza[i][j] = ' ';
            wyzerowana.ruch_zajety[i][j] = 0;
        }
    }
    return wyzerowana;
}

void komendy(void)
{
    printf("Lista dostępnych komend:\n\ncommands - wypisuje dostępne komendy\nmoves - wypisuje dostępne ruchy\nexit - kończy grę\n\n");
}