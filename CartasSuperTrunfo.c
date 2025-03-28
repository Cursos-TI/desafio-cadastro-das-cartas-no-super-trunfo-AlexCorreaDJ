/**
 * Programa: Cadastro de Cartas Super Trunfo
 * Autor: [Alex Correa Gomes]
 * Descrição: Este programa cadastra cartas para um jogo do tipo Super Trunfo,
 * onde cada carta representa uma cidade com atributos como população, área, PIB e pontos turísticos.
 * Agora também calcula a densidade populacional e o PIB per capita.
 */

 #include <stdio.h>
 #include <string.h>
 
 typedef struct {
     char estado[3];
     char codigo[3];
     char nome[100];
     unsigned long int populacao;
     float area;
     float pib;
     int pontosTuristicos;
     float densidadePopulacional;
     float pibPerCapita;
     float superPoder;
 } Carta;
 
 void calcularAtributos(Carta* c) {
     // Calculando a densidade populacional (população / área)
     if (c->area > 0) {
         c->densidadePopulacional = c->populacao / c->area;
     } else {
         c->densidadePopulacional = 0;
     }
 
     // Calculando PIB per capita (PIB / população)
     if (c->populacao > 0) {
         c->pibPerCapita = c->pib / c->populacao;
     } else {
         c->pibPerCapita = 0;
     }
 
     // Calculando o super poder
     float densidadeAjustada = (c->densidadePopulacional > 0) ? (1 / c->densidadePopulacional) : 0;
     c->superPoder = c->populacao + c->area + c->pib + c->pontosTuristicos + densidadeAjustada;
 }
 
 void exibirCarta(Carta c) {
     printf("\nCarta - %s %s\n", c.estado, c.codigo);
     printf("Nome da Cidade: %s\n", c.nome);
     printf("População: %lu habitantes\n", c.populacao);
     printf("Área: %.2f km²\n", c.area);
     printf("PIB: %.2f bilhões\n", c.pib);
     printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
     printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
     printf("PIB per Capita: %.2f reais\n", c.pibPerCapita);
     printf("Super Poder: %.2f\n", c.superPoder);
 }
 
 int comparar(int v1, int v2, int inverso) {
     if (inverso) {
         return (v1 < v2) ? 1 : 0; // Para densidade, menor é melhor
     }
     return (v1 > v2) ? 1 : 0; // Para outros atributos, maior é melhor
 }
 
 int compararFloat(float v1, float v2, int inverso) {
     if (inverso) {
         return (v1 < v2) ? 1 : 0;
     }
     return (v1 > v2) ? 1 : 0;
 }
 
 void compararCartas(Carta c1, Carta c2) {
     printf("\nComparação entre as cartas:\n");
 
     // Comparação de População
     printf("População: %d\n", comparar(c1.populacao, c2.populacao, 0));
 
     // Comparação de Área
     printf("Área: %d\n", comparar(c1.area, c2.area, 0));
 
     // Comparação de PIB
     printf("PIB: %d\n", comparar(c1.pib, c2.pib, 0));
 
     // Comparação de Pontos Turísticos
     printf("Pontos Turísticos: %d\n", comparar(c1.pontosTuristicos, c2.pontosTuristicos, 0));
 
     // Comparação de Densidade Populacional (inverso)
     printf("Densidade Populacional: %d\n", compararFloat(c1.densidadePopulacional, c2.densidadePopulacional, 1));
 
     // Comparação de PIB per Capita
     printf("PIB per Capita: %d\n", compararFloat(c1.pibPerCapita, c2.pibPerCapita, 0));
 
     // Comparação de Super Poder
     printf("Super Poder: %d\n", compararFloat(c1.superPoder, c2.superPoder, 0));
 }
 
 int main() {
     Carta carta1, carta2;
 
     // Entrada para a carta 1
     printf("Digite os dados para a primeira carta:\n");
     printf("Estado (2 caracteres): ");
     fgets(carta1.estado, 3, stdin); // lê o estado
     getchar(); // Limpa o buffer do teclado
 
     printf("Código (2 caracteres): ");
     fgets(carta1.codigo, 3, stdin); // lê o código
     getchar(); // Limpa o buffer do teclado
 
     printf("Nome da Cidade: ");
     fgets(carta1.nome, 100, stdin); // lê o nome da cidade
     carta1.nome[strcspn(carta1.nome, "\n")] = '\0'; // Remove a quebra de linha
 
     printf("População: ");
     scanf("%lu", &carta1.populacao); // lê a população (long unsigned int)
 
     printf("Área (em km²): ");
     scanf("%f", &carta1.area); // lê a área
 
     printf("PIB (em bilhões): ");
     scanf("%f", &carta1.pib); // lê o PIB
 
     printf("Pontos Turísticos: ");
     scanf("%d", &carta1.pontosTuristicos); // lê os pontos turísticos
     getchar(); // Limpa o buffer do teclado
 
     calcularAtributos(&carta1); // Calcula os atributos da carta 1
 
     // Entrada para a carta 2
     printf("\nDigite os dados para a segunda carta:\n");
     printf("Estado (2 caracteres): ");
     fgets(carta2.estado, 3, stdin);
     getchar(); // Limpa o buffer do teclado
 
     printf("Código (2 caracteres): ");
     fgets(carta2.codigo, 3, stdin);
     getchar(); // Limpa o buffer do teclado
 
     printf("Nome da Cidade: ");
     fgets(carta2.nome, 100, stdin);
     carta2.nome[strcspn(carta2.nome, "\n")] = '\0'; // Remove a quebra de linha
 
     printf("População: ");
     scanf("%lu", &carta2.populacao);
 
     printf("Área (em km²): ");
     scanf("%f", &carta2.area);
 
     printf("PIB (em bilhões): ");
     scanf("%f", &carta2.pib);
 
     printf("Pontos Turísticos: ");
     scanf("%d", &carta2.pontosTuristicos);
     getchar(); // Limpa o buffer do teclado
 
     calcularAtributos(&carta2); // Calcula os atributos da carta 2
 
     // Exibe as cartas e realiza a comparação
     exibirCarta(carta1);
     exibirCarta(carta2);
 
     compararCartas(carta1, carta2);
 
     return 0;
 }
 