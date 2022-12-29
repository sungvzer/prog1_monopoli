/**
 * Questo file contiene l'implementazione delle funzioni necessarie alla stampa
 * su terminale
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#include <Giocatore.h>
#include <Terminale.h>
#include <stdio.h>

void stampa_tabellone_con_giocatori(const Colore tabellone[],
                                    int dimensione_tabellone,
                                    Giocatore* giocatori[],
                                    int numero_giocatori) {
  Giocatore const* giocatore = NULL;
  for (int i = 0; i < dimensione_tabellone; i++) {
    int indice = trova_casella(giocatori, numero_giocatori, i);
    if (indice == -1) {
      // Se il giocatore non viene trovato, stampa la casella vuota
      printf("%s[]%s ", colore_a_ansi(tabellone[i]), ANSI_RESET);
    } else {
      // Altrimenti stampa il nome del giocatore
      giocatore = giocatori[indice];
      printf("%s[%s]%s ", colore_a_ansi(tabellone[i]), giocatore->nome,
             ANSI_RESET);
    }
  }
}

void stampa_tabellone(const Colore tabellone[], int dimensione_tabellone) {
  for (int i = 0; i < dimensione_tabellone; i++) {
    printf("%s[]%s ", colore_a_ansi(tabellone[i]), ANSI_RESET);
  }
}

const char* colore_a_ansi(const Colore colore) {
  switch (colore) {
    case Bianco:
      return "";
    case Azzurro:
      return ANSI_BLU;
    case Arancione:
      return ANSI_GIALLO;
    case Nero:
      return ANSI_NERO;
    case Verde:
      return ANSI_VERDE;
    case Rosso:
      return ANSI_ROSSO;
    case Viola:
      return ANSI_MAGENTA;
  }
  return "";
}
