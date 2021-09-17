#include <stdio.h>
#include <stdint.h>
#define SUCESSO 0


//Função Menu da Calculadora
void menuCalc(void) {
	printf("=========================== CALCULADORA ===========================\n");
	printf("Digite [valor 1 * valor 2] para realizar uma multiplicacao\n");
	printf("Digite [valor 1 / valor 2] para realizar uma divisao\n");
	printf("Digite [valor 1 + valor 2] para realizar uma soma\n");
	printf("Digite [valor 1 - valor 2] para realizar uma diferenca\n");
	printf("Digite [valor 1 %% valor 2] para obter o modulo de uma divisoa\n");
	printf("Digite [valor 1 # valor 2] para obter a exponencial desse valor\n");
}

//Função Menu Erro
void entradaInvalida(void) {
	printf("\n");
	printf("ERROR: operacao invalida, o programa sera encerrado imediatamente!");
}

//Função para separar o menu
void separaMenu(void) {
	printf("\n");
	printf("\n");
}

//Função para calcular a soma
double soma(double valor1, double valor2) {
	return valor1 + valor2;
}

//Função para calcular diferença
double diferenca(double valor1, double valor2) {
	return valor1 - valor2;
}

//Função para casos de multiplicação
double multiplicacao(double valor1, double valor2) {
	return valor1 * valor2;
}

//Função para os casos de exponenciação
uint64_t exponencial(uint64_t valor1, uint64_t valor2) {
	int i;
	uint64_t resultado;
	resultado = valor1;
	if (valor2 == 1) {
		return valor1;
	}
	else if (valor2 == 0) {
		return 0;
	} 
	else {

	for (i = 1; i < valor2; i++) {
		resultado *= valor1;
	}
	return resultado;
	}
}

//Função para divisão
double divisao(double valor1, double valor2) {
	return ((valor1 * 1.0) / valor2);
}

//Função para casos de cacular o módulo
int modulo(int valor1, int valor2) {
	if (valor1 % valor2 == 0) {
		return valor1 / valor2;
	}
	else {
		return valor1 % valor2;
	}
}

//Função de Controle (main)
int main(int argc, char** argv) {
	char operador;
	double valor1, valor2, resultado;
	uint64_t resultadoExp;
	do {
		valor1 = 87514562;
		valor2 = 97495602;
		menuCalc();
		printf("Por favor, insira a operacao que deseja fazer: ");
		scanf("%lg %c %lg", &valor1, &operador, &valor2);

		if (((valor1 != 87514562) && (valor2 != 97495602)) && ((operador == '*') || (operador == 'x') || (operador == 'X') || (operador == '/') || (operador == '+') || (operador == '-') || (operador == '#') || (operador == '%'))) {
				switch (operador) {
				case 42: {
					resultado = multiplicacao(valor1, valor2);
					printf("\n");
					printf("O resultado dessa operacao [%lg %c %lg] eh igual a: %lg", valor1, operador, valor2, resultado);
					separaMenu();
					break;
				}
				case 88: {
					resultado = multiplicacao(valor1, valor2);
					printf("\n");
					printf("O resultado dessa operacao [%lg %c %lg] eh igual a: %lg", valor1, operador, valor2, resultado);
					separaMenu();
					break;
				}
				case 120: {
					resultado = multiplicacao(valor1, valor2);
					printf("\n");
					printf("O resultado dessa operacao [%lg %c %lg] eh igual a: %lg", valor1, operador, valor2, resultado);
					separaMenu();
					break;
				}
				case 47: {
					resultado = divisao(valor1, valor2);
					printf("\n");
					printf("O resultado dessa operacao [%lg %c %lg] eh igual a: %lg", valor1, operador, valor2, resultado);
					separaMenu();
					break;
				}
				case 43: {
					resultado = soma(valor1, valor2);
					printf("\n");
					printf("O resultado dessa operacao [%lg %c %lg] eh igual a: %lg", valor1, operador, valor2, resultado);
					separaMenu();
					break;
				}
				case 55: {
					resultado = diferenca(valor1, valor2);
					printf("\n");
					printf("O resultado dessa operacao [%lg %c %lg] eh igual a: %lg", valor1, operador, valor2, resultado);
					separaMenu();
					break;
				}
				case 37: {
					resultado = modulo((int)valor1,(int)valor2);
					if (resultado == (valor1 / valor2)) {
						printf("\n");
						printf("O modulo de [%lg %c %lg] corresponde a uma divisao inteira. Nesse caso obtemos o resto igual a %i e o valor da divisao igual a: %lg", valor1, operador, valor2, 0, resultado);
						separaMenu();
					}
					else {
						printf("\n");
						printf("O modulo de [%lg %c %lg] possui o resto no valor de: %lg", valor1, operador, valor2, resultado);
						separaMenu();
					}
					break;
				}
				case 35: {
					resultadoExp = exponencial((uint64_t)valor1, (uint64_t)valor2);
					printf("\n");
					printf("O resultado dessa operacao [%lg %c %lg] eh igual a: %I64d", valor1, operador, valor2, resultadoExp);
					separaMenu();
					break;
				}
				}
		

		}
		else {
			entradaInvalida();
			operador = 'F';
		}

	} while (operador != 'F');

	return SUCESSO;
}