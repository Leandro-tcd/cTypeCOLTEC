//Libs
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

// Constantes
#define SUCESSO 0
#define INICIAINDC 0
#define QUANTIDADE_MAXIMA_DE_INGREDIENTES_COMUNS 3
#define QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS 3
#define QUANTIDADE_MAXIMA_DE_INGREDIENTES_MASSA 6

//Função Menu Pizza
void imprimeMenuPizza(void) {
	printf("============= SEJA BEM VINDO AO SEU APP PREFERIDO DE RECEITAS =============\n");
	printf("AS RECEITAS DISPONIVELS NO MOMENTO SAO:\n");
	printf("[1] Pizza de Calabresa\n");
	printf("[2] Pizza de Quatro Queijos\n");
	printf("[3] Pizza de Peperoni e Palmito\n");
	printf("[4] Pizza de Carne e Bacon\n");
	printf("[5] Pizza de Frango com Catupiri\n");
	printf("[0] Caso deseje sair\n");
}

//Função para imprimir os ingredientes comum a todas as pizzas (massa e parte básica do recheio)
void ingredientesComuns(void){
	char* listaDeIngredientesBasicosMassa[QUANTIDADE_MAXIMA_DE_INGREDIENTES_MASSA];
	char* quantidadeDeIngredientesBasicosMassa[QUANTIDADE_MAXIMA_DE_INGREDIENTES_MASSA];
	char* listaDeIngredientesBasicosRecheio[QUANTIDADE_MAXIMA_DE_INGREDIENTES_COMUNS];
	char* quantidadeDeIngredientesBasicosRecheio[QUANTIDADE_MAXIMA_DE_INGREDIENTES_COMUNS];
	uint8_t i;

	//Ingredientes basicos para a massa
	listaDeIngredientesBasicosMassa[0] = "agua morna";
	listaDeIngredientesBasicosMassa[1] = "sal";
	listaDeIngredientesBasicosMassa[2] = "fermento Biologico";
	listaDeIngredientesBasicosMassa[3] = "acucar";
	listaDeIngredientesBasicosMassa[4] = "azeite";
	listaDeIngredientesBasicosMassa[5] = "farinha de Trigo";
	
	//Quantidades de ingredientes basicos para a Massa
	quantidadeDeIngredientesBasicosMassa[0] = "01 Xicara (165.0g)";
	quantidadeDeIngredientesBasicosMassa[1] = "01 Colher de cha rasa (2.5g)";
	quantidadeDeIngredientesBasicosMassa[2] = "01 Sache (10.0g)";
	quantidadeDeIngredientesBasicosMassa[3] = "01 Colhe de sopa rasa (7.5g)";
	quantidadeDeIngredientesBasicosMassa[4] = "05 Colheres de sopa (37.5g)";
	quantidadeDeIngredientesBasicosMassa[5] = "04 Xicaras (660.0g)";

	//Ingredientes basicos do recheio
	listaDeIngredientesBasicosRecheio[0] = "molho de tomate";
	listaDeIngredientesBasicosRecheio[1] = "queijo mussarela";
	listaDeIngredientesBasicosRecheio[2] = "oregado";

	//Quantidades de Ingredientes basicos para o recheio
	quantidadeDeIngredientesBasicosRecheio[0] = "05 Colheres de sopa cheia (40.0g)";
	quantidadeDeIngredientesBasicosRecheio[1] = "300g";
	quantidadeDeIngredientesBasicosRecheio[2] = "1.0g";

	printf("\nPara a massa, sera necessario:\n");
	for (i = INICIAINDC; i < QUANTIDADE_MAXIMA_DE_INGREDIENTES_MASSA; i++) {
		printf("%s de %s \n", quantidadeDeIngredientesBasicosMassa[i], listaDeIngredientesBasicosMassa[i]);
	}
	printf("\nComo base do recheio utilize:\n");
	for (i = INICIAINDC; i < QUANTIDADE_MAXIMA_DE_INGREDIENTES_COMUNS; i++) {
		printf("%s de %s \n", quantidadeDeIngredientesBasicosRecheio[i], listaDeIngredientesBasicosRecheio[i]);
	}
}

//Funções para imprimir os ingredientes usados para o recheio de cada tipo de pizza

