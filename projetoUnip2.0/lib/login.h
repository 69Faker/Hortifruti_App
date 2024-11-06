#ifndef LOGIN_H
#define LOGIN_H

extern const char* email_global;
int verificar_user(struct cadastro user);
void obter_linha(FILE *arquivo, char *linha, size_t tamanho);
const char* login();

#endif