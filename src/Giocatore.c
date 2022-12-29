/**
 * Questo file contiene l'implementazione della struttura Giocatore e delle
 * funzioni che ne gestiscono il funzionamento.
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#include <Giocatore.h>

int trova_casella(Giocatore* giocatori[], int numero_giocatori,
                  int indice_casella) {
  for (int i = 0; i < numero_giocatori; i++) {
    Giocatore* giocatore = giocatori[i];
    for (int j = 0; j < giocatore->numero_caselle; j++) {
      if (giocatore->caselle[j] == indice_casella) {
        return i;
      }
    }
  }
  return -1;
}

Giocatore* crea_giocatore(char const* nome) {
  Giocatore* giocatore = malloc(sizeof(Giocatore));

  // Valore di default come indicato dalla traccia
  giocatore->saldo = 100;

  // Ogni giocatore parte dalla prima casella (bianca)
  giocatore->posizione = 0;

  // Imposta il numero di caselle possedute a 0
  giocatore->numero_caselle = 0;

  strncpy(giocatore->nome, nome, DimensioniStringa);
  return giocatore;
}

void aggiungi_giocatore(Giocatore* lista[], Giocatore* nuovo_giocatore,
                        int indice) {
  lista[indice] = nuovo_giocatore;
}

void dealloca_giocatori(Giocatore* giocatori[], int dimensione) {
  for (int i = 0; i < dimensione; i++) {
    // Per ogni elemento all'indice i chiama la funzione free
    // per de-allocare la memoria
    free(giocatori[i]);
    giocatori[i] = NULL;
  }
}
