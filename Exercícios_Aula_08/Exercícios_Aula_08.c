#include <stdio.h>
#include <stdint.h>
#define SUCESSO 0
//Função para separar menu
void separaMenu(void) {
	printf("\n");
	printf("==============================================================================================");
	printf("\n");
}

//Função para imprimir o menu
void menuDeQuestoes(void) {
	printf("Os exercicios dessa semana foram:\n");
	printf("[1] Calculadora\n");
	printf("[2] para fornecer sua idade em anos, meses e dias e saber ela em dias\n");
	printf("[3] para fornecer o tempo em segundos e converter ele para horas\n");
	printf("[4] para verificar se o nemero eh primo\n");
	printf("[5] para calcular o N fatorial (N!)\n");
	printf("[0] para Sair.\n");
}

// Menu para Calculadora
void menuDaCalculadora(void) {
	printf("Esse eh o menu de possibilidades para a realizacao de calculos\n");
	printf("[1] para Soma\n");
	printf("[2] para Produto\n");
	printf("[3] para Divisao\n");
	printf("[4] para Sair\n");
	printf("Por favor, digite a opcao de acordo com o menu apresentado:  ");
}

//Funções para a calculadora do exercício 01
float soma(float A, float B) {
	return A + B;
}
float produto(float A, float B) {
	return A * B;
}
double divisao(float A, float B) {
	return (A * 1.0) / B;
}

//Exercício 01 - Calculadora
void exercicio01(void) {
	uint8_t opcao;
	float A, B;
	double resultado;
	do {
		menuDaCalculadora();
		scanf("%hhd", &opcao);

		if ((opcao >= 1) && (opcao <= 3)) {
			printf("\n");
			printf("Digite os dois numeros para a realizacao do calculo [numero1 numero2]: ");
			scanf("%f %f", &A, &B);
		}

		switch (opcao) {
		case 1: {
			resultado = soma(A,B);
			printf("O resultado da soma realizada eh: %.2f\n", resultado);
			break;
		}
		case 2: {
			resultado = produto(A,B);
			printf("O resultado do produto realizada eh: %.2f\n", resultado);
			break;
		}
		case 3: {
			resultado = divisao(A,B);
			printf("O resultado da operacao realizada eh: %.4f\n", resultado);
			break;
		}
		case 4: {
			return;
		} default: {
			printf("ERROR: voce escolheu uma opcao invalida, por favor tente novamente.\n");
			break;
		}
		}
		separaMenu();
	} while (opcao != 4);

}

//Funções para transformar a idade em ano, mês e dias em dias 
#define anoEmDias 365
#define mesEmDias 30
uint32_t idadeEmDias(uint8_t ano, uint8_t mes, uint8_t dia) {
	return ((uint16_t)ano * anoEmDias) + ((uint16_t)mes * mesEmDias) + dia;
}

//Exercício 02 - Transformar idade em dias
void exercicio02(void) {
	
	separaMenu();
	
	uint8_t dia, mes, ano;
	uint32_t resultado;

	printf("Por favor, informe a sua idade em anos meses e dias [aa mm dd]: ");
	scanf("%hhd %hhd %hhd", &ano, &mes, &dia);

	resultado = idadeEmDias(ano, mes, dia);
	printf("Se voce nasceu a %hhd anos, %hhd meses e %hhd dias. voce ja viveu %d dias", ano, mes, dia, resultado);
	printf("\n");
}

//Funções para converter tempo de segundos para horas
#define segParaMinuto 60
#define minParaHora	60
uint8_t restoDeSegundos(int seg) {
	return seg % segParaMinuto;
}
uint8_t tempoEmMinutos(int seg) {
	uint8_t minuto, minutoResto;
	minuto = seg / segParaMinuto;
	minutoResto = minuto % minParaHora;
	return (minutoResto);
}
uint16_t tempoEmHora(int seg) {
	uint16_t hora;
	uint8_t minuto;
	minuto = seg / segParaMinuto;
	hora = minuto / minParaHora;
	return (hora);
}

//Exercício 03 - Transformar segundos em horas
void exercicio03(void) {
	int seg;
	uint16_t hora;
	uint8_t segundos, minutos;
	separaMenu();

	printf("Por favor, informe quantos segundos levou para completar o experimento [3984]:  ");
	scanf("%d", &seg);
	segundos = restoDeSegundos(seg);
	hora = tempoEmHora(seg);
	minutos = tempoEmMinutos(seg);
	printf("\n");
	printf("Se o experimento levou %d segundos para ser concluido, significa que foram gastos %hd hora(s), %hhd minuto(s) e %hhd segundos.", seg, hora, minutos, segundos);
	printf("\n");
}

//Função para definir se o numero é primo ou não
#define VERDADEIRO 1
#define FALSO !VERDADEIRO
uint8_t numeroPrimo(uint32_t num) {
	uint8_t i, primo;
	//Começa com 1 por que não irei testar num/num
	primo = 1;
	for (i = (num - 1); i >= 1; i--) {
		if (num % i == 0) {
			primo += 1;
		}
	}
	if (primo > 2) {
		return FALSO;
	}
	else {
		return VERDADEIRO;
	}
}

//Exercício 04 - Verificar se um número é primo
void exercicio04(void) {
	uint32_t num;
	uint8_t resultado;
	separaMenu();
	printf("Por favor, informe o numero para verificar se eh primo: ");
	scanf("%I32d", &num);
	
	if (num == 1) {
		printf("\n");
		printf("O numero %I32d so eh divisivel por ele mesmo, nesse caso, ele nao eh primo!", num);
	}
	
	resultado = numeroPrimo(num);
	if (resultado == FALSO) {
		printf("\n");
		printf("O numero %I32d possui mais de dois divisores inteiros. Nesse caso, ele nao eh primo!", num);
	}
	else {
		printf("\n");
		printf("O numero %I32d so eh divisivel por %d e ele mesmo. Nesse caso, ele nao eh primo!", num, 1);
	}

}

//Funções para calcular fatorial
uint64_t calculaFatorial(uint64_t num) {
	uint64_t i;
	for (i = (num -1); i >= 1; i--) {
		num *= i;
	}
	return num;
}

//Exercício 05 - N Fatorial
void exercicio05(void) {
	int num;
	uint64_t resultado;
	
	separaMenu();

	printf("Digite um numero para identificar o seu fatorial: ");
	scanf("%d", &num);
	resultado = calculaFatorial(num);
	printf("\n");
	printf("Ao calcular o fatorial de %d, obtemos: %llu", num, resultado);
}

// Painel de execução central
int main(int argc, char** argv) {

	uint8_t exercicio;
	
	do {
		menuDeQuestoes();
		printf("De acordo com o menu apresentado, digite por favor o numero do exercicio: ");
		scanf("%hhd", &exercicio);

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
		default:{
				  printf("ERROR: numero do exercicio invalido");
			  }
		}
	separaMenu();
	} while (exercicio != 0);

	return SUCESSO;
}