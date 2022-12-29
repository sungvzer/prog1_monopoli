/**
 * Si vuole sviluppare un programma per la simulazione di una fase del gioco del
 * "monopoli".
 * Si suppone di avere 6 giocatori identificati dal loro nome o da un
 * "personaggio"
 * Ogni giocatore ha a disposizione dei soldi iniziali (100 euro) dei "terreni"
 * come nella seguente figura (la cella bianca sul percorso identifica il
 * "via").
 * I terreni sono di diverso colore e hanno il seguente valore: azzurro 1 euro,
 * arancione 2 euro, nero 3 euro, verde 4 euro, rosso 5 euro e viola 6 euro.
 * Inizialmente i "terreni" vengono distribuiti in maniera casuale ai
 * partecipanti ma ogni giocatore non può averne più di 4. Partendo dal via, ad
 * ogni turno un giocatore lancia due dadi e in base al punteggio si sposta
 * nella cella corrispondente. Se il giocatore arriva in un terreno in suo
 * possesso passa il turno al giocatore successivo altrimenti paga, secondo il
 * valore precedentemente indicato, dei soldi al proprietario del terreno
 *
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#include <Dado.h>
#include <Definizioni.h>
#include <Giocatore.h>
#include <Gioco.h>
#include <Tabellone.h>
#include <Terminale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]) {
  // Imposta il seed iniziale per il generatore casuale di numeri
  srand(time(0));

  Giocatore* giocatori[NumeroGiocatori];

  // Crea i giocatori
  Giocatore* nuovo_giocatore;
  for (int i = 0; i < NumeroGiocatori; i++) {
    char nome[DimensioniStringa];
    sprintf(nome, "Giocatore %d", i);

    nuovo_giocatore = crea_giocatore(nome);
    aggiungi_giocatore(giocatori, nuovo_giocatore, i);
  }

  assegna_caselle_ai_giocatori(giocatori, NumeroGiocatori);
  printf("Assegnate le seguenti caselle:\n");
  stampa_tabellone_con_giocatori(s_tabellone, DimensioneTabellone, giocatori,
                                 NumeroGiocatori);

  printf("\n");

  // Gioca (a titolo esemplificativo) 6 turni, fermandosi se il gioco ha
  // ottenuto un vincitore.
  // Un giocatore vince se tutti i giocatori tranne lui sono in bancarotta
  // (hanno saldo <= 0)
  int indice_giocatore = 0;
  for (int i = 0; i < 6; i++) {
    if (!gioca_turno(giocatori, NumeroGiocatori, indice_giocatore, s_tabellone,
                     DimensioneTabellone))
      break;
    indice_giocatore = (indice_giocatore + 1) % NumeroGiocatori;
  }

  // Pulizia
  dealloca_giocatori(giocatori, NumeroGiocatori);
  return 0;
}
