#ifndef CADASTRO_H
#define CADASTRO_H

typedef struct cadastro //struct de usuarios para realizar o cadastro
{
    char name[20], email[30], cpf[12], cep[8], senha[60];
} user ;

void cadastro();
void limparBuffer();

#endif