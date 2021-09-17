#include <stdio.h>


#define SUCESSO 0

// Em C, condições falsas recebem 0


	/* Par ou Impar */
void exercicio01(void) {

	int num;

	printf("Por favor, digite um numero inteiro: ");
	scanf("%d", &num);

	if (num % 2 == 0) {
		printf("\n O numero informado pertence ao conjunto dos numeros pares");
	}
	else {
		printf("\n O numero informado pertence ao conjunto dos numeros impares");
	};
};
	/* Maior, menor ou igual */
void exercicio02(void) {

	int num1, num2;

	printf("Por favor, digite dois numeros inteiros: ");
	scanf("%i %i", &num1, &num2);

	if (num1 > num2) {
		printf("\n O numero %i eh maior que %i", num1, num2);
	}
	else if (num2 > num1) {
		printf("\n O numero %i eh maior que %i", num2, num1);
	}
	else {
		printf("\n Os numeros informados são iguais");
	};

};
	/* Dia da Semana */
void exercicio03(void) {

	int dia;

	printf("Por favor, informe o numero de 1 ate 7, referente ao dia da semana que voce deseja: ");
	scanf("%i", &dia);

	switch (dia) {
	case 1: {
		printf("\n O dia da semana informado eh Domingo");
		break;
	}
	case 2: {
		printf("\n O dia da semana informado eh a Segunda-feira");
		break;
	}
	case 3: {
		printf("\n O dia da semana informado eh a Terca-feira");
		break;
	}
	case 4: {
		printf("\n O dia da semana informado correspode a Quarta-feira");
		break;
	}
	case 5: {
		printf("\n O dia da semana informado corresponde a Quinta-feira");
		break;
	}
	case 6: {
		printf("\n O dia da semana informado eh a Sexta-feira");
		break;
	}
	case 7: {
		printf("\n O dia da semana informado corresponde ao Sabado");
		break;
	}
	default: {
		printf("\n Dia da semana inválido");
	}
	}
};
	/* Calculadora */
void exercicio04(void) {

	float result, num1, num2;
	char operador;

	printf("Por favor, digite a operacao que deseja fazer ex [ 4 + 3 ]: ");
	scanf("%f %c %f", &num1, &operador, &num2);

	if ((operador == '*') || (operador == 'x') || (operador == 'X')) {
		result = num1 * num2;
		printf("\n O resultado da multiplicacao entre %.2f e %.2f eh igual a: %.2f ", num1, num2, result);
	}
	else if (operador == '/') {
		result = ((num1 * 1.0) / num2);
		printf("\n O resultado da divisao entre o %.2f e %.2f eh igual a: %2.f ", num1, num2, result);
	}
	else if (operador == '+') {
		result = num1 + num2;
		printf("\n A soma dos numeros %.2f e %.2f eh igual a: %.2f ", num1, num2, result);
	}
	else if (operador == '-') {
		result = num1 - num2;
		printf("\n A diferenca entre o numero %.2f e o numero %.2f eh igual a: %.2f", num1, num2, result);
	}
	else {
		printf("\n Error: A operacao informada eh invalida");
	};

};
	/* É triângulo ou não */
void exercicio05(void) {

	float x, y, z;
	printf("Por favor, informe os tres comprimentos para saber se eles formam um triangulo: ");
	scanf("%f %f %f", &x, &y, &z);
	if ((x < (y + z)) && (y < x + z) && (z < (x + y))) {
		printf("\n Os numeros informados formam um triangulo");
	}
	else {
		printf("\n Desculpe, mas os numeros informados nao satisfazem as condicoes para a formacao de um triangulo");
	};
};
	/* Peso ideal */
void exercicio06(void) {

	float peso, altura, result;
	char sexo;

	printf("Por favor, informe a sua altura (em metros): ");
	scanf("%f", &altura);
	printf("Agora, por gentileza, informe o seu peso (em Kg): ");
	scanf("%f", &peso);
	printf("Por fim, nos informe seu sexo [M/F]: ");
	scanf(" %c", &sexo);
	
	if ((sexo == 'M') || (sexo == 'm')) {
		result = (72.7 * altura) - 58;
		if (peso > result) {
			printf("\n Voce esta acima do peso. O seu peso ideal eh: %.2f", result);
		}
		else if (peso < result) {
			printf("\n Voce esta abaixo do seu peso. O seu peso ideal eh: %.2f", result);
		}
		else {
			printf("\n Parabens, voce esta no peso ideal que eh: %.2f", result);
		};
	}
	else if ((sexo == 'F') || (sexo == 'f')) {
		result = (62.1 * altura) - 44.7;
		if (peso > result) {
			printf("\n Voce esta acima do seu peso. O seu peso ideal eh: %.2f", result);
		}
		else if (peso < result) {
			printf("\n Voce esta abaixo do seu peso. O seu peso ideal eh: %.2f", result);
		}
		else {
			printf("\n Parabens, voce esta no peso ideal que eh: %.2f", result);
		};
	}
	else {
		printf("ERROR: informacoes incorretas");
	};
}

int main(int argc, char** argv) {
	int exercicio;
	do {

		// Menu: seleção de exercícios
		printf("Os exercicios da aula cinco foram: \n");
		printf("[1] para par ou impar \n");
		printf("[2] para ler inteiros e determinar o maior \n");
		printf("[3] para dia da semana \n");
		printf("[4] para operacoes entre dois valores \n");
		printf("[5] para saber se um conjunto de valores forma um triangulo \n");
		printf("[6] para saber o peso ideal \n");
		printf("[0] para sair \n");
		printf("Por favor, digite o numero do exercicio que voce quer executar: ");
		scanf("%d", &exercicio);

		switch (exercicio) {

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
				printf("ERROR: Voce nao escolheu um exercicio valido!");
			}
		}
		printf("\n");
		printf("\n");
	
	}	while (exercicio != 0);
	
	return SUCESSO;
}