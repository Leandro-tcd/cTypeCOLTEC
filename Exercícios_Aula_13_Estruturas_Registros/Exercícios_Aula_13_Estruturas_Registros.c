#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCESSO 0
#define TAMANHO_MAXIMO_DO_NOME (65+1)
#define TAMANHO_MAXIMO_DO_CURSO (60+1)
#define DATA_DE_NASCIMENTO (10+1)
#define TAMANO_MAXIMO_DO_VETOR_NOTAS 3
#define INICIAINDC 0
#define MEDIA_DO_ALUNO 6.0
#define INICIAVARIAVELZERO 0
#define INICIAVARIAVEL 948548
#define TAMANHO_DA_CLASSIFICACAO 3

typedef struct cadastro_aluno_s {
	char nomeDoAluno[TAMANHO_MAXIMO_DO_NOME];
	char nomeDoCurso[TAMANHO_MAXIMO_DO_CURSO];
	char dataDeNascimento[DATA_DE_NASCIMENTO];
	float notaDoAluno[TAMANO_MAXIMO_DO_VETOR_NOTAS];
	float mediaIndividual;
} cadastroAluno_t;


cadastroAluno_t* alocaMemoriaParaNotas(uint16_t quantidadeDeAlunos) {
	return (cadastroAluno_t*)malloc(quantidadeDeAlunos * sizeof(cadastroAluno_t));
}

uint16_t perguntaQuantidadeDeAlunos(void) {
	uint16_t quantidadeDeAlunos;
	printf("Por favor, informe para o sistema, quantos alunos voce deseja cadastrar: ");
	scanf("%hd", &quantidadeDeAlunos);
	return quantidadeDeAlunos;
}

void imprimeMenuDeQuestoes(void) {
	printf("Os exercicios disponiveis para essa semana, sao:\n");
	printf("[1] para informar os dados de um aluno\n");
	printf("[2] para fornecer os dados do aluno e calcular sua media\n");
	printf("[3] para inserir os dados de N alunos e calcular as medias individuais e geral\n");
	printf("[4] para incluir e receber os dados e a media de N alunos em ordem crescente\n");
	printf("[0] para Sair.\n");
}

void separaMenu(void) {
	printf("\n");
	printf("========================================================================");
	printf("\n");
}

void exercicio01(void) {
	cadastroAluno_t entradaInformacaoDoAluno;
	getchar();
	printf("Por favor, insira o nome do aluno: ");
	fgets(entradaInformacaoDoAluno.nomeDoAluno, TAMANHO_MAXIMO_DO_NOME, stdin);
	printf("Agora, insira o nome do curso: ");
	fgets(entradaInformacaoDoAluno.nomeDoCurso, TAMANHO_MAXIMO_DO_CURSO, stdin);
	printf("Por fim, insira a sua data de nascimento dd/mm/aaaa: ");
	fgets(entradaInformacaoDoAluno.dataDeNascimento, DATA_DE_NASCIMENTO, stdin);
	printf("\nNome:%s \nCurso:%s \nData de Nascimento:%s \n", entradaInformacaoDoAluno.nomeDoAluno, entradaInformacaoDoAluno.nomeDoCurso, entradaInformacaoDoAluno.dataDeNascimento);
}

void exercicio02(void) {
	cadastroAluno_t entradaInformacaoDoAluno;
	uint8_t i;
	float soma, media;
	soma = INICIAVARIAVELZERO;
	media = INICIAVARIAVEL;
	getchar();
	printf("Por favor, insira o nome do aluno: ");
	fgets(entradaInformacaoDoAluno.nomeDoAluno, TAMANHO_MAXIMO_DO_NOME, stdin);
	printf("Em seguida, insira o nome do curso: ");
	fgets(entradaInformacaoDoAluno.nomeDoCurso, TAMANHO_MAXIMO_DO_CURSO, stdin);
	printf("Por fim, insira a sua data de nascimento dd/mm/aaaa: ");
	fgets(entradaInformacaoDoAluno.dataDeNascimento, DATA_DE_NASCIMENTO, stdin);
	printf("Agora, informe as notas das tres provas \n");
	for (i = INICIAINDC; i < TAMANO_MAXIMO_DO_VETOR_NOTAS; i++) {
		printf("Digite a nota da prova %hhd: ",i);
		scanf("%f", &(entradaInformacaoDoAluno.notaDoAluno[i]));
		soma += entradaInformacaoDoAluno.notaDoAluno[i];
	}
	media = ((soma * 1.0f) / TAMANO_MAXIMO_DO_VETOR_NOTAS);
	if (media > MEDIA_DO_ALUNO) {
		printf("\nParabens, voce foi aprovado com a media %.2f", media);
	}
	else {
		printf("Infelizmente voce esta abaixo da media. Verifique se sua nota lhe da direito a reculperacao \n");
		printf("Sua nota foi: %.2f", media);
	}
}

