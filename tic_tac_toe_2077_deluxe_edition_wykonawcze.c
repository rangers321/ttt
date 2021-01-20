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

int sprawdzbotpoziom(struct pole p)
{
    int ileO = 0;
    int suma = 0;
    int ileX = 0;
    int czyX = 0;

    for(int i = 1; i<=szer; i++)
    {
        for(int j = 1; j<=wys; j++)
        {
            if(p.plansza[i][j] == 'O')
            {
                ileX = 0;
                ileO++;
                if(ileO == wygrywa)
                {
                    return 1000;
                }
            }
            else if(p.plansza[i][j] == 'X')
            {
                ileO = 0;
                czyX = 1;
                ileX++;
                if(ileX == wygrywa)
                {
                    return -1000;
                }
                //break;
            }
        } 
        if(czyX != 0)
        {
            ileO = 0;
            ileX = 0;
        }
        else
        {
            suma += ileO;
            ileO = 0;
            ileX = 0;
        }
    }

    return suma;
}

int sprawdzbotpion(struct pole p)
{
    int ileO = 0;
    int suma = 0;
    int ileX = 0;
    int czyX = 0;

    for(int i = 1; i<=szer; i++)
    {
        for(int j = 1; j<=wys; j++)
        {
            if(p.plansza[j][i] == 'O')
            {
                ileX = 0;
                ileO++;
                if(ileO == wygrywa)
                {
                    return 1000;
                }
            }
            else if(p.plansza[j][i] == 'X')
            {
                ileO = 0;
                ileX++;
                int czyX = 1;
                if(ileX == wygrywa)
                {
                    return -1000;
                }
                // break;
            }
        } 
        if(czyX != 0)
        {
            ileO = 0;
            ileX = 0;
        }
        else
        {
            suma += ileO;
            ileO = 0;
            ileX = 0;
        }
    }

    return suma;
}

int sprawdzbotukos1(struct pole p)
{
    int ileO = 0;
    int ileX = 0;
    int czyX = 0;

    for(int i = 1; i<=wys; i++)
    {
        if(p.plansza[i][i] == 'O')
        {
            ileX = 0;
            ileO++;
            if(ileO == wygrywa)
            {
                return 1000;
            }
        }
        else if(p.plansza[i][i] == 'X')
        {
            ileO = 0;
            ileX++;
            czyX = 1;
            if(ileX == wygrywa)
            {
                return -1000;
            }
            // break;
        }
    }
    if(czyX != 0)
    {
        return 0;
    }
    else
    return ileO;
}

int sprawdzbotukos2(struct pole p)
{
    int ileO = 0;
    int ileX = 0;
    int czyX = 0;

    for(int i = 1; i<=wys; i++)
    {
        if(p.plansza[(wys+1)-i][i] == 'O')
        {
            ileX = 0;
            ileO++;
            if(ileO == wygrywa)
            {
                return 1000;
            }
        }
        else if(p.plansza[(wys+1)-i][i] == 'X')
        {
            ileO = 0;
            ileX++;
            czyX = 1;
            if(ileX == wygrywa)
            {
                return -1000;
            }
            // break;
        }
    }
    if(czyX != 0)
    {
        return 0;
    }
    else
    return ileO;
}

int sprawdzbot(struct pole p)
{
    int suma = sprawdzbotpoziom(p) + sprawdzbotpion(p) + sprawdzbotukos1(p) + sprawdzbotukos2(p);

    return suma;
}

struct listaruchow* dostepneruchy(struct pole* stare)
{
    struct pole* p = stare;
    struct listaruchow* lr;
    int i, j;
    int k = 1;
    for(i = 1; i<=wys; i++)
    {
        for(j = 1; j<=szer; j++)
        {    
            if(p->ruch_zajety[i][j] == 0)
            {
                lr->ruchy[i][j] = 1;
                lr->ruch1[k] = i;
                lr->ruch2[k] = j;
                k++;
            }
            else
            {
                lr->ruchy[i][j] = 0;
            }
        }
    }

    return lr;
}

void wypiszdostepneruchy(struct pole p)
{
    int i, j;
    for(i = 1; i<=wys; i++)
    {
        for(j = 1; j<=szer; j++)
        {    
            if(p.ruch_zajety[i][j] == 0)
            printf("%d %d  ", j, i);
        }
    }
    printf("\n");
}

struct pole interfejs(struct pole p)
{
    int a, b;
    char i[10], j[6];
    float c, d;
    ponow:
    scanf("%s", i);   
    if(strcmp(i, "exit") == 0)
    {
        p.koniec = 1;
        return p;
    }
    else if(strcmp(i, "moves") == 0)
    {
        wypiszdostepneruchy(p);
        goto ponow;
    }
    else if(strcmp(i, "commands") == 0)
    {
        komendy();
        goto ponow;
    }
    
    scanf("%s", j);
    p.szerokosc = atoi(i);
    p.wysokosc = atoi(j);

    if(p.ruch_zajety[p.wysokosc][p.szerokosc] == 1 || p.szerokosc>szer || p.wysokosc>wys || p.szerokosc == 0 || p.wysokosc == 0)
    {
        printf("RUCH NIEDOZWOLONY!\n\n");
        goto ponow;
    }

    return p;
}

struct pole graj(struct pole stare)
{
    struct pole p = stare;
    
    if(p.czymgrasz == 'X')
        goto X;
    else if(p.czymgrasz == 'O')
        goto O;
    
    
    X:
    p.plansza[p.wysokosc][p.szerokosc] = 'X';
    p.ruch_zajety[p.wysokosc][p.szerokosc] = 1;
    p.pozostale_ruchy=p.pozostale_ruchy-1;
    p.wygrana = 0;
    p.wygrana = sprawdz(p, p.szerokosc, p.wysokosc);
    
    return p;

    O:
    p.plansza[p.wysokosc][p.szerokosc] = 'O';
    p.ruch_zajety[p.wysokosc][p.szerokosc] = 1;
    p.pozostale_ruchy=p.pozostale_ruchy-1;
    p.wygrana = 0;
    p.wygrana = sprawdz(p, p.szerokosc, p.wysokosc);

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