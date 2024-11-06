#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "c:\cproject\projetoUnip2.0\lib\cadastro.h"
#include "c:\cproject\projetoUnip2.0\lib\pim.h"
#include "c:\cproject\projetoUnip2.0\lib\suporte.h"

extern int opcao; // Variável de pim.c que é usada na função login
int verificar_user(struct cadastro user);
void obter_linha(FILE *arquivo, char *linha, size_t tamanho);
const char* login();

// Definindo uma variável global para armazenar o e-mail
static char email_global[30];

const char* login() 
{
    bool login = false;
    struct cadastro user;

    while (!login)
    {
        // Coleta de dados de login
        printf("Digite seu email: ");
        fgets(user.email, sizeof(user.email), stdin);
        user.email[strcspn(user.email, "\n")] = 0; // Remove a quebra de linha

        printf("Digite sua senha: ");
        fgets(user.senha, sizeof(user.senha), stdin);
        user.senha[strcspn(user.senha, "\n")] = 0; // Remove a quebra de linha

        // Verifica as credenciais
        if (verificar_user(user)) // Chama a função verificar o user
        { 
            printf("Login bem-sucedido!\n");
            login = true;

            // Cópia do email do usuário para a variável global
            strncpy(email_global, user.email, sizeof(email_global) - 1);
            email_global[sizeof(email_global) - 1] = '\0'; // Garante que a string está terminada
            menu();
            manage(opcao, email_global); // Passa o email_global para manage
        } 
        else 
        {
            printf("Email ou senha incorretos.\n");     
        }
    }

    // Retorna o e-mail armazenado
    return email_global;
}

void obter_linha(FILE *arquivo, char *linha, size_t tamanho) 
{
    if (fgets(linha, tamanho, arquivo) != NULL) 
    {
        linha[strcspn(linha, "\n")] = 0; // Remove a quebra de linha
    }
}

int verificar_user(struct cadastro user) 
{
    // Abrindo os arquivos
    FILE *email_user;
    FILE *password_user;

    email_user = fopen("c:/cproject/projetoUnip2.0/output/email_user.txt", "r"); //abrindo email_user.txt
    password_user = fopen("c:/cproject/projetoUnip2.0/output/password_user.txt", "r"); //abrindo password_user.txt

    if (!email_user || !password_user) //verifica se os arquivos existem
    {
        printf("Erro ao abrir os arquivos de dados.\n");
        return 0;  // Retorna 0 se os arquivos não puderem ser abertos
    }

    // Variáveis utilizadas
    char email_linha[100];
    char password_linha[100];
    int user_encontrado = 0;

    // Loop para verificar todas as linhas do arquivo
    while (1) 
    {
        obter_linha(email_user, email_linha, sizeof(email_linha)); // chama a função obter_lina e lê linha por linha do arquivo
        obter_linha(password_user, password_linha, sizeof(password_linha));

        // Se não houver mais linhas, saia do loop
        if (feof(email_user) || feof(password_user)) 
        {
            break;
        }

        // Verifica se o email e a senha fornecidos correspondem aos armazenados
        if (strcmp(user.email, email_linha) == 0 && strcmp(user.senha, password_linha) == 0) //verifica pela linha do arquivo
        {
            user_encontrado = 1;
            break;
        }
    }
    
    fclose(email_user);
    fclose(password_user);
    return user_encontrado; // Retorna 1 se o usuário for encontrado, 0 caso contrário
}