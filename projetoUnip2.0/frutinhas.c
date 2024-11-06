#include <stdio.h>
#include "c:\cproject\projetoUnip2.0\lib\fruta.h"   
#include "c:\cproject\projetoUnip2.0\lib\cupom.h" 
#include "c:\cproject\projetoUnip2.0\lib\pim.h"
#include "c:\cproject\projetoUnip2.0\lib\suporte.h"

int frutas() 
{
    // Array de frutas
    Fruta frutas[] = 
    {
    {"Banana", 5.0},
    {"Maca", 4.0},
    {"Pera", 4.0},
    {"Uva", 9.0},
    {"Abacaxi", 6.5},
    {"Mamao", 6.0},
    {"Laranja", 3.5},
    {"Manga", 7.0},
    {"Melancia", 3.0},
    {"Melao", 8.0},
    {"Kiwi", 13.0},
    {"Morango", 12.0},
    {"Abacate", 8.5},
    {"Limao", 2.5},
    {"Coco", 7.5},
    {"Caju", 15.0},
    {"Jabuticaba", 18.0},
    {"Acai", 22.0},
    {"Carambola", 9.0},
    {"Maracuja", 10.0}
    };
    
    // Array de cupons
    Cupom cupomValor[] = 
    {
        {"FASTFRUIT", 5.0},
        {"CUPOMFRUIT", 10.0},
        {"SUPERFRUIT", 20.0}
    };

    // Quantidade de cada fruta
    int quantidade_frutas[20] = {0}; // Inicializa todas as quantidades com 0

    int escolha, i;
    float valor_total = 0;
    do 
    {
        // Menu de opções
        printf("\nEscolha uma fruta:\n"
       "1. Banana      - R$ 5.00\n"
       "2. Maca        - R$ 4.00\n"
       "3. Pera        - R$ 4.00\n"
       "4. Uva         - R$ 9.00\n"
       "5. Abacaxi     - R$ 6.50\n"
       "6. Mamao       - R$ 6.00\n"
       "7. Laranja     - R$ 3.50\n"
       "8. Manga       - R$ 7.00\n"
       "9. Melancia    - R$ 3.00\n"
       "10. Melao      - R$ 8.00\n"
       "11. Kiwi       - R$ 13.00\n"
       "12. Morango    - R$ 12.00\n"
       "13. Abacate    - R$ 8.50\n"
       "14. Limao      - R$ 2.50\n"
       "15. Coco       - R$ 7.50\n"
       "16. Caju       - R$ 15.00\n"
       "17. Jabuticaba - R$ 18.00\n"
       "18. Acai       - R$ 22.00\n"
       "19. Carambola  - R$ 9.00\n"
       "20. Maracuja   - R$ 10.00\n"
       "0. Sair\n"
       "Digite a opcao: ");
        scanf("%d", &escolha);

        if (escolha >= 1 && escolha <= 20) 
        {
            printf("Quantas voce deseja? ");
            scanf("%d", &quantidade_frutas[escolha - 1]);
        }
    } while (escolha != 0);
    
    // Pergunta se o usuário deseja usar um cupom
    printf("Deseja usar um cupom? (1-SIM, 2-NAO): ");
    scanf("%d", &escolha);
    
    if (escolha == 1) 
    {
        // Chama a função do menu de cupons e passa o valor total
        menu_cupom(&valor_total, cupomValor);
    }

    // Cálculo do valor total
    printf("\nNota Fiscal:\n");
    printf("-----------------------------------------------------------------\n");
    printf("Produto       | Quantidade | Preco Unitario |   Total | Desconto |\n");
    printf("-----------------------------------------------------------------\n");

    //Pega todos os dados para colocar na nota fiscal
    for (int i = 0; i < 20; i++) 
    {
        if (quantidade_frutas[i] > 0) 
        {
            float total_fruta = quantidade_frutas[i] * frutas[i].preco;
            printf("%-15s | %10d | R$ %-12.2f | R$ %.2f | R$ %.2f\n", frutas[i].nome, quantidade_frutas[i], frutas[i].preco, total_fruta, valor_total);
            valor_total += total_fruta; // Adiciona ao valor total
        }
    }

    printf("-----------------------------------------------------------------\n");
    printf("Valor Total da Compra: R$ %.2f\n", valor_total); //apos o desconto ou não.
    printf("-----------------------------------------------------------------\n");
    return 1;
}