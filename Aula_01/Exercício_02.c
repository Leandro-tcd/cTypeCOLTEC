/* ler 6 valores reais, calcular e imprimir a média aritmética*/

#include <stdio.h>
#define SUCESSO 0

int main(int argc, char ** argv) {
	float num1, num2, num3, num4, num5, num6, med;
	printf("Para calcular a média, digite 6 valores \n");
	scanf("%f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6);
	med = ((num1 + num2 + num3 + num4 + num5 + num6) * 1.0) / 6;
	printf("A média dos valores informado eh %.2f", med);
	return SUCESSO;
}