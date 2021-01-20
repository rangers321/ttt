#ifndef _TIC_TAC_TOE_2077_DELUXE_EDITION_FUNKCJONALNE_H
#define _TIC_TAC_TOE_2077_DELUXE_EDITION_FUNKCJONALNE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tic_tac_toe_2077_deluxe_edition_wykonawcze.h"

#define wygrywa 3
#define wys 3
#define szer 3

struct pole
{
    char plansza[wys+1][szer+1], ruch_zajety[wys+1][szer+1], *czymgrasz;
    int wygrana, pozostale_ruchy, koniec, wysokosc, szerokosc;
};

struct listaruchow
{
    char ruchy[wys+1][szer+1], ruch1[(wys*szer)+2], ruch2[(wys*szer)+2], ruch[100];
    struct listaruchow* nast;
};

void wypisz(struct pole p);

struct pole zeruj(void);

void komendy(void);

#endif