#include"tic_tac_toe_2077_deluxe_edition_wykonawcze.h"
#include"tic_tac_toe_2077_deluxe_edition_funkcjonalne.h"


int main(int argc, char **argv)
{
    char q[1];
    system("clear");
    printf("INSTRUKCJA:\n\nSkładnia współrzędnych - K W\ncommands - wypisuje dostępne komendy\nmoves - wypisuje dostępne ruchy\nexit - kończy grę\n\n");
    scanf("%c", q);
    start: system("clear");
    struct pole p = zeruj();
    p.wygrana = 0;
    p.koniec = 0;
    p.pozostale_ruchy = wys*szer;
    for(int i=1; i<(wys*szer)*2; i++)
    {
        system("clear");
        wypisz(p);
        p.czymgrasz = 'X';
        printf("Ruch X\n\n");
        p = interfejs(p);
        p = graj(p); 
        
        if(p.wygrana == 1)
            {
                goto koniecX;
            }
            else if(p.koniec == 1)
            {
                return 0;
            }
            else if(p.pozostale_ruchy == 0)
            {
                goto remis;
            }
            else;   

        system("clear");
        wypisz(p);
        p.czymgrasz = 'O';
        printf("Ruch O\n\n");
        p = interfejs(p);
        p = graj(p);

            if(p.wygrana == 1)
            {
                goto koniecO;
            }
            else if(p.koniec == 1)
            {
                return 0;
            }
            else;
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