#include <stdio.h>

int main() {
    // Definicoes de tipo
    typedef unsigned long int PopulacaoType;

    // Variaveis para a Carta 1
    char estado1;
    char codigo1[4];
    char nome_cidade1[50];
    PopulacaoType populacao1; // unsigned long int
    float area1;
    float pib1; // em bilhoes de reais
    int pontos_turisticos1;

    // Variaveis Calculadas para a Carta 1
    float densidade_populacional1;
    float pib_per_capita1;
    float super_poder1; // Nova variavel

    // Variaveis para a Carta 2
    char estado2;
    char codigo2[4];
    char nome_cidade2[50];
    PopulacaoType populacao2; // unsigned long int
    float area2;
    float pib2; // em bilhoes de reais
    int pontos_turisticos2;

    // Variaveis Calculadas para a Carta 2
    float densidade_populacional2;
    float pib_per_capita2;
    float super_poder2; // Nova variavel

    // Variaveis para o Resultado da Comparacao (0 ou 1)
    int vence_populacao;
    int vence_area;
    int vence_pib;
    int vence_pontos;
    int vence_densidade;
    int vence_pib_capita;
    int vence_super_poder;


    // LEITURA DOS DADOS 
    
    // CADASTRO DA CARTA 1
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", nome_cidade1);
    printf("Populacao (unsigned long int): ");
    scanf("%lu", &populacao1); // Uso de %lu para unsigned long int
    printf("Area (em km2): ");
    scanf("%f", &area1);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos1);
    
    // CALCULO DA CARTA 1
    densidade_populacional1 = (float)populacao1 / area1;
    // (PIB * 1 bilhao) / populacao
    pib_per_capita1 = (pib1 * 1000000000.0f) / (float)populacao1;

    // CALCULO DO SUPER PODER 1
    // Atributos numericos (Pop + Area + PIB + Pontos + PIB per Capita + (1 / Densidade))
    super_poder1 = (float)populacao1 + area1 + pib1 + (float)pontos_turisticos1 + pib_per_capita1 + (1.0f / densidade_populacional1);
    
    printf("\n");

    // CADASTRO DA CARTA 2 
    printf("--- Cadastro da Carta 2 ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", nome_cidade2);
    printf("Populacao (unsigned long int): ");
    scanf("%lu", &populacao2); // Uso de %lu para unsigned long int
    printf("Area (em km2): ");
    scanf("%f", &area2);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos2);

    // CALCULO DA CARTA 2
    densidade_populacional2 = (float)populacao2 / area2;
    // (PIB * 1 bilhao) / populacao
    pib_per_capita2 = (pib2 * 1000000000.0f) / (float)populacao2;

    // CALCULO DO SUPER PODER 2
    // Atributos numericos (Pop + Area + PIB + Pontos + PIB per Capita + (1 / Densidade))
    super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontos_turisticos2 + pib_per_capita2 + (1.0f / densidade_populacional2);


    // EXIBICAO DOS CALCULOS

    printf("\n--- Resultados dos Calculos ---\n");
    
    printf("Carta 1 - Densidade: %.2f hab/km2 | PIB per Capita: %.2f reais | Super Poder: %.2f\n", 
           densidade_populacional1, pib_per_capita1, super_poder1);
           
    printf("Carta 2 - Densidade: %.2f hab/km2 | PIB per Capita: %.2f reais | Super Poder: %.2f\n", 
           densidade_populacional2, pib_per_capita2, super_poder2);

    printf("\n");


    // COMPARACAO E RESULTADOS 
    
    // Comparação: Carta 1 vence (1) se for MAIOR, exceto para Densidade.
    
    // População (MAIOR vence)
    vence_populacao = (populacao1 > populacao2);
    
    // Área (MAIOR vence)
    vence_area = (area1 > area2);
    
    // PIB (MAIOR vence)
    vence_pib = (pib1 > pib2);
    
    // Pontos Turísticos (MAIOR vence)
    vence_pontos = (pontos_turisticos1 > pontos_turisticos2);
    
    // Densidade Populacional (MENOR vence) - O inverso da logica
    vence_densidade = (densidade_populacional1 < densidade_populacional2);

    // PIB per Capita (MAIOR vence)
    vence_pib_capita = (pib_per_capita1 > pib_per_capita2);

    // Super Poder (MAIOR vence)
    vence_super_poder = (super_poder1 > super_poder2);

    
    // EXIBICAO DOS RESULTADOS FINAIS
    printf("Comparacao de Cartas:\n");
    printf("População: %s venceu (%d)\n", 
           vence_populacao ? "Carta 1" : "Carta 2", vence_populacao);
           
    printf("Área: %s venceu (%d)\n", 
           vence_area ? "Carta 1" : "Carta 2", vence_area);
           
    printf("PIB: %s venceu (%d)\n", 
           vence_pib ? "Carta 1" : "Carta 2", vence_pib);
           
    printf("Pontos Turísticos: %s venceu (%d)\n", 
           vence_pontos ? "Carta 1" : "Carta 2", vence_pontos);
           
    printf("Densidade Populacional: %s venceu (%d)\n", 
           vence_densidade ? "Carta 1" : "Carta 2", vence_densidade);
           
    printf("PIB per Capita: %s venceu (%d)\n", 
           vence_pib_capita ? "Carta 1" : "Carta 2", vence_pib_capita);
           
    printf("Super Poder: %s venceu (%d)\n", 
           vence_super_poder ? "Carta 1" : "Carta 2", vence_super_poder);

    return 0;
}