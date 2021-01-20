#include "wykonawcze_test.h"

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


void main ()
{
    struct pole test;

    test.plansza[1][1] = 'X';
    test.plansza[1][2] = 'X';
    test.plansza[1][3] = 'X';
    test.plansza[2][1] = ' ';
    test.plansza[2][2] = 'O';
    test.plansza[2][3] = ' ';
    test.plansza[3][1] = ' ';
    test.plansza[3][2] = ' ';
    test.plansza[3][3] = 'O';

    wypisz(test);

    int x;

    printf("%d\n",sprawdz(test, 1 , 1) );

}