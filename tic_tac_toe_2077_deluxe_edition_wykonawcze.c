#include "tic_tac_toe_2077_deluxe_edition_wykonawcze.h"


int sprawdz_poziom(struct pole p,int a, int b)
{
    int i = 0;
    int ileX = 0;
    int ileO = 0;
    for(i = 0; i<szer; i++)
    {
        if(p.plansza[b][i] == 'X' || p.plansza[b][i] == 'O')
        {
            if(p.plansza[b][i] == 'X')
            {
                ileX++;
                ileO = 0;
                if(ileX == wygrywa)
                {
                    if(p.czymgrasz == 'X')
                    {
                        return 1000;
                    }
                    else if(p.czymgrasz == 'O')
                    {
                        return -1000;
                    }
                }
                else;
            }
            else
            {
                ileO++;
                ileX = 0;
                if(ileO == wygrywa)
                {
                    if(p.czymgrasz == 'O')
                    {
                        return 1000;
                    }
                    else if(p.czymgrasz == 'X')
                    {
                        return -1000;
                    }
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
    int i = 0;
    int ileX = 0;
    int ileO = 0;
    for(i = 0; i<wys; i++)
    {
        if(p.plansza[i][a] == 'X' || p.plansza[i][a] == 'O')
        {
            if(p.plansza[i][a] == 'X')
            {
                ileX++;
                ileO = 0;
                if(ileX == wygrywa)
                {
                    if(p.czymgrasz == 'X')
                    {
                        return 1000;
                    }
                    else if(p.czymgrasz == 'O')
                    {
                        return -1000;
                    }
                }
                else;
            }
            else
            {
                ileO++;
                ileX = 0;
                if(ileO == wygrywa)
                {
                    if(p.czymgrasz == 'O')
                    {
                        return 1000;
                    }
                    else if(p.czymgrasz == 'X')
                    {
                        return -1000;
                    }
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

        while((a-(b)+i)<szer && (i)<wys)
        {
            if(p.plansza[i][a-(b)+i] == 'X' || p.plansza[i][a-(b)+i] == 'O')
            {
                if(p.plansza[i][a-(b)+i] == 'X')
                {
                    ileX++;
                    ileO = 0;
                    if(ileX == wygrywa)
                    {
                        if(p.czymgrasz == 'X')
                        {
                            return 1000;
                        }
                        else if(p.czymgrasz == 'O')
                        {
                            return -1000;
                        }   
                    }
                    else;
                }
                else
                {
                    ileO++;
                    ileX = 0;
                    if(ileO == wygrywa)
                    {
                        if(p.czymgrasz == 'O')
                        {
                            return 1000;
                        }
                        else if(p.czymgrasz == 'X')
                        {
                            return -1000;
                        }
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
    
    while((a+(b)-i)>=0 && (i)<wys)
    {
        if(p.plansza[i][a+(b)-i] == 'X' || p.plansza[i][a+(b)-i] == 'O')
        {
            if(p.plansza[i][a+(b)-i] == 'X')
            {
                ileX++;
                ileO = 0;
                if(ileX == wygrywa)
                {
                    if(p.czymgrasz == 'X')
                    {
                        return 1000;
                    }
                    else if(p.czymgrasz == 'O')
                    {
                        return -1000;
                    }
                }
                else;
            }
            else
            {
                ileO++;
                ileX = 0;
                if(ileO == wygrywa)
                {
                    if(p.czymgrasz == 'O')
                    {
                        return 1000;
                    }
                    else if(p.czymgrasz == 'X')
                    {
                        return -1000;
                    }
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
    if(x != 0)
        return x;
    else if(y != 0)
        return y;
    else if(z1 != 0)
        return z1;
    else if(z2 != 0)
        return z2;
    else
        return 0;
}

int sprawdzbotpoziom(struct pole p)
{
    int ileO = 0;
    int suma = 0;
    int ileX = 0;

    for(int i = 0; i<szer; i++)
    {
        for(int j = 0; j<wys; j++)
        {
            if(p.plansza[i][j] == 'O')
            {
                ileX = 0;
                ileO++;
                if(ileO == wygrywa)
                {
                    if(p.czymgrasz == 'O')
                        return 1000;
                    else if(p.czymgrasz == 'X')
                        return -1000;
                    
                }
            }
            else if(p.plansza[i][j] == 'X')
            {
                ileO = 0;
                ileX++;
                if(ileX == wygrywa)
                {
                    if(p.czymgrasz == 'O')
                        return -1000;
                    else if(p.czymgrasz == 'X')
                        return 1000;
                }
            }
        } 
    }
    return 0;
}

int sprawdzbotpion(struct pole p)
{
    int ileO = 0;
    int suma = 0;
    int ileX = 0;

    for(int i = 0; i<szer; i++)
    {
        for(int j = 0; j<wys; j++)
        {
            if(p.plansza[j][i] == 'O')
            {
                ileX = 0;
                ileO++;
                if(ileO == wygrywa)
                {
                    if(p.czymgrasz == 'O')
                        return 1000;
                    else if(p.czymgrasz == 'X')
                        return -1000;
                }
            }
            else if(p.plansza[j][i] == 'X')
            {
                ileO = 0;
                ileX++;
                if(ileX == wygrywa)
                {
                    if(p.czymgrasz == 'O')
                        return -1000;
                    else if(p.czymgrasz == 'X')
                        return 1000;
                }
            }
        } 
    }

    return 0;
}

int sprawdzbotukos1(struct pole p)
{
    int ileO = 0;
    int ileX = 0;

    for(int i = 0; i<wys; i++)
    {
        if(p.plansza[i][i] == 'O')
        {
            ileX = 0;
            ileO++;
            if(ileO == wygrywa)
            {
                if(p.czymgrasz == 'O')
                    return 1000;
                else if(p.czymgrasz == 'X')
                    return -1000;
            }
        }
        else if(p.plansza[i][i] == 'X')
        {
            ileO = 0;
            ileX++;
            if(ileX == wygrywa)
            {
                if(p.czymgrasz == 'O')
                    return -1000;
                else if(p.czymgrasz == 'X')
                    return 1000;
            }
        }
    }
    return 0;
}

int sprawdzbotukos2(struct pole p)
{
    int ileO = 0;
    int ileX = 0;

    for(int i = 0; i<wys; i++)
    {
        if(p.plansza[(wys-1)-i][i] == 'O')
        {
            ileX = 0;
            ileO++;
            if(ileO == wygrywa)
            {
                if(p.czymgrasz == 'O')
                    return 1000;
                else if(p.czymgrasz == 'X')
                    return -1000;
            }
        }
        else if(p.plansza[(wys-1)-i][i] == 'X')
        {
            ileO = 0;
            ileX++;
            if(ileX == wygrywa)
            {
                if(p.czymgrasz == 'O')
                    return -1000;
                else if(p.czymgrasz == 'X')
                    return 1000;
            }
        }
    }
    
    return 0;
}

int sprawdzbot(struct pole p)
{
    int x, y, z1, z2 = 0;
    x = sprawdzbotpoziom(p);
    y = sprawdzbotpion(p);
    z1 = sprawdzbotukos1(p);
    z2 = sprawdzbotukos2(p);
    if(x != 0)
        return x;
    else if(y != 0)
        return y;
    else if(z1 != 0)
        return z1;
    else if(z2 != 0)
        return z2;
    else
        return 0;
}

struct listaruchow* dostepneruchy(struct pole* p)
{
int i,j;
  struct listaruchow *glowa = NULL;
  struct listaruchow *lista = NULL;
  struct listaruchow *r = NULL;

  for(i=0;i<wys;i++)
    for(j=0;j<szer;j++){
      if(p->ruch_zajety[i][j] == 0){
        lista = (struct listaruchow*) malloc(sizeof(struct listaruchow));
        lista->nast = NULL;

        if(glowa == NULL)
          glowa = lista;
        else{
          r = glowa;
          while(r->nast !=NULL)
            r = r->nast;
          r->nast = lista;
        }
        lista->ruch[0] = j;
        lista->ruch[1] = i;
      }
    }

  return glowa;
}

void wypiszdostepneruchy(struct pole p)
{
    int i, j;
    for(i = 0; i<wys; i++)
    {
        for(j = 0; j<szer; j++)
        {    
            if(p.ruch_zajety[i][j] == 0)
            printf("%d %d  ", j+1, i+1);
        }
    }
    printf("\n");
}

struct listaruchow interfejs(struct pole p)
{
    struct listaruchow lr;
    int a, b;
    char i[10], j[6];
    printf("Gdzie chcesz postawić X?\n");
    ponow:
    scanf("%s", i);   
    if(strcmp(i, "exit") == 0)
    {
        p.koniec = 1;
        return lr;
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
    lr.ruch[0] = atoi(i)-1;
    lr.ruch[1] = atoi(j)-1;

    if(p.ruch_zajety[lr.ruch[1]][lr.ruch[0]] == 1 || lr.ruch[0]>szer-1 || lr.ruch[1]>wys-1)
    {
        printf("RUCH NIEDOZWOLONY!\n\n");
        goto ponow;
    }

    return lr;
}

struct pole graj(struct pole starep, struct listaruchow lr)
{
    struct pole p = starep;

        
    if(p.czymgrasz == 'X')
        goto X;
    else if(p.czymgrasz == 'O')
        goto O;
    
    
    X:
    p.plansza[lr.ruch[1]][lr.ruch[0]] = 'X';
    p.ruch_zajety[lr.ruch[1]][lr.ruch[0]] = 1;
    p.pozostale_ruchy=p.pozostale_ruchy-1;
    p.wygrana = 0;
    p.wygrana = sprawdz(p, lr.ruch[0], lr.ruch[1]);
    p.czymgrasz = 'O';
    
    return p;

    O:

    p.plansza[lr.ruch[1]][lr.ruch[0]] = 'O';
    p.ruch_zajety[lr.ruch[1]][lr.ruch[0]] = 1;
    p.pozostale_ruchy=p.pozostale_ruchy-1;
    p.wygrana = 0;
    p.wygrana = sprawdz(p, lr.ruch[0], lr.ruch[1]);
    p.czymgrasz = 'X';

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

int negmax(struct pole* p, int glebokosc, int alfa, int beta)
{
    
    if(!glebokosc)
    {
        return sprawdzbot(*p);
    }
    int ocenawezla = -1000;
    for(struct listaruchow* lr = dostepneruchy(p), *ptr = lr; lr; lr = lr->nast, free(ptr), ptr = lr)
    {
        struct pole dziecko = graj(*p, *lr);

        int nowaocena = -negmax(&dziecko, glebokosc-1, -beta, -alfa);

        if(nowaocena > ocenawezla)
        {
            ocenawezla = nowaocena;
        }
        if(ocenawezla > alfa)
        {
            alfa = ocenawezla;
        }
        if(alfa > beta)
        {
            break;
        }
    }
    return ocenawezla;

}

struct listaruchow *najlepszy_ruch(struct pole *p, int glebokosc, int alfa, int beta)
{
int ile = p->pozostale_ruchy;
  int nowaocena[ile]; 
  struct listaruchow naj_pole[ile];
  
  int i = -1;
  struct listaruchow *j = NULL;
  j = (struct listaruchow*) malloc(sizeof(struct listaruchow));
  int maxocena;
    for(struct listaruchow *lr = dostepneruchy(p); lr; lr = lr->nast)
    {
      i++;
      struct pole dziecko = graj(*p, *lr);
      nowaocena[i] = -negmax(&dziecko, glebokosc, alfa, beta);
      naj_pole[i].ruch[0] = lr->ruch[0];
      naj_pole[i].ruch[1] = lr->ruch[1];
    }
        i = 0;
        j->ruch[0] = naj_pole[i].ruch[0];
        j->ruch[1] = naj_pole[i].ruch[1];

        maxocena = -50;
        for(i;i<ile;i++)
        {
            if(maxocena<nowaocena[i])
            {
                j->ruch[0] = naj_pole[i].ruch[0];
                j->ruch[1] = naj_pole[i].ruch[1];
                maxocena=nowaocena[i];
            }
        }
        
    return j;
}