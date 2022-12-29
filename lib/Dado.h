/**
 * Questo file contiene le definizioni delle funzioni necessarie al
 * funzionamento delle meccaniche dei dadi
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#pragma once
#include <stdlib.h>

/**
 * Genera un numero da 2 a 12, l'equivalente del lanciare 2 dadi da 6 facce.
 *
 * Genera un numero tra {0,10} inclusi, per poi trasportare l'intervallo a
 * {2,12}
 * @returns il risultato del lancio dei dadi
 */
int lancia_dadi();
