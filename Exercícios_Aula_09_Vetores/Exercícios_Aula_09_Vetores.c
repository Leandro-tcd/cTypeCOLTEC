#include <stdio.h>
#include<stdint.h>

#define SUCESSO 0
#define INICIAINDC 0
#define TAMANHO_DO_VETOR_10 10 //Usado nas questões 02 e 03
#define TAMANHO_DO_VETOR_20 20 //Usado na questão 01
#define TAMANHO_MAXIMO_DO_VETOR 1000

//Função para imprimir o menu de questões
void imprimeMenuDeQuestoes(void) {
	printf("As questoes trabalhadas na aula dessa semana foram:\n");
	printf("[1] para inserir 20 valores e descubrir qual o menor\n");
	printf("[2] para multiplicar um vetor de 10 valores por um escalar\n");
	printf("[3] para calcular o produto escalar entre dois vetores\n");
	printf("[4] para calcular a media de um vetor linear com seu tamanho escolhido por voce (entre 1 a 1000)\n");
	printf("[0] para Sair.\n");
}

//Função para separar uma execução da outra
void separaQuestoes(void) {
	printf("\n");
	printf("####################################################################################");
	printf("\n");
}

//Exercício 01 - Identificar o menor número com seu indice
void exercicio01(void) {
	uint8_t i, indiceDoMenor;
	float vetorMenorNum[20], menorNum;
	menorNum = 982752486.0f;
	indiceDoMenor = 134;
	for (i = INICIAINDC; i < TAMANHO_DO_VETOR_20; i++) {
		printf("Por favor, digite o valor para a posicao %hhd: ", i);
		scanf("%f", &vetorMenorNum[i]);
		
		if (vetorMenorNum[i] < menorNum) {
			menorNum = vetorMenorNum[i];
			indiceDoMenor = i;
		}
	}
	printf("\nO menor numero digitado foi: %.3f com o indice %hhd", menorNum, indiceDoMenor);
	separaQuestoes();
}

//Exercicio 02 - Vetor x Escalar
void exercicio02(void) {
	uint8_t i;
	float vetorUsuario[10], vetorAuxiliar[10], escalar;
	printf("Por favor, digite inicialmente o valor do numero escalar para multiplicar o vetor: ");
	scanf("%f", &escalar);
	for (i = INICIAINDC; i < TAMANHO_DO_VETOR_10; i++) {
		printf("Por favor, digite o valor para a posicao %hhd: ", i);
		scanf("%f", &vetorUsuario[i]);
		vetorAuxiliar[i] = vetorUsuario[i] * escalar;

	}
	printf("Vetor informado \t  vezes \t eh iguao ao vetor:\n");
	for (i = INICIAINDC; i < TAMANHO_DO_VETOR_10; i++) {
		printf("%10.3f \t %10.3f \t %15.3f \n", vetorUsuario[i], escalar, vetorAuxiliar[i]);
	}
	separaQuestoes();
}

//Exercicio 03 - Vetor x Vetor 
void exercicio03(void) {
	uint8_t i;
	float vetorUsuario01[10], vetorUsuario02[10], vetorEscalar[10];
	for (i = INICIAINDC; i < TAMANHO_DO_VETOR_10; i++) {
		printf("Por favor, digite o valor para a posicao %hhd do primeiro vetor: ", i);
		scanf("%f", &vetorUsuario01[i]);
		printf("\n");
		printf("Por favor, digite o valor para a posicao %hhd do segundo vetor: ", i);
		scanf("%f", &vetorUsuario02[i]);
		vetorEscalar[i] = vetorUsuario01[i] * vetorUsuario02[i];
	}
	printf("O Primeiro vetor \t vezes o segundo vetor \t eh iguao ao vetor: \n");
	for (i = INICIAINDC; i < TAMANHO_DO_VETOR_10; i++) {
		printf("%15f \t %15f \t %15f \n", vetorUsuario01[i], vetorUsuario02[i], vetorEscalar[i]);
	}
}

//Exercicio 04 - Media aritmetica do vetor
void exercicio04(void) {
	uint16_t i;
	float valorDoVetor, somaDosValores, vetorUsuario[TAMANHO_MAXIMO_DO_VETOR], mediaDosValores;
	somaDosValores = 0.0;
	printf("Por favor, informe um numero (de 1 a 1000) para escolher o tamanho do seu vetor: ");
	scanf("%f", &valorDoVetor);
	for (i = INICIAINDC; i < valorDoVetor; i++) {
		printf("Por favor, digite o valor para a posicao %hhd do primeiro vetor: ", i);
		scanf("%f", &vetorUsuario[i]);
		somaDosValores += vetorUsuario[i];
	}
	mediaDosValores = somaDosValores / valorDoVetor;
	printf("\n");
	printf("A media aritmetica dos valores informados para o vetor eh: %.3f", mediaDosValores);
	separaQuestoes();
}

int main(int argc, char** argv) {
	uint8_t questoes;
	do {
		imprimeMenuDeQuestoes();
		printf("De acordo com o menu apresentado anteriormente, escolha o numero da questao que deseja acessar: ");
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
			default: {
			printf("ERROR: opcao invalida! Por favor, escolha um numero entre 1 e 5, ou pressione 0 para sair");
			separaQuestoes();
			}
		}
		separaQuestoes();
	} while (questoes != 0);
	return SUCESSO;
}