#include "pilhachar.h"
#include <stdio.h>
#include <string.h>

int main(void) {
  char frase[500];
  Pilha P = pilha(500);
  Pilha PAux = pilha(500);

  printf("Digite a frase: ");
  gets(frase);

  for (int i = 0; frase[i]; i++) {
    if (frase[i] == ' ' || frase[i + 1] == '\0') {
      for (int j = (frase[i] == ' ' ? i - 1 : i); j >= 0; j--) {
        if (frase[j] == ' ')
          j = 0;
        else
          empilha(frase[j], PAux);
      }
      if (frase[i] == ' ')
        empilha(frase[i], PAux);
    }
  }

  while (!vaziap(PAux))
    empilha(desempilha(PAux), P);

  printf("Frase invertida: ");
  while (!vaziap(P))
    printf("%c", desempilha(P));
  puts("\n");
  destroip(&P);

  return 0;
}