struct ocena negmax(struct szachownica* sz, char glebokosc, int alfa, int beta)
{​​​​​​​
if (!glebokosc)
return ocena(sz);
int ocenawezla = -PRZEGRANA;
for(struct listaruchow *lr = dostepneruchy(sz), *ptr = lr; lr; lr = lr->nast, free(ptr), ptr = lr)
{​​​​​​​
dziecko = wykonajruch(sz, lr->ruch);
nowaocena = -negmax(&dziecko, glebokosc - 1, -beta, -alfa);
if (nowaocena > ocenawezla)
ocenawezla = nowaocena;
if (ocenawezla > alfa)
alfa = ocenawezla;
if (alfa > beta)
{​​​​​​​
// zwolninenie listy ruchów do końca
break;
}​​​​​​​
}​​​​​​​
return ocenawezla;
}​​​​​​​