#include<stdio.h>

#include"tic_tac_toe_2077_deluxe_edition_wykonawcze.h"
#include"tic_tac_toe_2077_deluxe_edition_funkcjonalne.h"

int negmax(struct pole* p, int glebokosc, int alfa, int beta)
{
    int v;
    int z;
    
    if(!glebokosc)
    {
        return sprawdzbot(*p);
    }
    int ocenawezla = -1000;
    for(struct listaruchow* lr = dostepneruchy(p), *ptr = lr; lr; lr = lr->nast, free(ptr), ptr = lr)
    {
        // lr->x = x;
        // lr->y = y;
        struct pole dziecko = graj(*p);
        int nowaocena = -negmax(&dziecko, glebokosc-1, -beta, -alfa);
        if(nowaocena > ocenawezla)
        {
            ocenawezla = nowaocena;
            lr->x = v;
            lr->y = z;
        }
        if(ocenawezla > alfa)
        alfa = ocenawezla;
        if(alfa > beta)
        break;
    }
    //printf("%d\n", ocenawezla);
    //printf("%d %d", x, y);
    
    p->plansza[v][z] = 'O';

    return ocenawezla;

}


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
        //system("clear");
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

        //system("clear");
        wypisz(p);
        p.czymgrasz = 'O';
        //printf("Ruch O\n\n");
        // p = interfejs(p);
        // p = graj(p);
            int chuj = 5;
            int max = 1000;
            int min = -1000;
            int u = negmax(&p, chuj , max, min);
            printf("%d\n", u);

            if(p.wygrana == 1)
            {
                goto koniecO;
            }
            // else if(p.koniec == 1)
            // {
            //     return 0;
            // }
            // else;
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