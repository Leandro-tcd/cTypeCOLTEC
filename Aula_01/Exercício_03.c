/*Algoritmo para gerar e imprimir o resultado do n�mero H, sendo
H = 1 + 1/2 + 1/3 + 1/4 + 1/5*/

#include <stdio.h>
#define SUCESSO 0
// Como H n�o receber� nenhuma entrada e os valores s�o pr� definidos, � melhor usar constante
#define H 1 + ((1*1.0)/2) + ((1*1.0)/3) + ((1*1.0)/4) + ((1*1.0)/5)

int main(int argc, char ** argv) {
	printf("O valor de H eh %.3f", H); // O valor � uma d�zima
	return SUCESSO;
}