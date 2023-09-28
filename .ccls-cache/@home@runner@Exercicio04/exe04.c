#include "pilhachar.h"
#include <stdio.h>
#include <string.h>

int fechamento(char chave) {
  return (chave == '}' || chave == ')' || chave == ']') ? 1 : 0;
}

int tiposIguais(char chaveAbertura, char chaveFechamento) {
  int result = 0;
  switch (chaveFechamento) {
  case '}':
    result = chaveAbertura == '{' ? 1 : 0;
    break;
  case ']':
    result = chaveAbertura == '[' ? 1 : 0;
    break;
  case ')':
    result = chaveAbertura == '(' ? 1 : 0;
    break;
  }
  return result;
}

int expressaoValida(Pilha expressaoP) {
  Pilha PAux = pilha(500);

  for (int i = expressaoP->topo; i >= 0; i--) {
    if (fechamento(topo(expressaoP))) {
      if (vaziap(PAux) || !tiposIguais(topo(PAux), topo(expressaoP))) {
        return 0;
      } else {
        desempilha(PAux);
        desempilha(expressaoP);
      }
    } else {
      empilha(desempilha(expressaoP), PAux);
    }
  }
  return 1;
}

int main(void) {
  char expressao[500];
  Pilha P = pilha(500);

  printf("Digite a expressão: ");
  gets(expressao);

  for (int i = strlen(expressao); i >= 0; i--)
    empilha(expressao[i], P);

  printf("\nA expressao '");
  fputs(expressao, stdout);

  if (expressaoValida(P))
    printf("' esta balanceada.");
  else
    printf("' esta desbalanceada.");
  destroip(&P);
  puts("\n");

  return 0;
}