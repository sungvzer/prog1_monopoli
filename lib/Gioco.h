/**
 * Questo file contiene le definizioni per le funzioni relative allo svolgimento
 * del gioco
 *
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#pragma once

#include <Definizioni.h>
#include <Giocatore.h>

/**
 * Assegna da 0 a 4 caselle ad ogni giocatore
 * @param giocatori il vettore di giocatori
 * @param numero_giocatori il numero di giocatori
 * @param tabellone il tabellone contenente le caselle
 * @param dimensione_tabelloen la dimensione del tabellone
 * @returns il numero di caselle assegnate
 */
int assegna_caselle_ai_giocatori(Giocatore *giocatori[], int numero_giocatori,
                                 Colore const tabellone[],
                                 int dimensione_tabellone);

/**
 * Esegue un turno del gioco per un singolo giocatore
 * @param giocatori il vettore di giocatori
 * @param numero_giocatori il numero di giocatori
 * @param indice_giocatore_attivo l'indice del giocatore attivo
 * @param tabellone il tabellone di gioco
 * @param dimensione_tabellone la dimensione del tabellone di gioco
 * @returns 1 se il gioco può continuare, 0 se il gioco è terminato (tutti i
 * giocatori tranne uno hanno saldo <=0)
 */
int gioca_turno(Giocatore *giocatori[], int numero_giocatori,
                int indice_giocatore_attivo, Colore const tabellone[],
                int dimensione_tabellone);

/**
 * Assegna da 0 a 4 caselle ad ogni giocatore
 * @param tabellone il tabellone all'interno del quale copiare il colore delle
 * caselle
 * @param dimensione_destinazione dimensione della destinazione
 * @param tabellone il tabellone da gioco contenente il colore delle caselle
 * @param dimensione_tabellone dimensione del tabellone
 * @returns il numero di caselle assegnate
 */
void copia_tabellone(Colore destinazione[], int dimensione_destinazione,
                     Colore const tabellone[], int dimensione_tabellone);

/**
 * Controlla i saldi dei giocatori
 * @param giocatori il vettore di giocatori
 * @param numero_giocatori il numero di giocatori
 * @returns il numero di giocatori con saldo <= 0
 */
int controlla_saldi(Giocatore *giocatori[], int numero_giocatori);
