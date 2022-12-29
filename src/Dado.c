/**
 * Questo file contiene l'implementazione delle funzioni necessarie al
 * funzionamento delle meccaniche dei dadi
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#include <Dado.h>

int lancia_dadi() {
  int result = rand() % 11 + 2;
  return result;
}
