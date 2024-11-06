#include <stdio.h>
#include "c:\cproject\projetoUnip2.0\lib\fruta.h"
#include "c:\cproject\projetoUnip2.0\lib\cupom.h"
#include "c:\cproject\projetoUnip2.0\lib\pim.h"
#include "c:\cproject\projetoUnip2.0\lib\suporte.h"

extern float valor_total;

int menu_cupom(float* valor_total, Cupom cupomValor[]);
void aplicarDesconto(float* valor_total, Cupom cupomValor[], int escolha);
int cupons();

int cupons() 
{
    Cupom cupomValor[] = //valores de cupons
    {
        {"FASTFRUIT", 5.0},
        {"CUPOMFRUIT", 10.0},
        {"SUPERFRUIT", 20.0}
    };
    return 0;
}

int menu_cupom(float* valor_total, Cupom cupomValor[]) 
{
    int escolha;
    printf("Cupons: FASTFRUIT R$5.00 | CUPOMFRUIT R$10.00 | SUPERFRUIT R$20.00");
    printf("\nSelecione o cupom que deseja usar (1-3): \n");
    scanf("%d", &escolha);

    escolha -= 1; // Ajusta o índice para começar do zero

    // Verifica se a escolha está dentro dos limites
    if (escolha < 0 || escolha > 2) 
    {
        printf("Escolha inválida! Por favor, escolha um número de 1 a 3.\n");
        return -1; // Indica erro
    }

    printf("Voce escolheu o Cupom %s, deseja continuar? \n1- SIM \n2- Escolher outro cupom \n3- descartar cupom e finalizar compra\n", cupomValor[escolha].nome);
    int opcao;
    scanf("%d", &opcao);

    switch (opcao) 
    {
        case 1: // Aplica o desconto
            aplicarDesconto(valor_total, cupomValor, escolha); 
            printf("Compra finalizada com o valor de R$ %.2f\n", *valor_total); //passa valor_total para frutinhas.c
            return 1;

        case 2: // Chama a função novamente se o usuário quiser escolher outro cupom
            printf("Escolha outro cupom.\n");
            menu_cupom(valor_total, cupomValor);
            return 0; // Retorna 0 para continuar no menu
        
        case 3: //finaliza a compra
            printf("Compra finalizada sem aplicar cupom.\n");
            return 1;
    }

    return 0; // Caso nenhuma opção válida seja selecionada
}

void aplicarDesconto(float* valor_total, Cupom cupomValor[], int escolha) 
{
    if (escolha >= 0 && escolha < 3) 
    {
        *valor_total -= cupomValor[escolha].valor; // Aplica o desconto
        printf("Desconto aplicado: R$ %.2f\n", cupomValor[escolha].valor);
    } 
    else 
    {
        printf("Escolha inválida para aplicar desconto.\n");
    }
}