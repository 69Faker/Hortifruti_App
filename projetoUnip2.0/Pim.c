#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "c:\cproject\projetoUnip2.0\lib\cupom.h"
#include "c:\cproject\projetoUnip2.0\lib\fruta.h"
#include "c:\cproject\projetoUnip2.0\lib\cadastro.h"
#include "c:\cproject\projetoUnip2.0\lib\pim.h"
#include "c:\cproject\projetoUnip2.0\lib\suporte.h"
#include "c:\cproject\projetoUnip2.0\lib\login.h"

int opcao;

// Definir funções
int menu(); 
int manage(int opcao, const char* email); 
const char* inicio();

// Função inicial
const char* inicio() //menu inicial (cadastro ou login)
{   
    const char* user_email = NULL; // Variável para armazenar o e-mail do usuário

    do 
    {
        printf("| 1- Cadastro | 2-Login |\n");
        scanf("%d", &opcao);
        limparBuffer();
        
        if (opcao < 1 || opcao > 2)
        {
            printf("Valor inválido, tente novamente.\n");
        }
    } while (opcao < 1 || opcao > 2);    
    
    switch (opcao)
    {
        case 1:
            printf("Cadastro:\n");
            cadastro(); //chama a função para realizar cadastro
            break;
        case 2:
            printf("------ Bem-vindo ------\n");
            user_email = login(); // Chama a função login e recebe o e-mail
            break;
    }
    return user_email;
}

int menu() //loop utilizado em int manage
{
    do
    {
        printf("| 1- Frutas | 2- Suporte |\n");
        scanf("%d", &opcao);
        limparBuffer();

        if (opcao < 1 || opcao > 2)
            printf("Digite um número válido.\n");
    } while (opcao < 1 || opcao > 2);
    
    return opcao;
}

int manage(int opcao, const char* email) // recebe variavel opcao e passa o e-mail para o suporte
{
    switch (opcao) 
    {
        case 1: // função de frutinhas.c
            frutas();
            break;

        case 2: // suporte, recebe o email utilizado no login
            incrementar_arquivos(email);
            break; 
    }
    return 0; // Caso nenhuma opção válida seja selecionada
}

int main() // Chama todas as funções
{
    const char* email = inicio(); //chama a função inicio e vincula o email utilizado com a variavel "email"
    int opcao;

    return 0; // Retorno padrão de main
}