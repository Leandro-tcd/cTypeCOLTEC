#include <stdio.h>
#define SUCESSO 0

// N fatorial
void exercicio01(void) {
	printf("\n");
	int num, i;
	printf("Por favor, insira o numero para o qual deseja calcular o fatorial: ");
	scanf("%d", &num);

	if (num == 0) {
		printf("\nO fatorial de 0 eh um caso especial, sendo assim obtemos para 0! o valor 1");
	}
	else {
		printf("\nDado o valor %d, escolhido pelo senhor(a), obtemos o seguinte fatorial: \n", num);
		for (i = (num - 1); i >= 1; i--) {
			printf("|  %10d  %c %d  |", num, '*', i);
			num = (num * i);
			printf("  =  %d \n", num);
		}
		printf("\nObtendo como valor final o numero: %d", num);
	}
}
// divisao por N fatorial
void exercicio02(void) {
	printf("\n");
	
	int numero, divi, i, j;
	double resultado;
	
	printf("Por favor, digite o numero para que seja feita a soma das fracoes de seu fatorial: ");
	scanf("%d", &numero);

	resultado = 1;

	for (i = 2; i <= numero; i++) {
		divi = 1;
		for (j = 1; j <= i; j++) {
			divi = divi * j;
		}
		resultado = (double) (resultado + (1.0 / divi));
	}
	printf("\nO resultado da soma das fracoes fatoriais de %d eh: %.3f", numero, resultado);
}
// Menor e Maior
void exercicio03(void) {
	printf("\n");
	int num, menor, maior;
	maior = 0;
	menor = 0;

	do {
		printf("Por favor, digite os valores desejados para identificar o maior e o menor numero dentre eles. \n");
		printf("Eh necessario que seja informado um por vez clicando enter apos digita-los. Ao terminar, basta usar como entrada o numero zero. \n");
		printf("Feito isso, o programa sera finalizado e o resultado sera apresentado para o senhor(a): ");
		scanf("%d", &num);
		if (num != 0) {
			if (num > maior) {
				maior = num;
			}
			else {
				menor = num;
			}
		}
	} while (num != 0);
	printf("\nO maior numero corresponde a: %d \n", maior);
	printf("E o menor corresponde a: %d ", menor);
}
// Sequência de Fibonacci 
void exercicio04(void) {
	printf("\n");
	int num1, num2, num3, vezes;
	
	printf("Digite a quantidade de numeros da serie de fibbonaci que voce deseja saber: ");
	scanf("%i", &vezes);
	num1 = 1;
	num2 = 1;
	num3 = 1;
	if (vezes == 0) {
		printf("\nO numero inserido eh invalido! Devido a isso o programa sera encerrado.");
	}
	else {
		printf("Os %d numeros da sequencia de Fibonacci sao: ", vezes);
		do {
			printf("%3d, ", num3);
			num3 = num1 + num2;
			num1 = num2;
			num2 = num3;
			vezes--;
		} while (vezes != 0);
		printf("Obrigado pela visita!");
	}
}
// Calcular graus celcius
void exercicio05(void) {
	printf("\n");
	int fahren;
	float celcius;
	fahren = 50;
	do {
		celcius = ((9.0 * (fahren - 32)) / 5);
		printf("\nQuando a temperatura eh %3d graus Fahrenheit, temos %5.1f graus Celcius", fahren, celcius);
		fahren++;
	} while (fahren <= 150);
}
// Menu de inicialização e chamadas
int main(int argc, char** argv) {
	int exercicio;
	do {
		//Menu contendo todos os exercicios e opções possíveis do menu
		printf("Os exercIcios dessa semana foram: \n");
		printf("[1] para o fatorial de um numero qualquer (N!) \n");
		printf("[2] para a soma de uma fracao cujo denominador eh um fatorial informado por voce \n");
		printf("[3] para informar valores e indentificar qual o maior e o menor dentre eles \n");
		printf("[4] para saber quantos numeros da serie de Fibonacci voce desejar \n");
		printf("[5] para acessar ao conversor de graus Fahrenheit para graus Celcios \n");
		printf("[0] para parar a execucao \n");
		printf("Por favor, indique o numero referente ao exercicio que deseja executar: ");
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
			default: {
				printf("ERROR: Exercicio escolhido invalido! Por favor, tente novamente.");
			}
		}
		printf("\n");
		printf("\n");
	} while (exercicio != 0);

	return SUCESSO;
}