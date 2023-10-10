#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h>// biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro(){ //funcao responsavel por cadastrar usuarios


	//criacao de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuario
	scanf("%s", cpf); // "%s" lê e armazena  a string 
	
	strcpy(arquivo, cpf);// responsavel por copiar os valores das string
	
	FILE * file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo  e o "W" escreve
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // fopen abre o arquivo. "a" mantendo o conteudo anterior
	fprintf(file, ",");// escreve uma virgula no arquivo
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause");
	
}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE * file;
	file = fopen(cpf, "r");	
	
	if(file == NULL){
		printf("\n Usuário não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar(){
	char cpf[40];
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE * file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Usuário nao se encontra no sistema!\n");
		system("pause");
		
	}
	
	fclose(file);
	
}
int main(){
	
	int opcao = 0;
	int laco = 1;
	
	for(laco=1;laco=1;){	
	
		system("cls");	

		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
		printf("======Cartório da EBAC======\n\n"); // inicio menu
		printf("Escolha a opção desejada no menu: \n\n");
		printf("\t 1-Registrar nomes\n");
		printf("\t 2-Consultar  nomes\n");
		printf("\t 3-Deletar  nomes\n");
		printf("\t 4-Sair do sistema\n");
		printf("Opção:"); // fim do menu
	
		scanf("%d", &opcao); // armazenando escolha do usuario
	
		system("cls");
		
		switch(opcao) // estrutura de escolha
		{
			case 1:
			registro(); //chamando funcao
			break; //parada 
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Opção indisponivel!\nTente novamente\n");
			system("pause");
			break;		
		}	
	}
}
	
