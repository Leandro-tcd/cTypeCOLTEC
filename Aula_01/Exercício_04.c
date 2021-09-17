/*Aumento de um funcionário através do salário atual e 
a porcentagem de aumento*/

#include <stdio.h>
#define SUCESSO 0

int main(int argc, char** argv) {
	float salarioAtual, porcentAumento, salarioAtt;
	printf("Para calcular o seu novo salário, por favor, informe o valor do salário atual \n");
	scanf("%f", &salarioAtual);
	printf("Agora, por favor, informe a porcentagem do aumento \n");
	scanf("%f", &porcentAumento);
	salarioAtt = salarioAtual + (salarioAtual * ((porcentAumento * 1.0) / 100));
	printf("O valor do seu novo salario eh: %.3f, parabens pela promocao! \n", salarioAtt);
	return SUCESSO;
}