/**
 * Questo file contiene le definizioni della struttura Giocatore e delle
 * funzioni che ne gestiscono il funzionamento.
 *
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#pragma once

#include <Definizioni.h>
#include <stdlib.h>
#include <string.h>

/**
 * Identifica un singolo giocatore.
 * @param saldo il saldo del giocatore
 * @param nome il nome del giocatore
 * @param posizione la posizione del giocatore nel tabellone
 * @param caselle gli indici delle caselle del tabellone possedute dal giocatore
 * @param numero_caselle il numero di caselle possedute dal giocatore (max. 4)
 */
typedef struct {
  int saldo;
  char nome[DimensioniStringa];
  int posizione;
  int caselle[DimensioniCaselle];
  int numero_caselle;
} Giocatore;

/**
 * Trova l'indice del giocatore che possiede la casella
 * @param giocatori il vettore di giocatori
 * @param numero_giocatori il numero di giocatori
 * @param indice_casella l'indice della casella da ricercare
 * @returns l'indice del giocatore che possiede la casella o -1 se nessun
 * giocatore possiede la casella
 */
int trova_casella(Giocatore* giocatori[], int numero_giocatori,
                  int indice_casella);

/**
 * Crea un giocatore, allocato nell'heap
 * @param nome il nome da assegnare al giocatore
 * @returns un puntatore al nuovo giocatore allocato
 */
Giocatore* crea_giocatore(char const* nome);

/**
 * Aggiunge un giocatore alla lista di giocatori
 * @param lista il vettore contenente i puntatori ai giocatori
 * @param nuovo_giocatore il puntatore al giocatore da aggiungere
 * @param indice l'indice all'interno del quale inserire il giocatore
 */
void aggiungi_giocatore(Giocatore* lista[], Giocatore* nuovo_giocatore,
                        int indice);
/**
 * Elimina la lista di giocatori, liberando la memoria allocata
 * @param giocatori il vettore contenente i puntatori ai giocatori
 * @param dimensione la dimensione del vettore
 */
void dealloca_giocatori(Giocatore* giocatori[], int dimensione);