void exercicio03(void) {
	cadastroAluno_t* enderecoDaEntradaDeInformacaoDoAluno;
	uint16_t entradaQuantidadeDeAlunos, i, j;
	float soma = INICIAVARIAVELZERO;
	float somaGeral = INICIAVARIAVELZERO;
	float mediaGeral = INICIAVARIAVELZERO;
	char* classificacao[TAMANHO_DA_CLASSIFICACAO];
	classificacao[0] = "Primeira";
	classificacao[1] = "Segunda";
	classificacao[2] = "Terceira";
	entradaQuantidadeDeAlunos = perguntaQuantidadeDeAlunos();
	enderecoDaEntradaDeInformacaoDoAluno = alocaMemoriaParaNotas(entradaQuantidadeDeAlunos);
	getchar();
	for (i = INICIAINDC; i < entradaQuantidadeDeAlunos; i++) {
		printf("Por favor, insira o nome do aluno: ");
		fgets(enderecoDaEntradaDeInformacaoDoAluno[i].nomeDoAluno, TAMANHO_MAXIMO_DO_NOME, stdin);
		printf("Em seguida, insira o nome do curso: ");
		fgets(enderecoDaEntradaDeInformacaoDoAluno[i].nomeDoCurso, TAMANHO_MAXIMO_DO_CURSO, stdin);
		printf("Por fim, insira a sua data de nascimento dd/mm/aaaa: ");
		fgets(enderecoDaEntradaDeInformacaoDoAluno[i].dataDeNascimento, DATA_DE_NASCIMENTO, stdin);
	}
	for (i = INICIAINDC; i < entradaQuantidadeDeAlunos; i++) {
		for (j = INICIAINDC; j < TAMANO_MAXIMO_DO_VETOR_NOTAS; j++) {
			printf("Digite a %s nota do aluno %s: ", classificacao[j], enderecoDaEntradaDeInformacaoDoAluno[i].nomeDoAluno);
			scanf(" %f", &(enderecoDaEntradaDeInformacaoDoAluno[i].notaDoAluno[j]));
			soma += enderecoDaEntradaDeInformacaoDoAluno[i].notaDoAluno[j];
		}
		somaGeral += soma;
		enderecoDaEntradaDeInformacaoDoAluno[i].mediaIndividual = ((soma * 1.0f) / TAMANO_MAXIMO_DO_VETOR_NOTAS);
		soma = INICIAVARIAVELZERO;
	}
	for (i = INICIAINDC; i < entradaQuantidadeDeAlunos; i++) {
		printf("Nome: %s \n", enderecoDaEntradaDeInformacaoDoAluno[i].nomeDoAluno);
		printf("Curso: %s\n", enderecoDaEntradaDeInformacaoDoAluno[i].nomeDoCurso);
		printf("Data de Nascimento: %s\n", enderecoDaEntradaDeInformacaoDoAluno[i].dataDeNascimento);
		printf("Media Individual: %.2f\n", enderecoDaEntradaDeInformacaoDoAluno[i].mediaIndividual);
		printf("\n");
	}
	mediaGeral = ((somaGeral * 1.0f) / entradaQuantidadeDeAlunos);
	printf("Media geral dos Alunos %.2f", mediaGeral);
	free(enderecoDaEntradaDeInformacaoDoAluno);
}
// A parte do código para por em ordem naão está funcional exercicio 04 == exercicio 03
void exercicio04(void) {
	cadastroAluno_t* enderecoDaEntradaDeInformacaoDoAluno;
	uint16_t entradaQuantidadeDeAlunos, i, j;
	float soma = INICIAVARIAVELZERO;
	float somaGeral = INICIAVARIAVELZERO;
	float mediaGeral = INICIAVARIAVELZERO;
	float auxiliar = INICIAVARIAVEL;
	char* classificacao[TAMANHO_DA_CLASSIFICACAO];
	classificacao[0] = "Primeira";
	classificacao[1] = "Segunda";
	classificacao[2] = "Terceira";
	entradaQuantidadeDeAlunos = perguntaQuantidadeDeAlunos();
	enderecoDaEntradaDeInformacaoDoAluno = alocaMemoriaParaNotas(entradaQuantidadeDeAlunos);
	getchar();
	for (i = INICIAINDC; i < entradaQuantidadeDeAlunos; i++) {
		printf("Por favor, insira o nome do aluno: ");
		fgets(enderecoDaEntradaDeInformacaoDoAluno[i].nomeDoAluno, TAMANHO_MAXIMO_DO_NOME, stdin);
		printf("Em seguida, insira o nome do curso: ");
		fgets(enderecoDaEntradaDeInformacaoDoAluno[i].nomeDoCurso, TAMANHO_MAXIMO_DO_CURSO, stdin);
		printf("Por fim, insira a sua data de nascimento dd/mm/aaaa: ");
		fgets(enderecoDaEntradaDeInformacaoDoAluno[i].dataDeNascimento, DATA_DE_NASCIMENTO, stdin);
	}
	for (i = INICIAINDC; i < entradaQuantidadeDeAlunos; i++) {
		for (j = INICIAINDC; j < TAMANO_MAXIMO_DO_VETOR_NOTAS; j++) {
			printf("Digite a %s nota do aluno %s: ", classificacao[j], enderecoDaEntradaDeInformacaoDoAluno[i].nomeDoAluno);
			scanf(" %f", &(enderecoDaEntradaDeInformacaoDoAluno[i].notaDoAluno[j]));
			soma += enderecoDaEntradaDeInformacaoDoAluno[i].notaDoAluno[j];
		}
		somaGeral += soma;
		enderecoDaEntradaDeInformacaoDoAluno[i].mediaIndividual = ((soma * 1.0f) / TAMANO_MAXIMO_DO_VETOR_NOTAS);
		soma = INICIAVARIAVELZERO;
	}
	//Função para colocar em ordem ==== NÃO FUNCIONAL ====
	for (i = INICIAINDC; i < entradaQuantidadeDeAlunos; i++) {
		for (j = INICIAINDC + 1; j < entradaQuantidadeDeAlunos; j++) {
			if (enderecoDaEntradaDeInformacaoDoAluno[i].mediaIndividual < enderecoDaEntradaDeInformacaoDoAluno[j].mediaIndividual) {
				auxiliar = enderecoDaEntradaDeInformacaoDoAluno[i].mediaIndividual;
				enderecoDaEntradaDeInformacaoDoAluno[i].mediaIndividual = enderecoDaEntradaDeInformacaoDoAluno[j].mediaIndividual;
				enderecoDaEntradaDeInformacaoDoAluno[j].mediaIndividual = auxiliar;
			}
		}
	}
	for (i = INICIAINDC; i < entradaQuantidadeDeAlunos; i++) {
		printf("Nome: %s \n", enderecoDaEntradaDeInformacaoDoAluno[i].nomeDoAluno);
		printf("Curso: %s\n", enderecoDaEntradaDeInformacaoDoAluno[i].nomeDoCurso);
		printf("Data de Nascimento: %s\n", enderecoDaEntradaDeInformacaoDoAluno[i].dataDeNascimento);
		printf("Media Individual: %.2f\n", enderecoDaEntradaDeInformacaoDoAluno[i].mediaIndividual);
		printf("\n");
	}
	mediaGeral = ((somaGeral * 1.0f) / entradaQuantidadeDeAlunos);
	printf("Media geral dos Alunos %.2f", mediaGeral);
	free(enderecoDaEntradaDeInformacaoDoAluno);

}

int main(int argc, char** argv) {
	uint8_t exercicio;
	do {
		imprimeMenuDeQuestoes();
		printf("Por favor, digite o numero referente ao exercicio que deseja executar: ");
		scanf("%hhd", &exercicio);
		switch (exercicio) {
			case 0: {
				break;
			}
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
			default: {
				printf("ERROR! Numero de exercicio informado nao corresponde aos listados acima. Por favor, tente novamente");
				printf("\n");
			}
		}
		separaMenu();
	} while (exercicio != 0);

	return SUCESSO;
}