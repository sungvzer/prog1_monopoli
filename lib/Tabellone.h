/**
 * Questo file contiene le definizioni per il tabellone di gioco
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#pragma once
#include <Definizioni.h>

/** Il numero di caselle all'interno del tabellone */
#define DimensioneTabellone 20

/** Il tabellone di gioco  */
static const Colore s_tabellone[] = {
    Bianco, Arancione, Arancione, Arancione, Rosso,   Verde,   Verde,
    Nero,   Azzurro,   Azzurro,   Rosso,     Viola,   Viola,   Viola,
    Rosso,  Verde,     Verde,     Nero,      Azzurro, Azzurro,
};
