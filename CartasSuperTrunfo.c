/**
 * Programa: Cadastro de Cartas Super Trunfo
 * Autor: [Alex Correa Gomes]
 * Descrição: Este programa cadastra cartas para um jogo do tipo Super Trunfo,
 * onde cada carta representa uma cidade com atributos como população, área, PIB e pontos turísticos.
 * Agora também calcula a densidade populacional e o PIB per capita.
 */

 #include <stdio.h>

 // Definição da estrutura que representa uma carta do jogo
 struct Carta {
     char estado[3]; // Sigla do estado
     char codigo[4]; // Código identificador da cidade
     char nome[50];  // Nome da cidade
     int populacao;  // População da cidade
     float area;     // Área total da cidade em km²
     float pib;      // PIB da cidade em bilhões
     int pontos_turisticos; // Número de pontos turísticos
     float densidade_populacional;
     float pib_per_capita;
 };
 
 int main() {
     struct Carta cartas[2]; // Array para armazenar duas cartas
 
     // Cadastro das cartas
     for (int i = 0; i < 2; i++) {
         printf("\nCadastrar a carta %d:\n", i + 1);
         printf("Digite o estado da cidade (ex: SP): ");
         scanf("%2s", cartas[i].estado);
         printf("Digite o código da cidade (ex: A01): ");
         scanf("%3s", cartas[i].codigo);
         getchar(); // Consome o '\n' deixado pelo scanf anterior
         printf("Digite o nome da cidade: ");
         scanf(" %[^\n]", cartas[i].nome); // Le string com espaços corretamente
         printf("Digite a população: ");
         scanf("%d", &cartas[i].populacao);
         printf("Digite a área (em km²): ");
         scanf("%f", &cartas[i].area);
         printf("Digite o PIB (em bilhões): ");
         scanf("%f", &cartas[i].pib);
         printf("Digite o número de pontos turísticos: ");
         scanf("%d", &cartas[i].pontos_turisticos);
         
         // Cálculo da densidade populacional e PIB per capita
         cartas[i].densidade_populacional = cartas[i].populacao / cartas[i].area;
         cartas[i].pib_per_capita = (cartas[i].pib * 1e9) / cartas[i].populacao; // Convertendo PIB para reais
     }
 
     // Exibição dos dados cadastrados
     printf("\nCartas cadastradas:\n");
     for (int i = 0; i < 2; i++) {
         printf("\nCarta %d:\n", i + 1);
         printf("Estado: %s\n", cartas[i].estado);
         printf("Código: %s\n", cartas[i].codigo);
         printf("Nome da Cidade: %s\n", cartas[i].nome);
         printf("População: %d habitantes\n", cartas[i].populacao);
         printf("Área: %.2f km²\n", cartas[i].area);
         printf("PIB: %.2f bilhões\n", cartas[i].pib);
         printf("Número de Pontos Turísticos: %d\n", cartas[i].pontos_turisticos);
         printf("Densidade Populacional: %.2f hab/km²\n", cartas[i].densidade_populacional);
         printf("PIB per Capita: %.2f reais\n", cartas[i].pib_per_capita);
     }
 
     return 0;
 }
 