#ifndef CUPOM_H
#define CUPOM_H

typedef struct { //struct cupom
    char nome[20];
    float valor;
} Cupom;

extern float valor_total;

int menu_cupom(float* valor_total, Cupom cupomValor[]);
void aplicarDesconto(float* valor_total, Cupom cupomValor[], int escolha);
int cupons(); 

#endif