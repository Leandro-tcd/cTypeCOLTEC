/*Receber três notas e calcular o valor final usando a média ponderada
pesos 4, 3 e 3 */

#include <stdio.h>
#define SUCESSO 0
int main(int argc, char** argv) {
	float prov1, prov2, prov3, med;
	printf("Por favor, digite a nota das suas tres provas \n");
	scanf("%f %f %f", &prov1, &prov2, &prov3);
	med = ((prov1 * 4.0) + (prov2 * 3.0) + (prov3 * 3.0)) / 10;
	printf("Sua media para essa materia foi de %.2f \n", med);
	return SUCESSO;
}