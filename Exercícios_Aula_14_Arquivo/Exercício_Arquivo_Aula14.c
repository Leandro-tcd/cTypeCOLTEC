#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

//Constantes
#define SUCESSO 0
#define INITCONT 0
#define INITSOMADOR 0
#define RAIZ 0.5
#define CONFIRMA_CARACTERE 1
#define VERDADEIRO 1
#define QUANTIDADE_DE_PROVAS 2
#define EXPOENTE 2
#define QUANTIDADE_DE_LINHAS 5
#define ARQUIVO "./dadosSalvos.txt"
#define CAMINHO_MAXIMO_ARQUIVO (150 + 1)
#define QUANTIDADE_MAXIMA_NOME (50 + 1)

//Estrutura para o cadastro de dados de Alunos - Exercício 03 e 04
typedef struct infoCadastro_s {
	char nomeDoAluno[QUANTIDADE_MAXIMA_NOME];
	float notas[QUANTIDADE_DE_PROVAS], media;
} infoCadastro_t;

//Função para exibir menu de exercícios da semana
void imprimeMenu(void) {
	printf("=============================================ATIVIDADES DA SEMANA=======================================================\n");
	printf("As atividades disponiveis para essa semana foram:\n");
	printf("[1] Para identificar o numero de linhas contidas no arquivo\n");
	printf("[2] Identificar o numero de caracteres de um arquivo\n");
	printf("[3] Armazenar os nomes e as notas de N alunos\n");
	printf("[0] Para sair\n");
	printf("=============================================ESCOLHA A ATIVIDADE=======================================================\n");
	printf("\n");
}

//Função para criar o arquivo utilizado nos Exercícios 01 e 02
void criaArquivo(void) {
	//Variáveis de manipulação
	FILE* arquivoDeManipulação;
	uint8_t i;
	//Abrir o arquivo
	arquivoDeManipulação = fopen(ARQUIVO, "w");
	//Verificar se o arquivo abriu corretamente
	if (arquivoDeManipulação == NULL) {
		perror("Falha ao abrir o arquivo");
	}
	//Adicionar as linhas ao arquivo
	for (i = INITCONT; i < QUANTIDADE_DE_LINHAS; i++) {
		fprintf(arquivoDeManipulação,"Linha [%hhd]\n", (i+1));
	}
	//Fechar o arquivo
	fclose(arquivoDeManipulação);
}

//Função para alocar a memória utilizado nos Exercício 03 e 04
infoCadastro_t* criaDadosDosAlunos(uint16_t quantidadeAlunos) {
	infoCadastro_t* infoAlunos;
	infoAlunos = (infoCadastro_t *) malloc(quantidadeAlunos * sizeof(infoCadastro_t));
	return infoAlunos;
}

//Função para executar o exercício 01 - Contador de Linhas
void exercicio01(void) {
	// Variáveis utilizadas 
	FILE* arquivoPadrao;
	FILE* arquivoUsuario;
	uint16_t somador = INITSOMADOR;
	uint8_t aux ;
	char comparador, caractereProcessado;
	char caminhoDoArquivo[CAMINHO_MAXIMO_ARQUIVO];
	
	// Opção de arquivo padrão ou entrada por usuário 
	printf("Deseja digitar o caminho do arquivo? \n");
	printf("--- Digite 1 para SIM ---\n");
	printf("--- Digite 2 para NAO --- \n");
	printf("Digite aqui: ");
	scanf("%hhd", &aux);
	
	if (aux == VERDADEIRO) {
		printf("Por favor, digite o caminho do arquivo de texto [exemplo: arquivoDeTeste.txt]: ");
		getchar();
		fgets(caminhoDoArquivo, CAMINHO_MAXIMO_ARQUIVO, stdin);
		
		//Feito pra tirar o '\n' e incluir o '\0'
		caminhoDoArquivo[strlen(caminhoDoArquivo) - 1] = '\0';

		// Abrindo arquivo indicado pelo usuário
		arquivoUsuario = fopen(caminhoDoArquivo, "r");

		// Verifica se o arquivo abriu corretamente
		if (arquivoUsuario == NULL) {
			perror("Falha ao abrir o arquivo \n");
		}
		
		// Varre todo o arquivo
		while (!feof(arquivoUsuario)) {
			caractereProcessado = fscanf(arquivoUsuario, "%c", &comparador);
		
			// Compara se tem quebra de linha	|| Compara se o caracter lido é válido, ou seja, Caracter Processado == 1 
			if ((comparador == '\n') && (caractereProcessado == CONFIRMA_CARACTERE)) {
				somador++;
			}
		}

		// Fecha o arquivo
		fclose(arquivoUsuario);
		
		// Método de contorno para incrementando a última linha que o programa não pega de um arquivo externo	
		somador++;
		
		// Exibe a informação para o usuário
		printf("\n");
		printf("O arquivo analisado possui %hd Linhas \n", somador);
	}else if (aux != VERDADEIRO) {
		// Abre o arquivo padrão
		arquivoPadrao = fopen(ARQUIVO, "r");
		
		// Verifica se o arquivo abriu corretamente
		if (arquivoPadrao == NULL) {
			perror("Falha ao abrir o arquivo \n");
		}
		
		// Varre todo o arquivo
		while (!feof(arquivoPadrao)) {
			caractereProcessado = fscanf(arquivoPadrao, "%c", &comparador);
		
			// Compara se tem quebra de linha	|| Compara se o caracter lido é válido, ou seja, Caracter Processado == 1 
			if ((comparador == '\n') && (caractereProcessado == CONFIRMA_CARACTERE)) {
				somador++;
			}
		}
		
		// Fecha o arquivo
		fclose(arquivoPadrao);
		
		// Exibe a informação para o usuário
		printf("\n");
		printf("O arquivo analisado possui %hd Linhas \n", somador);
	}
}

