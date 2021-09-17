#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Devo chamar a variável que tem o ** que corresponde a matriz

#define SUCESSO 0
#define INICIAINDC 0
#define INICIAVARIAVEL 214746153

//Função para exibir o menu de questões 
void imprimeMenu(void) {
	printf("Os exercicios destinados para essa semana foram\n");
	printf("[1] para informar o tamanho do vetor e retornar um ponteiro\n");
	printf("[2] para informar o tamanho da matriz e retornar um ponteiro\n");
	printf("[3] para informar o tamanho do vetor e calcular a média\n");
	printf("[4] para informar o tamanho e ler o vetor para obter o menor valor existente\n");
	printf("[5] para informar uma matriz e obter a soma dos elementos\n");
	printf("[6] para informar uma quantidade X de produtos para uma quantidade Y de lojas\n");
	printf("[0] para Sair.\n");
}
//Função para indicar que as linhas são as lojas e as colunas são os produtos
void imprimeMenuLoja(void) {
	printf("\n");
	printf("Considere a quantidade de lojas sendo o numero de linhas da matriz\n");
	printf("E a quantidade de colunas igual a quantidade de itens de um produto \n");
}
//Função para separar um novo menu
void separaMenu(void) {
	printf("\n");
	printf("===========================================================================================");
	printf("\n");
}
//Função para obter o numero de Linhas do Vetor/Matriz
uint16_t tamanhoDoVetorLinha(void) {
	uint16_t entradaUsuarioVetorLinha;
	printf("Por favor, informe o tamanho da Linha do Vetor/Matriz que deseja criar: ");
	scanf("%hd", &entradaUsuarioVetorLinha);
	return entradaUsuarioVetorLinha;
}
//Função para obter o numero de Colunas do Vetor/Matriz
uint16_t tamanhoDoVetorColuna(void) {
	uint16_t entradaUsuarioVetorColuna;
	printf("Por favor, infrome a quantidade de colunas que formam a sua matriz: ");
	scanf("%hd", &entradaUsuarioVetorColuna);
	return entradaUsuarioVetorColuna;
}
//Função para alocar as Linhas da Matriz
int** alocaLinhasMatriz(quantidadeDeLinhas) {
	return (int**) malloc(quantidadeDeLinhas * sizeof(int));
}
//Função para alocar as colunas da Matriz
int** alocaColunas(uint16_t quantidadeDeColunas, int** linhasAlocadas) {
	uint16_t i;
	for (i = 0; i < quantidadeDeColunas; i++) {
		 linhasAlocadas[i] = (int*)malloc(quantidadeDeColunas * sizeof(int));
	}
	return linhasAlocadas;
}
//Função para alocar as linhas de uma Matriz de números reais
float** alocaLinhasMatrizFloat(quantidadeDeLinhas) {
	return (float**)malloc(quantidadeDeLinhas * sizeof(float));
}
//Função para alocar as colunas para uma Matriz de números reais
float** alocaColunasFloat(uint16_t quantidadeDeColunas, float** linhasAlocadas) {
	uint16_t i;
	for (i = 0; i < quantidadeDeColunas; i++) {
		linhasAlocadas[i] = (float*)malloc(quantidadeDeColunas * sizeof(float));
	}
	return linhasAlocadas;
}
//Função para liberar primeiro as colunas de uma matriz
void liberaMemoriaDasColunas(int** quantidadeDeLinhas) {
	uint16_t i, quantidadeDeColunas;

	printf("Por favor, informe a quantidade de colunas que deseja liberar: ");
	scanf("%hd", &quantidadeDeColunas);
	
	for (i = 0; i < quantidadeDeColunas; i++) {
		free(quantidadeDeLinhas[i]);
	}
}
//Função para liberar as colunas de uma Matriz de números reais
void liberaMemoriaDasColunasFloat(uint16_t quantidadeDeColunas, float** quantidadeDeLinhas) {
	uint16_t i;
	for (i = 0; i < quantidadeDeColunas; i++) {
		free(quantidadeDeLinhas[i]);
	}
}
//Função para liberar as linhas de um Vetor
void liberaMemoriaDasLinhasDoVetor(int* quantidadeDeLinhas) {
	free(quantidadeDeLinhas);
}
//Função para liberar as linhas de um Vetor para numeros reais
void liberaMemoriaDasLinhasDoVetorFloat(float* quantidadeDeLinhas) {
	free(quantidadeDeLinhas);
}
//Função para liberar as linhas de uma Matriz
void liberaMemoriaDasLinhasDeMatriz(int** quantidadeDeLinhas) {
	free(quantidadeDeLinhas);
}
//Função para liberar as linhas de uma Matriz com valores reais
void liberaMemoriaDasLinhasDeMatrizFloat(float** quantidadeDeLinhas) {
	free(quantidadeDeLinhas);
}
//Função para executar o exercício 01 - Alocar a memória para um vetor e retornar o endereço
int* exercicio01(void) {
	uint16_t quantidadeDeLinhasDoVetor;
	quantidadeDeLinhasDoVetor = tamanhoDoVetorLinha();
	return (int*)malloc(quantidadeDeLinhasDoVetor * sizeof(int));
}
//Função para executar o exercício 02 - Formar uma matriz passando numero de linhas e colunas
int** exercicio02(void) {
	uint16_t quantidadeDeLinhasDaMatriz, quantidadeDeColunasDaMatriz;
	int** linhasParaMatriz;
	int** matrizCompleta;
	
	quantidadeDeLinhasDaMatriz = tamanhoDoVetorLinha();
	quantidadeDeColunasDaMatriz = tamanhoDoVetorColuna();
	linhasParaMatriz = alocaLinhasMatriz(quantidadeDeLinhasDaMatriz);
	
	matrizCompleta = alocaColunas(quantidadeDeColunasDaMatriz, linhasParaMatriz);
	
	return matrizCompleta;
}
//Função para executar o exercício 03 - Forma um vetor e faz a média aritmética dos elementos dele
void exercicio03(void) {
	uint16_t i, quantidadeDeLinhasDoVetor;
	float soma = INICIAINDC;
	double mediaAri;
	float* vetorAlocado;

	quantidadeDeLinhasDoVetor = tamanhoDoVetorLinha();
	vetorAlocado = (float*)malloc(quantidadeDeLinhasDoVetor * sizeof(float));
	
	printf("Por favor, informe os numeros para o preenchimento do vetor\n");
	for (i = INICIAINDC; i < quantidadeDeLinhasDoVetor; i++) {
		printf("Digite o numero: ");
		scanf("%f", &vetorAlocado[i]);
		soma += vetorAlocado[i];
	}
	mediaAri = ((soma * 1.0) / quantidadeDeLinhasDoVetor);
	printf("A média aritmetica de todos os numeros informados na construcao do vetor foi de: %f", mediaAri);
	liberaMemoriaDasLinhasDoVetorFloat(vetorAlocado);
}
/*Função para executar o exercício 04 - Forma um vetor 
Identifica o menor e o maior valor inserido ao longo do preenchimento*/
void exercicio04(void) {
	uint16_t i, quantidadeDeLinhasDoVetor;
	double menorValor = INICIAVARIAVEL * 1.0;
	double maiorValor = INICIAINDC;
	float* vetorAlocado;

	quantidadeDeLinhasDoVetor = tamanhoDoVetorLinha();
	vetorAlocado = (float*)malloc(quantidadeDeLinhasDoVetor * sizeof(float));

	printf("Por favor, informe os numeros para o preenchimento do vetor\n");
	for (i = INICIAINDC; i < quantidadeDeLinhasDoVetor; i++) {
		printf("Digite o numero: ");
		scanf("%f", &vetorAlocado[i]);
		if (vetorAlocado[i] < menorValor) {
			menorValor = vetorAlocado[i];
		}
		if (vetorAlocado[i] > maiorValor) {
			maiorValor = vetorAlocado[i];
		}
	}
	printf("O menor e o maior valor informado ao longo do preenchimento do vetor foram respectivamente: [%.2lf], [%.2lf]", menorValor, maiorValor);
	liberaMemoriaDasLinhasDoVetorFloat(vetorAlocado);
}
//Função para executar o exercício 05 - Aloca e soma os elementos de uma matriz
void exercicio05(void) {
	uint16_t quantidadeDeLinhasDaMatriz, quantidadeDeColunasDaMatriz, i, j;
	float** linhasParaMatriz;
	float** matrizCompleta;
	float soma = INICIAINDC;
	quantidadeDeLinhasDaMatriz = tamanhoDoVetorLinha();
	quantidadeDeColunasDaMatriz = tamanhoDoVetorColuna();
	linhasParaMatriz = alocaLinhasMatrizFloat(quantidadeDeLinhasDaMatriz);
	matrizCompleta = alocaColunasFloat(quantidadeDeColunasDaMatriz, linhasParaMatriz);
	for (i = INICIAINDC; i < quantidadeDeLinhasDaMatriz; i++) {
		for (j = INICIAINDC; j < quantidadeDeColunasDaMatriz; j++) {
			printf("Por favor, informe o valor para a posicao [%d,%d] da matriz:", i, j);
			scanf("%f", &matrizCompleta[i][j]);
			soma += matrizCompleta[i][j];
		}
	}
	printf("A soma de todos os elementos que constitui a matriz informada eh: %.2f", soma);
	liberaMemoriaDasColunasFloat(quantidadeDeColunasDaMatriz, matrizCompleta);
	liberaMemoriaDasLinhasDeMatrizFloat(matrizCompleta);
}
//Função para executar o exercício 06 - Organização de quantidade de produtos por loja 
void exercicio06(void) {
	uint16_t quantidadeDeLinhasDaMatriz, quantidadeDeColunasDaMatriz, i, j;
	uint16_t indiceDaLoja = INICIAINDC;
	int** linhasParaMatriz;
	int** matrizCompleta;
	uint32_t soma = INICIAINDC;
	uint32_t lojaComMenosProdutos = INICIAVARIAVEL;

	quantidadeDeLinhasDaMatriz = tamanhoDoVetorLinha();
	quantidadeDeColunasDaMatriz = tamanhoDoVetorColuna();
	linhasParaMatriz = alocaLinhasMatriz(quantidadeDeLinhasDaMatriz);
	matrizCompleta = alocaColunas(quantidadeDeColunasDaMatriz, linhasParaMatriz);
	
	for (i = INICIAINDC; i < quantidadeDeLinhasDaMatriz; i++) {
		for (j = INICIAINDC; j < quantidadeDeColunasDaMatriz; j++) {
			printf("Por favor, informe a quantidade de itens do produto %d para a loja %d: ", j, i);
			scanf("%d", &matrizCompleta[i][j]);
			soma += matrizCompleta[i][j];
			if ((j == (quantidadeDeColunasDaMatriz-1)) && (soma < lojaComMenosProdutos)) {
				lojaComMenosProdutos = soma;
				indiceDaLoja = i;
			}
		}
		soma = INICIAINDC;
	}
	for (i = INICIAINDC; i < quantidadeDeLinhasDaMatriz; i++) {
		for (j = INICIAINDC; j < quantidadeDeColunasDaMatriz; j++) {
			printf("A loja %d \t possui %d unidades \t do item %d \t \n", i, matrizCompleta[i][j], j);
		}
	}
	printf("\n");
	printf("A loja que possui a menor quantidade de itens eh a %d, com um total de %d", indiceDaLoja, lojaComMenosProdutos);
	liberaMemoriaDasColunasFloat(quantidadeDeColunasDaMatriz, (float**)matrizCompleta);
	liberaMemoriaDasLinhasDeMatriz(matrizCompleta);
}
//Função de chamada principal, contém as opções de chamadas de função para cada exercicio
int main(int argc, char** argv) {
	uint8_t exercicio;
	int* resultadoVetor;
	int** resultadoMatriz;
	do {

		imprimeMenu();
		printf("Por favor, informe o numero com base no menu informado acima: ");
		scanf("%hhd", &exercicio);
	
		switch (exercicio) {
		case 0: {
			break;
		}
		case 1: {
			resultadoVetor = exercicio01();
			liberaMemoriaDasLinhasDoVetor(resultadoVetor);
			separaMenu();
			break;
		}
		case 2: {
			resultadoMatriz = exercicio02();
			liberaMemoriaDasColunas(resultadoMatriz);
			liberaMemoriaDasLinhasDeMatriz(resultadoMatriz);
			separaMenu();
			break;
		}
		case 3: {
			exercicio03();
			separaMenu();
			break;
		}
		case 4: {
			exercicio04();
			separaMenu();
			break;
		}
		case 5: {
			exercicio05();
			separaMenu();
			break;
		}
		case 6: {
			imprimeMenuLoja();
			exercicio06();
			separaMenu();
			break;
		}
		default: {
			printf("\n");
			printf("ERROR! O numero informado nao corresponde a nenhum dos exercicios demonstrados acima, por favor, tente novamente.");
		}
		}
		separaMenu();
	} while (exercicio != 0);

	return SUCESSO;
}
