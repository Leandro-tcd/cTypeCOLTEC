#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define SUCESSO 0
#define TAMANHO_DA_COLUNA 5
#define TAMANHO_DA_LINHA 5
#define INICIODAMATRIZ 0
#define QUANTIDADE_DE_LOJA 7
#define QUANTIDADE_DE_PRODUTO 5
#define INICIOVARIAVEL 9478154715
#define INICIOVARCONTADOR 0

// Menu principal de questões
void imprimeMenuDeQuestoes(void) {
	printf("As Questoes dessa semana foram:\n");
	printf("[1] para fornecer uma matriz 5x5 e imprimir sua transposta\n");
	printf("[2] para somar os elementos de uma matriz de tamanho qualquer\n");
	printf("[3] para multiplicar um vetor com 5 dimensoes por uma matriz quadrada 5x5\n");
	printf("[4] para informar a quantidade de 5 produtos presentes em 7 lojas distintas.\n");
	printf("[0] para sair.\n");
}
// Função para separar menus pós finalização da questão
void separaMenu(void) {
	printf("\n");
	printf("===================================================================================");
	printf("\n");
}
// Exercício 01 - Ler matriz e imprimir transposta
void exercicio01(void) {
	float entradaDoUsuario[TAMANHO_DA_LINHA][TAMANHO_DA_COLUNA];
	uint16_t i, j; // i == linhas e j == colunas
	printf("A matriz a ser informada eh uma matriz quadrada do tipo 5x5.\n");
	printf("Ela sera preenchida linha a linha, da esquerda para direita.\n");
	printf("nesse caso, atente-se as posicoes informadas a seguir:\n");
	for (i = INICIODAMATRIZ; i < TAMANHO_DA_LINHA; i++) {
		for (j = INICIODAMATRIZ; j < TAMANHO_DA_COLUNA; j++) {
			printf("Por favor, informe o valor para as posicoes da linha [%hhd] e coluna [%hhd] da matriz: ", i, j);
			scanf("%f", &entradaDoUsuario[i][j]);
		}
	}
	//Para fazer a transposta, ou seja, para imprimir o que era coluna no lugar das linhas
	printf("\n");
	printf("A transposta da matriz informada eh:\n");
	for (i = INICIODAMATRIZ; i < TAMANHO_DA_COLUNA; i++) {
		for (j = INICIODAMATRIZ; j < TAMANHO_DA_LINHA; j++) {
				printf("%.2f \t", entradaDoUsuario[j][i]);
				if (j == (TAMANHO_DA_LINHA - 1)) {
					printf("\n");
			}
		}
	}
}
// Exercício 02 - Ler matriz e imprimir soma dos elementos
void exercicio02(void) {
	float soma, entradaDoUsuario[TAMANHO_DA_LINHA][TAMANHO_DA_COLUNA];
	uint8_t i, j; // i == linhas, j == colunas
	
	printf("A matriz a ser informada eh uma matriz quadrada do tipo 5x5.\n"); 
	printf("Ela sera preenchida linha a linha, da esquerda para direita.\n");
	printf("nesse caso, atente-se as posicoes informadas a seguir:\n");
	
	soma = INICIOVARCONTADOR;
	for (i = INICIODAMATRIZ; i < TAMANHO_DA_LINHA; i++) {
		for (j = INICIODAMATRIZ; j < TAMANHO_DA_COLUNA; j++) {
			printf("Por favor, informe o valor para as posicoes da linha [%hhd] e coluna [%hhd] da matriz: ", i, j);
			scanf("%f", &entradaDoUsuario[i][j]);
			soma += entradaDoUsuario[i][j];
		}
	}
	printf("\n");
	printf("A soma de todos os elementos da matriz informada eh: %.2f", soma);
}
// Exercício 03 - Ler matriz e vetor e imprimir o produto deles
void exercicio03(void) {
	uint8_t i, j, k; // i == linhas, j == colunas, k == vetor
	float entradaDoUsuarioMatriz[TAMANHO_DA_LINHA][TAMANHO_DA_COLUNA], entradaDoUsuarioVetor[TAMANHO_DA_LINHA];
	// Informar o Vetor
	for (k = INICIODAMATRIZ; k < TAMANHO_DA_LINHA; k++) {
		printf("Por favor, digite um valor para a posicao %hhd do vetor: ", k);
		scanf("%f", &entradaDoUsuarioVetor[k]);
	}
	
	// Informar a Matriz
	printf("\n");
	printf("A matriz a ser informada eh uma matriz quadrada do tipo 5x5.\n");
	printf("Ela sera preenchida linha a linha, da esquerda para direita.\n");
	printf("nesse caso, atente-se as posicoes informadas a seguir:\n");
	for (i = INICIODAMATRIZ; i < TAMANHO_DA_LINHA; i++) {
		for (j = INICIODAMATRIZ; j < TAMANHO_DA_COLUNA; j++) {
			printf("Por favor, informe o valor para as posicoes da linha [%hhd] e coluna [%hhd] da matriz: ", i, j);
			scanf("%f", &entradaDoUsuarioMatriz[i][j]);
			entradaDoUsuarioMatriz[i][j] *= entradaDoUsuarioVetor[j];
		}
	}
	// Imprimir a matriz
	printf("\n");
	printf("O produto da matriz informada pelo vetor eh:\n");
	for (i = INICIODAMATRIZ; i < TAMANHO_DA_COLUNA; i++) {
		for (j = INICIODAMATRIZ; j < TAMANHO_DA_LINHA; j++) {
			printf("%.2f \t", entradaDoUsuarioMatriz[j][i]);
			if (j == (TAMANHO_DA_LINHA - 1)) {
				printf("\n");
			}
		}
	}

}
// Exercício 04 - Ler quantidade de produtos por loja 
// e imprimir quantidade de produtos por loja e a que tem menos produto
void exercicio04(void) {
	uint8_t i, j, indiceLoja;
	uint64_t entradaUsuario[QUANTIDADE_DE_LOJA][QUANTIDADE_DE_PRODUTO], somaProduto, lojaComMenosProdutos;
	lojaComMenosProdutos = INICIOVARIAVEL;
	somaProduto = INICIOVARCONTADOR;
	for (i = INICIODAMATRIZ; i < QUANTIDADE_DE_LOJA; i++) {
		for (j = INICIODAMATRIZ; j < QUANTIDADE_DE_PRODUTO; j++) {
			printf("Por favor, informe a quantidade de items que a loja [%hhd], possui do produto [%hhd]:", i, j);
			scanf("%lld", &entradaUsuario[i][j]);
		}
	}
	for (i = INICIODAMATRIZ; i < QUANTIDADE_DE_LOJA; i++) {
		for (j = INICIODAMATRIZ; j < QUANTIDADE_DE_PRODUTO; j++) {
			somaProduto += entradaUsuario[i][j];
			if (j == (QUANTIDADE_DE_PRODUTO - 1) && (somaProduto < lojaComMenosProdutos)) {
				lojaComMenosProdutos = somaProduto;
				indiceLoja = i;
			}
		}

	}
	printf("\n");
	for (i = INICIODAMATRIZ; i < QUANTIDADE_DE_LOJA; i++) {
		for (j = INICIODAMATRIZ; j < QUANTIDADE_DE_PRODUTO; j++) {
			printf("Loja [%hhd]: %lld itens do produto [%hhd]\t", i, entradaUsuario[i][j], j);
			if ((j % 2 == 0) && (j != 0)) {
				printf("\n");
			} 
			if (j == (QUANTIDADE_DE_PRODUTO - 1)) {
					printf("\n");
					printf("\n");
			}
		}
	}
	printf("\n");
	printf("Segundo os dados informados, a loja que possui menos produtos eh a de numero [%hhd], com um total de %lld items", indiceLoja, lojaComMenosProdutos);
	separaMenu();
}
// Função principal de chamada de questões
int main(int argc, char ** argv) {
	uint8_t exercicio;
	do {
		imprimeMenuDeQuestoes();
		printf("Por favor, informe o numero do exercicio com base no menu acima: ");
		scanf("%hhd", &exercicio);
		printf("\n");
		
		switch (exercicio) {
		case 0: {
			break;
		}
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
		default: {
			printf("\n");
			printf("ERROR! O numero informado nao corresponde a nenhuma das questoes disponiveis. Por favor tente novamente.\n");
		}
		}
		separaMenu();
	} while (exercicio != 0);
	return SUCESSO;
}