//Função para executar o exercício 02 - Contador de Caracteres
void exercicio02(void) {
	// Variáveis utilizadas 
	FILE* arquivoPadrao;
	FILE* arquivoUsuario;
	uint32_t somador = INITSOMADOR;
	uint8_t aux;
	char comparador, caractereProcessado;
	char caminhoDoArquivo[CAMINHO_MAXIMO_ARQUIVO];

	// Opção de arquivo padrão ou entrada por usuário 
	printf("Deseja digitar o caminho do arquivo? \n");
	printf("--- Digite 1 para SIM ---\n");
	printf("--- Digite 2 para NAO --- \n");
	printf("Digite aqui: ");
	scanf("%hhd", &aux);

	if (aux == VERDADEIRO) {
		printf("Por favor, digite o caminho do arquivo de texto [exemplo: arquivoDeTeste.txt]: ");
		getchar();
		fgets(caminhoDoArquivo, CAMINHO_MAXIMO_ARQUIVO, stdin);

		//Feito pra tirar o '\n' e incluir o '\0'
		caminhoDoArquivo[strlen(caminhoDoArquivo) - 1] = '\0';

		// Abrindo arquivo indicado pelo usuário
		arquivoUsuario = fopen(caminhoDoArquivo, "r");

		// Verifica se o arquivo abriu corretamente
		if (arquivoUsuario == NULL) {
			perror("Falha ao abrir o arquivo \n");
		}

		// Varre todo o arquivo
		while (!feof(arquivoUsuario)) {
			caractereProcessado = fscanf(arquivoUsuario, "%c", &comparador);

			// Compara se tem quebra de linha	|| Compara se o caracter lido é válido, ou seja, Caracter Processado == 1 
			if ((comparador != '\n') && (comparador != ' ') && (caractereProcessado == CONFIRMA_CARACTERE)) {
				somador++;
			}
		}

		// Fecha o arquivo
		fclose(arquivoUsuario);

		// Exibe a informação para o usuário
		printf("\n");
		printf("O arquivo analisado possui %d Caracteres \n", somador);
	}
	else if (aux != VERDADEIRO) {
		// Abre o arquivo padrão
		arquivoPadrao = fopen(ARQUIVO, "r");

		// Verifica se o arquivo abriu corretamente
		if (arquivoPadrao == NULL) {
			perror("Falha ao abrir o arquivo \n");
		}

		// Varre todo o arquivo
		while (!feof(arquivoPadrao)) {
			caractereProcessado = fscanf(arquivoPadrao, "%c", &comparador);

			// Compara se tem quebra de linha	|| Compara se o caracter lido é válido, ou seja, Caracter Processado == 1 
			if ((comparador != '\n') && (comparador != ' ') && (caractereProcessado == CONFIRMA_CARACTERE)) {
				somador++;
			}
		}

		// Fecha o arquivo
		fclose(arquivoPadrao);

		// Exibe a informação para o usuário
		printf("\n");
		printf("O arquivo analisado possui %d caracteres \n", somador);
	}

}

