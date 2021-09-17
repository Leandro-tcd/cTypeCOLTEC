#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// getchar(); para capturar o \n do scanf
#define TAMANHO_MAXIMO_DO_VETOR (1000 + 1)
#define SUCESSO 0
#define INICIARINDC 0
#define caracteres 1000
#define VERDADEIRO (1 == 1)
#define FALSO (!VERDADEIRO)

//Função para exibir o menu de exercícios da semana
void menuDeExercicios(void) {
	printf("Os exercicios solicitados para essa semana foram: \n");
	printf("[1] para contar o numero de espacos em branco de uma frase\n");
	printf("[2] para visualizar uma frase sem a utilizacao de espacos\n");
	printf("[3] para contar o numero de vogais em uma palavra\n");
	printf("[4] para colocar em maiusculo, as primeiras letras de cada palavra presente uma frase\n");
	printf("[5] para identificar se a palavra eh um palindromo\n");
	printf("[6] para identificar se uma frase eh um palindromo\n");
	printf("[0] para Sair\n");
}
//Função para separar os menus após a execução das questões
void separaQuestoes(void) {
	printf("\n");
	printf("########################################################################################");
	printf("\n");
}
// Exercício 01 - Contador de espaços
void exercicio01(void) {
	uint16_t i, tamanhoDaEntrada;
	uint8_t	contador;
	char entradaDoUsuario[TAMANHO_MAXIMO_DO_VETOR];
	contador = 0;
	
	getchar();
	
	printf("Para que seja possivel contar os espacos que separam as palavras, por favor digite uma frase com ate %hd caracteres \n", caracteres);
	printf("Digite aqui sua frase:");
	fgets(entradaDoUsuario, TAMANHO_MAXIMO_DO_VETOR, stdin);
	
	tamanhoDaEntrada = (uint16_t) strlen(entradaDoUsuario);
		for (i = 0; i <= tamanhoDaEntrada; i++) {
			if (entradaDoUsuario[i] == ' ') {
				contador++;
			}
		}
		printf("\n");
		printf("A frase informada utiliza %d, espacos para separar as palavras", contador);
		separaQuestoes();
}
// Exercício 02 - Sem espaços
void exercicio02(void) {
	uint16_t i, tamanhoDaEntrada;
	char entradaDoUsuario[TAMANHO_MAXIMO_DO_VETOR];
	
	getchar();
	
	printf("Para reescrever uma frase sem a utilizacao de espacos entre as palavras, digite uma frase com ate %hd caracteres\n", caracteres);
	printf("Digite aqui sua frase:");
	fgets(entradaDoUsuario, TAMANHO_MAXIMO_DO_VETOR, stdin);
	
	tamanhoDaEntrada = (uint16_t) strlen(entradaDoUsuario);
	for (i = 0; i <= tamanhoDaEntrada; i++) {
		if (entradaDoUsuario[i] != ' ') {
			printf("%c", entradaDoUsuario[i]);
		}
		else {
			continue;
		}
	}
	separaQuestoes();
}
// Exercício 03 - Número de Vogais
void exercicio03(void) {
	uint16_t i, vogal = 0;
	char entradaDoUsuario[TAMANHO_MAXIMO_DO_VETOR];
	getchar();
	printf("Por favor, digite a palavra ou texto que deseja identificar o numero de vogais. Cuidado, o limite de caracteres eh: %d \n", caracteres);
	printf("Digite o Texto aqui: ");
	fgets(entradaDoUsuario, TAMANHO_MAXIMO_DO_VETOR, stdin);
	for (i = 0; i <= strlen(entradaDoUsuario); i++) {
		if (((int)entradaDoUsuario[i] == (int)'a') || ((int)entradaDoUsuario[i] == (int)'A') || ((int)entradaDoUsuario[i] == (int)'e') || ((int)entradaDoUsuario == (int)'E') || ((int)entradaDoUsuario[i] == (int)'i') || ((int)entradaDoUsuario[i] == (int)'I') || ((int)entradaDoUsuario[i] == (int)'o') || ((int)entradaDoUsuario[i] == (int)'O') || ((int)entradaDoUsuario[i] == (int)'u') || ((int)entradaDoUsuario[i] == (int)'U')) {
			vogal += 1;
		}
	}
	printf("A quantidade de vogais na palavra/texto informado eh: %hd", vogal);
}
// Exercício 04 - Primeira letra de cada palavra em maiúsculo
void exercicio04(void) {
	uint8_t espaco;
	uint16_t i;
	char entradaDoUsuario[TAMANHO_MAXIMO_DO_VETOR];
	getchar(); 
	printf("digite uma frase com ate %hd caracteres para transformar a primeira letra de cada palavra em maiuscula \n", caracteres);
	printf("Digite sua frase aqui:");
	fgets(entradaDoUsuario, TAMANHO_MAXIMO_DO_VETOR, stdin);
	espaco = FALSO;
	for (i = 0; i <= strlen(entradaDoUsuario); i++) {
		if ((entradaDoUsuario[i] != ' ')) {
			entradaDoUsuario[0] = toupper(entradaDoUsuario[0]);
			continue;
		}
		else {
			espaco = VERDADEIRO;
		}
		if (espaco == VERDADEIRO) {
			entradaDoUsuario[i+1] = toupper(entradaDoUsuario[i+1]);
			espaco = FALSO;
		}
	}
	printf("%s", entradaDoUsuario);
	separaQuestoes();
}
// Exercício 05 - Ver se uma palavra é palindromo
void exercicio05(void) {
	uint8_t palindromo = VERDADEIRO;
	char entradaDoUsuario[TAMANHO_MAXIMO_DO_VETOR]; 
	char* entradaNormal;
	char* entradaInvertida;
	
	getchar();
	printf("Para identificar se uma palavra eh palindromo, basta digitar ela abaixo. Cuidado, o limite maximo de caracteres eh de %hd \n", caracteres);
	printf("Digite sua palavra aqui:");
	
	entradaNormal = fgets(entradaDoUsuario, TAMANHO_MAXIMO_DO_VETOR, stdin);
	entradaInvertida = entradaNormal + strlen(entradaNormal) - 2;
	
	while (entradaNormal < entradaInvertida) {
		if (*entradaNormal != *entradaInvertida) {
			palindromo = FALSO;
			break;
		}
		entradaNormal++;
		entradaInvertida--;
	}
	if (palindromo == VERDADEIRO) {
		printf("A palavra informada eh classificada como um palindromo \n");
		separaQuestoes();
	}
	else {
		printf("A palavra informada NAO eh classificada como um palindromo \n");
		separaQuestoes();
	}
}
// Exercício 06 - Ver se uma frase é palindromo
void exercicio06(void) {
	uint8_t palindromo = VERDADEIRO;
	char entradaDoUsuario[TAMANHO_MAXIMO_DO_VETOR];
	char* entradaNormal;
	char* entradaInvertida;
	char auxiliar1, auxiliar2;

	getchar();

	printf("Se deseja saber se uma frase ou texto eh um palindromo basta digita-lo a seguir. Cuidado! o limite maximo de caracteres eh: %hd", caracteres);
	printf("Por favor, digite o texto aqui:");
	entradaNormal = fgets(entradaDoUsuario, TAMANHO_MAXIMO_DO_VETOR, stdin);

	entradaInvertida = entradaNormal + strlen(entradaNormal) - 2;

	while (entradaNormal < entradaInvertida) {

		// Identificar se o caractere é alphanumerico
		if (!isalnum(*entradaNormal)) {
			entradaNormal++;
			continue;
		}
		if (!isalnum(*entradaInvertida)) {
			entradaInvertida--;
			continue;
		}

		auxiliar1 = *entradaNormal;
		auxiliar2 = *entradaInvertida;

		if (islower(auxiliar1)) auxiliar1 -= 0x20;
		if (islower(auxiliar2)) auxiliar2 -= 0x20;

		if (auxiliar1 != auxiliar2) {
			palindromo = FALSO;
			break;
		}

		entradaNormal++;
		entradaInvertida--;
	}
	if (palindromo == VERDADEIRO) {
		printf("O texto informado eh um palindromo.\n");
		separaQuestoes();
	}
	else {
		printf("Desculpe, mas o texto informado NAO eh um palindromo.\n");
		separaQuestoes();
	}

}
// Função de inicialização do menu de questões
int main(int argc, char** argv) {
	uint8_t questoes;
	do {

		menuDeExercicios();
		printf("Por favor, digite um numero dado as opcoes acima: ");
		scanf("%hhd", &questoes);

		switch (questoes) {
		case 0: break;
		case 1: {
			exercicio01();
			break;
		}
		case 2: {
			exercicio02();
			break;
		}
		case 3: {
			exercicio03();
			break;
		}
		case 4: {
			exercicio04();
			break;
		}
		case 5: {
			exercicio05();
			break;
		}
		case 6: {
			exercicio06();
			break;
		}
		default: {
			printf("ERROR: Por favor, insira um numero que corresponde aos exercicios!");
		}
		}
	} while (questoes != 0);

	separaQuestoes();
	
	return SUCESSO;
}