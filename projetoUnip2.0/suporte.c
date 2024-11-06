#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c:\cproject\projetoUnip2.0\lib\cadastro.h"
#include "c:\cproject\projetoUnip2.0\lib\pim.h"
#include "c:\cproject\projetoUnip2.0\lib\suporte.h"
#include "c:\cproject\projetoUnip2.0\lib\login.h"

void salvar_mensagem(const char* email); // Adicionado parâmetro para passar o email
void verificar_email(const char* email);

void incrementar_arquivos(const char* email);

Suporte suporte; //variavel suporte_nome.arquivo

void verificar_email(const char* email) 
{
    char email_digitado[30];

    while (1) 
    {
        printf("Qual seu email? ");
        fgets(email_digitado, sizeof(email_digitado), stdin);
        email_digitado[strcspn(email_digitado, "\n")] = 0;

        if (strcmp(email_digitado, email) == 0) 
        {
            printf("Email verificado com sucesso!\n");
            return; // Sai da função se o e-mail estiver correto
        } 
        else 
        {
            printf("Email nao corresponde ao email do login. Tente novamente.\n");
        }
    }
}

void incrementar_arquivos(const char* email) 
{
    verificar_email(email); // Verifica o e-mail antes de prosseguir
    
    int contador = 1;
    while (1)
    {
        sprintf(suporte.nome_arquivo, "c:/cproject/projetoUnip2.0/output/reclamacao/reclamacao%d.txt", contador);
        FILE *mensagem = fopen(suporte.nome_arquivo, "r");
        if (mensagem == NULL) // Se o arquivo não existir
        {
           
            mensagem = fopen(suporte.nome_arquivo, "w"); // Tente abrir para escrita
            if (mensagem == NULL) // Se falhar ao abrir para escrita
            {
                printf("Erro ao abrir o arquivo.\n"); //erro
                return; 
            }

            fclose(mensagem); // Fecha o arquivo após criar
            salvar_mensagem(suporte.nome_arquivo); // Chama a função para salvar a mensagem
            break; // Sai do loop, pois o arquivo foi criado
        }
        fclose(mensagem); // Fecha o arquivo que foi encontrado
        contador++; // Incrementa o contador para tentar o próximo nome de arquivo
    }
}

void salvar_mensagem(const char* nome_arquivo) // Recebe o nome do arquivo como parâmetro
{
    FILE *mensagem;
    mensagem = fopen(nome_arquivo, "w"); 
    if (mensagem == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Qual sua reclamacao? (Digite 'sair' para finalizar)\n");
    while(1)
    {
        fgets(suporte.mensagem, sizeof(suporte.mensagem), stdin);
        suporte.mensagem[strcspn(suporte.mensagem, "\n")] = 0;
        if (strcmp(suporte.mensagem, "sair") == 0 )
        {
            break;
        }
        fprintf(mensagem, "%s\n", suporte.mensagem);
    }
    fclose(mensagem);
}