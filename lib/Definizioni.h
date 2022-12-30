/**
 * Questo file contiene varie definizioni usate nel programma
 *
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#pragma once

#define DimensioniStringa 1024
#define DimensioniCaselle 4
#define NumeroGiocatori 6

/** Il numero di caselle all'interno del tabellone */
#define DimensioneTabellone 20

/**
 * Definisce l'associazione tra un colore e il suo corrispettivo valore
 */
typedef enum {
  Bianco = 0,
  Azzurro = 1,
  Arancione = 2,
  Nero = 3,
  Verde = 4,
  Rosso = 5,
  Viola = 6
} Colore;
