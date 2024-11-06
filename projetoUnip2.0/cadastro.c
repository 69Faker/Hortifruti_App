#include <stdio.h>
#include <string.h>
#include "c:\cproject\projetoUnip2.0\lib\cadastro.h"
#include "c:\cproject\projetoUnip2.0\lib\pim.h"
#include "c:\cproject\projetoUnip2.0\lib\suporte.h"

void cadastro();
void limparBuffer();

void limparBuffer() //limpar \n do teclado.
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Limpa até encontrar '\n'
}

void cadastro() //cadastrar novo usuario.
{
    struct cadastro user;
    FILE *name_user; //define a variavel do arquivo
    name_user = fopen("c:/cproject/projetoUnip2.0/output/name_user.txt", "a"); //name_user.txt "a" escreve 
    printf("digite o nome do user:");                                          //no final do arquivo
    fgets(user.name,20,stdin); //recebe o nome do user.
    user.name[strcspn(user.name, "\n")] = 0; //troca o \n por 0;
    fprintf(name_user, "%s\n", user.name); //grava no arquivo
    fclose(name_user); //fecha o arquivo

    FILE *email_user;
    email_user = fopen("c:/cproject/projetoUnip2.0/output/email_user.txt", "a"); //email_user.txt
    printf("digite o email do user:");
    fgets(user.email,60,stdin);
    user.email[strcspn(user.email, "\n")] = 0; //remove \n
    fprintf(email_user,"%s\n",user.email);
    fclose(email_user);

    FILE *cpf_user;
    cpf_user = fopen("c:/cproject/projetoUnip2.0/output/cpf_user.txt", "a"); //cpf_user.txt
    printf("digite o cpf do user:");
    fgets(user.cpf,20,stdin);
    user.cpf[strcspn(user.cpf, "\n")] = 0; //remove \n
    fprintf(cpf_user,"%s\n",user.cpf);
    fclose(cpf_user);

    FILE *cep_user;
    cep_user = fopen("c:/cproject/projetoUnip2.0/output/cep_user.txt", "a"); //cep_user.txt
    printf("digite a cep do user:");
    fgets(user.cep,20,stdin);
    user.cep[strcspn(user.cep, "\n")] = 0; //remove \n
    fprintf(cpf_user,"%s\n",user.cep);
    fclose(cpf_user);

    FILE *password_user;
    password_user = fopen("c:/cproject/projetoUnip2.0/output/password_user.txt", "a"); //password_user.txt
    printf("Digite sua senha:");
    fgets(user.senha,60,stdin);
    user.senha[strcspn(user.cep, "\n")] = 0;
    fprintf(password_user, "%s\n",user.senha);
    fclose(password_user);
}

