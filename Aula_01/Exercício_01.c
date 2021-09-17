/*ler 5 valores inteiros, calcular e imprimir a soma*/
#include <stdio.h>
#define SUCESSO 0

int main(int argc, char ** argv) {
	float num1, num2, num3, num4, num5, result;
	printf("Para realizar a soma, digite, por favor, cinco valores \n");
	scanf("%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);
	result = num1 + num2 + num3 + num4 + num5;
	printf("O resultado da soma eh: %.2f \n", result);
	return SUCESSO;
}