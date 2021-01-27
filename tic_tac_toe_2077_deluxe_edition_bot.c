#include <stdio.h>
#include <string.h>

#include "tic_tac_toe_2077_deluxe_edition_wykonawcze.h"
#include "tic_tac_toe_2077_deluxe_edition_funkcjonalne.h"




int main(int argc, char **argv)
{
    int q;
    system("clear");
    printf("INSTRUKCJA:\n\nSkładnia współrzędnych - K W\ncommands - wypisuje dostępne komendy\nmoves - wypisuje dostępne ruchy\nexit - kończy grę\n\n");
    printf("\nWybierz 1 żeby grać z botem\nWybierz 2 żeby grać gracz vs gracz\n");
    scanf("%d", &q);
    start: system("clear");
    struct pole p = zeruj();
    p.wygrana = 0;
    p.czymgrasz = 'X';
    int v = -10000;
    p.pozostale_ruchy = wys*szer;
    struct listaruchow lr;
    lr.koniec = 0;
    for(int i=1; i<(wys*szer)*2; i++)
    {
        system("clear");
        wypisz(p);
        printf("Ruch X\n\n");
        lr = interfejs(p);
        if(lr.koniec == 1)
        {
            return 0;
        }

        p = graj(p, lr);
        
        if(p.wygrana == 1000)
        {
            goto koniecX;
        }
        else if(p.pozostale_ruchy == 0)
        {
            goto remis;
        }
        else;
        
        system("clear");
        wypisz(p);
        if(q == 1)
        {
            struct listaruchow *najlepszy = najlepszy_ruch(&p, 4, -10000, 10000);
            p = graj(p, *najlepszy);
        }
        else
        {
            printf("Ruch O\n");
            lr = interfejs(p);
            if(lr.koniec == 1)
            {
                return 0;
            }
            p = graj(p, lr);
        }
        
        if(p.wygrana == 1000)
        {
            goto koniecO;
        }
        if(p.pozostale_ruchy == 0)
        {
            goto remis;
        }
        else;
    }
            
            

            

    koniecX: system("clear");
    wypisz(p);
    printf("Gratulacje! Wygrywasz X!\n\n");
    if(ponow() == 1)
    {
        goto start;
    }
    else
    return 0;

    koniecO: system("clear");
    wypisz(p);
    printf("Gratulacje! Wygrywasz O!\n\n");
    if(ponow() == 1)
    {
        goto start;
    }
    else
    return 0;

    remis: system("clear");
    wypisz(p);
    printf("No niestety mamy remis :(\n\n");
    if(ponow() == 1)
    {
        goto start;
    }
    else
    return 0;
}