//Função para executar o exercício 03 e 04 simultâneamente - Cadastro de Alunos e notas + Devio Padrão e Variância
void exercicio03(void) {
	// Variáveis utilizadas
	FILE* arquivoDeManipulacao;
	infoCadastro_t * infoAluno;
	uint16_t quantAlunos;
	uint8_t i, j;
	char questao04;
	char caminhoDoArquivo[CAMINHO_MAXIMO_ARQUIVO];
	float somador = INITSOMADOR, somadroGeral = INITSOMADOR, somadorVariancia = INITSOMADOR;
	float mediaGeral, desvio, variancia, desvioPadrao, varianciaExp;
	
	// Obter quantidade de alunos para alocar a memória
	printf("Quantos alunos deseja cadastrar? ");
	scanf("%hd", &quantAlunos);
	infoAluno = criaDadosDosAlunos(quantAlunos);
	
	// Loop para receber e armazenar os nomes dos alunos e suas notas
	for (i = INITCONT; i < quantAlunos; i++) {
		printf("Por favor, informe o nome do %hhd Aluno: ", (i + 1));
		getchar();
		fgets(infoAluno[i].nomeDoAluno, QUANTIDADE_MAXIMA_NOME, stdin);
		for (j = INITCONT; j < QUANTIDADE_DE_PROVAS; j++) {
			printf("Por favor, informe a nota da %hhd Prova: ", (j + 1));
			scanf("%f", &(infoAluno[i].notas[j]));
			somador += infoAluno[i].notas[j];
		}
		somadroGeral += somador;
		infoAluno[i].media = ((somador * 1.0f) / QUANTIDADE_DE_PROVAS);
		//Limpando a memória do somador de notas
		somador = INITSOMADOR;
	}

	//Calculo da média geral dos alunos
	mediaGeral = ((somadroGeral * 1.0f) / quantAlunos);
	//Loop calculo de variância e desvio
	for (i = INITCONT; i < quantAlunos; i++) {
		//Calculo do Desvio (Media do aluno - Media geral)
		desvio = (mediaGeral - infoAluno[i].media);
		//Calculo da Variância
		varianciaExp = (float)pow(desvio, EXPOENTE);
		somadorVariancia += varianciaExp;
		varianciaExp = INITSOMADOR;
		desvio = INITSOMADOR;
	}
	// Calculo de Variância = Somatorio de todas os desvios ao quadrado dividido pela média geral
	variancia = ((somadorVariancia * 1.0f) / mediaGeral);
	// Calculo de desvio Padrão = Raiz quadrada da Variância
	desvioPadrao = (float)pow(variancia, RAIZ);

	// Criar arquivo definido pelo usuário
	printf("\n#### Por favor, digite o nome e o caminho do arquivo para armazenar a lista de alunos preenchida anteriormente #### \n");
	printf("%10c ######## Exemplo: ./Alunos_do_Primeiro_ano.txt ########\n", ' ');
	printf("Se ja houver um arquivo com esse nome, ele sera substituido! \n");
	getchar();
	fgets(caminhoDoArquivo, CAMINHO_MAXIMO_ARQUIVO, stdin);
	
	//Retira o \n do final do caminho do arquivo e substitui por \0
	caminhoDoArquivo[strlen(caminhoDoArquivo) - 1] = '\0';
	
	//Abre o arquivo com o direcionamento indicado pelo usuário
	arquivoDeManipulacao = fopen(caminhoDoArquivo, "w");
	
	//Testa se abriu o arquivo corretamente
	if (arquivoDeManipulacao == NULL) {
		perror("Falha ao abrir arquivo");
	}
	//O primeiro dado do arquivo será quantos alunos foram cadastrados
	fprintf(arquivoDeManipulacao, "%hd \t", quantAlunos);
	//Cadastrando nome e nota de alunos
	for (i = INITCONT; i < quantAlunos; i++) {
		fprintf(arquivoDeManipulacao, "Nome: %s \t", infoAluno[i].nomeDoAluno);
		for (j=INITCONT; j < QUANTIDADE_DE_PROVAS; j++){
			fprintf(arquivoDeManipulacao, "[%hhd Prova [%0.2f] ] \t", (j + 1), infoAluno[i].notas[j]);
		}
		fprintf(arquivoDeManipulacao, "Média [%.2f] \n", infoAluno[i].media);
	}
	// Adicionar os dados de variância e desvio padrão ao arquivo
	fprintf(arquivoDeManipulacao, "[Desvio Padrão: %0.2f] \t [Variância: %0.2f]", desvioPadrao, variancia);
	//Fechar o arquivo de gravação
	fclose(arquivoDeManipulacao);

	//Exibir os dados na tela
	for (i = INITCONT; i < quantAlunos; i++) {
		printf("Nome: %s \t", infoAluno[i].nomeDoAluno);
		for (j = INITCONT; j < QUANTIDADE_DE_PROVAS; j++) {
			printf("[%hhd Prova [%0.2f] ] \t", (j + 1), infoAluno[i].notas[j]);
		}
		printf("Média [%.2f] \n", infoAluno[i].media);
	}

	// Exibir a função para a questão 04 - Mostrar ou não a variância e o desvio padrão
	printf("\nDeseja exibir os dados de variancia e desvio padrao [S/N]? ");
	scanf("%c", &questao04);
	
	// Exibir variância e desvio
	if ((questao04 == 'S') || (questao04 == 's')) {
		printf("\nOs dados apresentam [%0.2f de Variancia] e [%0.2f de Desvio Padrao]\n", variancia, desvioPadrao);
	}
	
	//Libera memória alocada
	free(infoAluno);
}

//Função Main~> Chama o Menu de exercício e as funções para executar as opções 
int main(int argc, char** argv) {
	uint8_t exercicio;
	
	//Repetir o menu até a entrada 0 do usuário
	do {
		//Complemento do Menu
		imprimeMenu();
		printf("Dado o menu acima, digite um numero para executar o exercicio desejado: ");
		scanf("%hhd", &exercicio);
		printf("\n");

		//Chamada de funções dos exercícios 
		switch (exercicio) {
			case 0: {
				break;
			}
			case 1: {
				criaArquivo();
				exercicio01();
				break;
			}
			case 2: {
				criaArquivo();
				exercicio02();
				break;
			}
			case 3: {
				exercicio03();
				break;
			}
		
		}
	} while (exercicio != 0);

	//Se tudo deu certo
	return SUCESSO;
}