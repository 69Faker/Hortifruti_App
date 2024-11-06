#ifndef SUPORTE_H
#define SUPORTE_H

typedef struct {
    char nome_arquivo[20];
    char mensagem[200];
    float valor;
} Suporte;

void salvar_mensagem(const char* email);
void verificar_email(const char* email);
void incrementar_arquivos(const char* email);

#endif