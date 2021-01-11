#include "tic_tac_toe_2077_deluxe_edition_wykonawcze.h"


int sprawdz_poziom(struct pole p,int a, int b)
{
    int i = 1;
    int ileX = 0;
    int ileO = 0;
    for(i = 1; i<=szer; i++)
    {
        if(p.plansza[b][i] == 'X' || p.plansza[b][i] == 'O')
        {
            if(p.plansza[b][i] == 'X')
            {
                ileX++;
                ileO = 0;
                if(ileX == wygrywa)
                {
                    return 1;
                }
                else;
            }
            else
            {
                ileO++;
                ileX = 0;
                if(ileO == wygrywa)
                {
                    return 1;
                }
                else;
            }
        }
        else
        {
            ileX = 0;
            ileO = 0;
        }
        
    }
    return 0;
}

int sprawdz_pion(struct pole p,int a, int b)
{
    int i = 1;
    int ileX = 0;
    int ileO = 0;
    for(i = 1; i<=wys; i++)
    {
        if(p.plansza[i][a] == 'X' || p.plansza[i][a] == 'O')
        {
            if(p.plansza[i][a] == 'X')
            {
                ileX++;
                ileO = 0;
                if(ileX == wygrywa)
                {
                    return 1;
                }
                else;
            }
            else
            {
                ileO++;
                ileX = 0;
                if(ileO == wygrywa)
                {
                    return 1;
                }
                else;
            }
        }
        else
        {
            ileX = 0;
            ileO = 0;
        }
    }
    return 0;
}

int sprawdz_ukos1(struct pole p,int a, int b)
{
    int i = 0;
    int ileX = 0;
    int ileO = 0;

        while((a-(b-1)+i)<=szer && (1+i)<=wys)
        {
            if(p.plansza[1+i][a-(b-1)+i] == 'X' || p.plansza[1+i][a-(b-1)+i] == 'O')
            {
                if(p.plansza[1+i][a-(b-1)+i] == 'X')
                {
                    ileX++;
                    ileO = 0;
                    if(ileX == wygrywa)
                    {
                        return 1;
                    }
                    else;
                }
                else
                {
                    ileO++;
                    ileX = 0;
                    if(ileO == wygrywa)
                    {
                        return 1;
                    }
                    else;
                }      
            }
            else
            {
                ileX = 0;
                ileO = 0;
            }
            i++;
        }
    return 0;
}

int sprawdz_ukos2(struct pole p, int a, int b)
{
    int i = 0;
    int ileX = 0;
    int ileO = 0;
    
    while((a+(b-1)-i)>=1 && (1+i)<=wys)
    {
        if(p.plansza[1+i][a+(b-1)-i] == 'X' || p.plansza[i+1][a+(b-1)-i] == 'O')
        {
            if(p.plansza[1+i][a+(b-1)-i] == 'X')
            {
                ileX++;
                ileO = 0;
                if(ileX == wygrywa)
                {
                    return 1;
                }
                else;
            }
            else
            {
                ileO++;
                ileX = 0;
                if(ileO == wygrywa)
                {
                    return 1;
                }
                else;
            }    
        }
        else
        {
            ileX = 0;
            ileO = 0;
        }   
        i++;
    }
    return 0;
}

int sprawdz(struct pole p, int a, int b)
{
    int x, y, z1, z2 = 0;
    x = sprawdz_poziom(p, a, b);
    y = sprawdz_pion(p, a, b);
    z1 = sprawdz_ukos1(p, a, b);
    z2 = sprawdz_ukos2(p, a, b);
    if(x==1 || y==1 || z1==1 || z2==1)
    {
        return 1;
    }
    else return 0;
}

void dostepneruchy(struct pole p)
{
    int i, j;
    printf("Lista dostępnych ruchów:\n");
    for(i = 1; i<=wys; i++)
    {
        for(j = 1; j<=szer; j++)
        {    
            if(p.ruch_zajety[i][j] == 0)
            {
                printf("%d %d   ", j, i);
            }
            else;
        }
    }
    printf("\n\n");
}

struct pole grajX(struct pole p)
{
    int a, b;
    char i[6], j[6];
    float c, d;
    system("clear");
    wypisz(p);
    X: printf("Gdzie chcesz postawić X?\n");
    scanf("%s", i);
    if(strcmp(i, "exit") == 0)
    {
        p.koniec = 1;
    }
    else if(strcmp(i, "moves") == 0)
    {
        dostepneruchy(p);
        goto X;
    }
    else if(strcmp(i, "commands") == 0)
    {
        komendy();
        goto X;
    }
    else
    {
        scanf("%s", j);
        c = atof(i);
        d = atof(j);
        a = c;
        b = d;
        if(p.ruch_zajety[b][a] == 1 || a>szer || b>wys || a == 0 || b == 0)
        {
            printf("RUCH NIEDOZWOLONY!\n\n");
            goto X;
        }
        else
        {
            p.plansza[b][a] = 'X';
            p.ruch_zajety[b][a] = 1;
            p.pozostale_ruchy=p.pozostale_ruchy-1;
            p.wygrana = 0;
            p.wygrana = sprawdz(p, a, b);

        }
    }
    return p;
}

struct pole grajO(struct pole p)
{
    int a, b;
    char i[6], j[6];
    float c, d;
    system("clear");
    wypisz(p);
    O: printf("Gdzie chcesz postawić O?\n");
    scanf("%s", i);
    if(strcmp(i, "exit") == 0)
    {
        p.koniec = 1;
    }
    else if(strcmp(i, "moves") == 0)
    {
        dostepneruchy(p);
        goto O;
    }
    else
    {
        scanf("%s", j);
        c = atof(i);
        d = atof(j);
        a = c;
        b = d;
        if(p.ruch_zajety[b][a] == 1 || a>szer || b>wys || a == 0 || b == 0)
        {
            printf("RUCH NIEDOZWOLONY!\n\n");
            goto O;
        }
        else
        {
            p.plansza[b][a] = 'O';
            p.ruch_zajety[b][a] = 1;
            p.pozostale_ruchy=p.pozostale_ruchy-1;
            p.wygrana = 0;
            p.wygrana = sprawdz(p, a, b);
        }
    }
    return p;
}

int ponow(void)
{
    char a[2];
    printf("Czy chcesz zagrać jeszcze raz? <T/N>\n");
    scanf("%s", a);
    if(strcmp("t", a) == 0 || strcmp("T", a) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}