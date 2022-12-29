/**
 * Questo file contiene le definizioni per le funzioni necessarie alla stampa su
 * terminale
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */
#pragma once

/**
 * I vari colori ANSI utilizzabili nel terminale
 */

#include <Definizioni.h>
#include <Giocatore.h>
#define ANSI_RESET "\x1b[0m"
#define ANSI_NERO "\x1b[30m"
#define ANSI_ROSSO "\x1b[31m"
#define ANSI_VERDE "\x1b[32m"
#define ANSI_GIALLO "\x1b[33m"
#define ANSI_BLU "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CIANO "\x1b[36m"

/**
 * Stampa il tabellone di gioco a schermo in una singola dimensione
 * @param tabellone il tabellone da stampare
 * @param dimensione_tabellone la dimensione del tabellone da stampare
 */
void stampa_tabellone(const Colore tabellone[], int dimensione_tabellone);

/**
 * Stampa il tabellone di gioco a schermo in una singola dimensione e indica per
 * ogni casella il nome del giocatore che la possiede
 * @param tabellone il tabellone da stampare
 * @param dimensione_tabellone la dimensione del tabellone da stampare
 * @param giocatori vettore di giocatori
 * @param numero_giocatori il numero di giocatori
 */
void stampa_tabellone_con_giocatori(const Colore tabellone[],
                                    int dimensione_tabellone,
                                    Giocatore* giocatori[],
                                    int numero_giocatori);

/**
 * Converte da un colore del tabellone a un colore ANSI per il terminale
 * @param colore il colore da convertire
 * @returns il codice ANSI adatto alla stampa su terminale
 */
const char* colore_a_ansi(const Colore colore);