// Pizza01 = Calabresa
void Pizza01(void) {
	char* listaDeIngredientesUsados[QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS];
	char* quantidadeDeIngredientesUsados[QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS];
	uint8_t i;
	// Ingredientes do Recheio
	listaDeIngredientesUsados[0] = "calabresa";
	listaDeIngredientesUsados[1] = "aneis de cebola";
	listaDeIngredientesUsados[2] = "azeitona";

	//Quantidades de Ingredientes basicos para o recheio
	quantidadeDeIngredientesUsados[0] = "350g";
	quantidadeDeIngredientesUsados[1] = "80g";
	quantidadeDeIngredientesUsados[2] = "30g";

	printf("\nPara o Recheio: \n");
	for (i = INICIAINDC; i < QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS; i++) {
		printf("%s de %s \n", quantidadeDeIngredientesUsados[i], listaDeIngredientesUsados[i]);
	}

}
// Pizza02 = Quatro Queijos
void Pizza02(void) {
	char* listaDeIngredientesUsados[QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS];
	char* quantidadeDeIngredientesUsados[QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS];
	uint8_t i;
	// Ingredientes do Recheio
	listaDeIngredientesUsados[0] = "provoloni";
	listaDeIngredientesUsados[1] = "catupiri";
	listaDeIngredientesUsados[2] = "gorgonzola";
	
	//Quantidades de Ingredientes basicos para o recheio
	quantidadeDeIngredientesUsados[0] = "250g";
	quantidadeDeIngredientesUsados[1] = "250g";
	quantidadeDeIngredientesUsados[2] = "200g";
	
	printf("\nPara o Recheio: \n");
	for (i = INICIAINDC; i < QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS; i++) {
		printf("%s de %s \n", quantidadeDeIngredientesUsados[i], listaDeIngredientesUsados[i]);
	}

}
// Pizza03 = Peperoni e Palmito
void Pizza03(void) {
	char* listaDeIngredientesUsados[QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS];
	char* quantidadeDeIngredientesUsados[QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS];
	uint8_t i;
	listaDeIngredientesUsados[0] = "peperoni";
	listaDeIngredientesUsados[1] = "palmito";
	listaDeIngredientesUsados[2] = "aneis de cebola";
	
	//Quantidades de Ingredientes basicos para o recheio
	quantidadeDeIngredientesUsados[0] = "350g";
	quantidadeDeIngredientesUsados[1] = "250g";
	quantidadeDeIngredientesUsados[2] = "80g";

	printf("\nPara o Recheio: \n");
	for (i = INICIAINDC; i < QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS; i++) {
		printf("%s de %s", quantidadeDeIngredientesUsados[i], listaDeIngredientesUsados[i]);
	}
}
// Pizza04 = Carne e Bacon
void Pizza04(void) {
	char* listaDeIngredientesUsados[QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS];
	char* quantidadeDeIngredientesUsados[QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS];
	uint8_t i;
	listaDeIngredientesUsados[0] = "carne";
	listaDeIngredientesUsados[1] = "bacon";
	listaDeIngredientesUsados[2] = "azeitona";

	//Quantidades de Ingredientes basicos para o recheio
	quantidadeDeIngredientesUsados[0] = "200g";
	quantidadeDeIngredientesUsados[1] = "300g";
	quantidadeDeIngredientesUsados[2] = "50g";
	
	printf("\nPara o Recheio: \n");
	for (i = INICIAINDC; i < QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS; i++) {
		printf("%s de %s \n", quantidadeDeIngredientesUsados[i], listaDeIngredientesUsados[i]);
	}
}
// Pizza05 = Frango com Catupiri
void Pizza05(void) {
	char* listaDeIngredientesUsados[QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS];
	char* quantidadeDeIngredientesUsados[QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS];
	uint8_t i;
	listaDeIngredientesUsados[0] = "frango";
	listaDeIngredientesUsados[1] = "catupiri";
	listaDeIngredientesUsados[2] = "azeitona";

	//Quantidades de Ingredientes basicos para o recheio
	quantidadeDeIngredientesUsados[0] = "350g";
	quantidadeDeIngredientesUsados[1] = "250g";
	quantidadeDeIngredientesUsados[2] = "60g";

	printf("\nPara o Recheio: \n");
	for (i = INICIAINDC; i < QUANTIDADE_MAXIMA_DE_INGREDIENTES_USADOS; i++) {
		printf("%s de %s \n", quantidadeDeIngredientesUsados[i], listaDeIngredientesUsados[i]);
	}
}

//Função main ~> Exibição do menu e escolha da pizza
int main(int argc, char** argv) {
	uint8_t Codpizza;
	
	do {
		imprimeMenuPizza();
		printf("Selecione a pizza que deseja de acordo com a numeracao do menu acima \n");
		printf("Escolha a Pizza:");
		scanf("%hhd", &Codpizza);
		switch (Codpizza) {
		case 0: {
			break;
		}
		case 1: {
			ingredientesComuns();
			Pizza01();
			printf("\n");
			break;
		}
		case 2: {
			ingredientesComuns();
			Pizza02();
			printf("\n");
			break;
		}
		case 3: {
			ingredientesComuns();
			Pizza03();
			printf("\n");
			break;
		}
		case 4: {
			ingredientesComuns();
			Pizza04();
			printf("\n");
			break;
		}
		case 5: {
			ingredientesComuns();
			Pizza05();
			printf("\n");
			break;
		}
		default: {
			printf("ERROR! Pizza nao encontrada. \nPor favor, digite o codigo de acordo com o menu apresentado");
			printf("\n");
		}
		}
	} while (Codpizza != 0);

	return SUCESSO;
}