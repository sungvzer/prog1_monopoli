/**
 * Questo file contiene le implementazioni per le funzioni relative allo
 * svolgimento del gioco
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#include <Dado.h>
#include <Giocatore.h>
#include <Gioco.h>
#include <Tabellone.h>
#include <Terminale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copia_tabellone(Colore destinazione[], int dimensione_destinazione,
                     Colore const tabellone[], int dimensione_tabellone) {
  int min_dimensioni = dimensione_destinazione;
  if (dimensione_tabellone < dimensione_destinazione)
    min_dimensioni = dimensione_tabellone;

  for (int i = 0; i < min_dimensioni; i++) {
    destinazione[i] = tabellone[i];
  }
}

int assegna_caselle_ai_giocatori(Giocatore *giocatori[], int numero_giocatori) {
  int tot_caselle_assegnate = 0;
  int caselle_da_assegnare_al_giocatore;
  int indice_tabellone = 0;
  Colore nuovo_tabellone[DimensioneTabellone];

  copia_tabellone(nuovo_tabellone, DimensioneTabellone, s_tabellone,
                  DimensioneTabellone);

  for (int ind = 0; ind < numero_giocatori; ind++) {
    // Per ogni giocatore
    Giocatore *giocatore = giocatori[ind];
    // Genera casualmente il numero di caselle da assegnare da 0 a 4
    caselle_da_assegnare_al_giocatore = rand() % 5;
    int numero_caselle = 0;

    while (numero_caselle < caselle_da_assegnare_al_giocatore &&
           tot_caselle_assegnate != DimensioneTabellone) {
      // Genera un indice tra 1 e (DimensioneTabellone - 1)
      indice_tabellone = (rand() % (DimensioneTabellone - 1)) + 1;

      // Se la casella all'indice non è stata marcata come "usata" (-1), allora
      // assegnala al giocatore
      if (nuovo_tabellone[indice_tabellone] != -1) {
        giocatore->caselle[numero_caselle] = indice_tabellone;
        nuovo_tabellone[indice_tabellone] = -1;
        numero_caselle++;
      }
    }
    giocatore->numero_caselle = numero_caselle;
    tot_caselle_assegnate += numero_caselle;
  }
  return tot_caselle_assegnate;
}

int gioca_turno(Giocatore *giocatori[], int numero_giocatori,
                int indice_giocatore_attivo, Colore const tabellone[],
                int dimensione_tabellone) {
  // Separatore dei turni
  printf("----------------\n");

  Giocatore *giocatore_attivo = giocatori[indice_giocatore_attivo];
  int spostamento_giocatore = lancia_dadi();

  // Aggiungi lo spostamento alla posizione del giocatore...
  int nuova_casella = giocatore_attivo->posizione + spostamento_giocatore;

  // ...e simula il movimento circolare tramite l'operatore modulo
  nuova_casella = nuova_casella % dimensione_tabellone;

  printf("Spostato %s nella casella %d (%d + %d)\n", giocatore_attivo->nome,
         nuova_casella, giocatore_attivo->posizione, spostamento_giocatore);

  int indice_proprietario =
      trova_casella(giocatori, numero_giocatori, nuova_casella);

  if (indice_proprietario != -1 &&
      indice_proprietario != indice_giocatore_attivo) {
    // Se la casella ha un proprietario, ed egli non è il giocatore corrente

    // Colore rappresenta un tipo numerico, usiamo il cast per chiarezza di tipo
    // usato per le operazioni numeriche
    int costo_da_pagare = (int)tabellone[nuova_casella];
    Giocatore *proprietario = giocatori[indice_proprietario];

    printf("Paga %s%d%s euro a %s\n", colore_a_ansi(tabellone[nuova_casella]),
           costo_da_pagare, ANSI_RESET, proprietario->nome);

    // Trasferisci saldo tra i due giocatori
    proprietario->saldo += costo_da_pagare;
    giocatore_attivo->saldo -= costo_da_pagare;

    printf("Nuovo saldo di %s%s%s: %d\n",
           colore_a_ansi(tabellone[nuova_casella]), proprietario->nome,
           ANSI_RESET, proprietario->saldo);
    printf("Nuovo saldo di %s: %d\n", giocatore_attivo->nome,
           giocatore_attivo->saldo);

  } else if (indice_proprietario == -1) {
    printf("La casella non appartiene a nessun giocatore.\n");
  } else {
    printf("È il proprietario di questa casella.\n");
  }

  // Sposta il giocatore
  giocatore_attivo->posizione = nuova_casella;

  // Separatore dei turni
  printf("----------------\n");

  if (controlla_saldi(giocatori, numero_giocatori) == numero_giocatori - 1) {
    return 0;
  }

  return 1;
}

int controlla_saldi(Giocatore *giocatori[], int numero_giocatori) {
  int numero_saldi_negativi_o_nulli = 0;
  Giocatore *corrente;

  for (int i = 0; i < numero_giocatori; i++) {
    corrente = giocatori[i];
    if (corrente->saldo <= 0) {
      numero_saldi_negativi_o_nulli++;
    }
  }

  return numero_saldi_negativi_o_nulli;
}
