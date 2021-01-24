#ifndef _TIC_TAC_TOE_2077_DELUXE_EDITION_WYKONAWCZE_H
#define _TIC_TAC_TOE_2077_DELUXE_EDITION_WYKONAWCZE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "tic_tac_toe_2077_deluxe_edition_funkcjonalne.h"

int sprawdz_poziom(struct pole p,int a, int b);

int sprawdz_pion(struct pole p,int a, int b);

int sprawdz_ukos1(struct pole p,int a, int b);

int sprawdz_ukos2(struct pole p, int a, int b);

int sprawdz(struct pole p, int a, int b);

int sprawdzbotpoziom(struct pole p);

int sprawdzbotpion(struct pole p);

int sprawdzbotukos1(struct pole p);

int sprawdzbotukos2(struct pole p);

int sprawdzbot(struct pole p);

struct listaruchow* dostepneruchy(struct pole* p);

void wypiszdostepneruchy(struct pole p);

struct pole interfejs(struct pole p);

struct pole graj(struct pole stare, struct listaruchow starelr);

int ponow(void);


#endif