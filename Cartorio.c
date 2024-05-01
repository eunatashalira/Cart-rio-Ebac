#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h>	//biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por ciudar das strings(conjunto de variaveis)


int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variaveis/string (conjunto de variaveis
	char arquivo[40]; //o número 40 se refere a quantidade caracteres
	char cpf[40]; //o número 40 se refere a quantidade caracteres
	char nome[40]; //o número 40 se refere a quantidade caracteres
	char sobrenome[40]; //o número 40 se refere a quantidade caracteres
	char cargo[40]; //o número 40 se refere a quantidade caracteres
	//Final da criaçãode variaveis/string (conjunto de variaveis
	
	printf("Digitar o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //armazena a variavel

	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; //chama uma função e cria o arquivo
	file = fopen(arquivo , "w"); // quando queremos escrever usamos W que vem do inglês write / cria o arquivo
	fprintf(file,cpf); //salva no arquivo o valor da váriavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // a letra "a" significa atualização
	fprintf(file, ","); //salvando os dados separados por virgula
	fclose(file); //fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",nome); //%s se refere a string, armazenando/salvando
	
	file = fopen(arquivo, "a"); //criando o arquivo e atualizando
	fprintf(file,nome); //salva o nome na variavel
	fclose(file);	//fecha o arquivo
	
	
	file = fopen(arquivo, "a"); //criando o arquivo e atualizando
	fprintf(file, ","); //salvando os dados separados por virgula
	fclose(file);//fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",sobrenome); //armazenando e salvando
	
	file = fopen(arquivo, "a"),//criando o arquivo e atualizando
	fprintf(file,sobrenome); //salvando os dados 
	fclose(file); //fechando o arquivo
	
	
	file = fopen(arquivo, "a"); //criando o arquivo e atualizando
	fprintf(file, ","); //salvando os dados separados por virgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "), //coletando informações do usuário
	scanf("%s",cargo); //%s se refere a string, armazenando/salvando
	
	file = fopen(arquivo, "a");//criando o arquivo e atualizando
	fprintf(file,cargo); //salvando os dados 
	fclose(file); //fechando o arquivo
	
	system("pause"); //pausa no sistema para o usuário ler
	

}

int consultar()
//inicio da criação das variaveis
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem, por conta dos acentos
	
	char cpf[40]; //o número 40 se refere a quantidade caracteres
	char conteudo [200]; //somente 200 caracteres
	
	
	printf("Digite o CPF a ser consultado: "); //coletando informações do usuário
	scanf("%s",cpf); //conjunto de variaiveis/string salvando e armazenando
	
	FILE *file; //chama uma função e cria o arquivo
	file = fopen(cpf,"r"); // A letra "r" é de ler (read)
	
	if(file == NULL) //caso o arquivo não localize
	
	{
		printf("Não foi possível abrir o arquivo, não locaizado!. n/"); //resposta do sistema de acordo com a solicitação anterior
	}


	while(fgets(conteudo, 200, file)!=NULL) //laço de repetição
	{
		printf("\nEssas são as informações do usuário: "); //resposta do sistema de acordo com a solicitação anterior
		printf("%s", conteudo); //%s se refere a string, armazenando/salvando
		printf("\n\n"); //espaço
	}
	

	system("pause"); //pausa no sistema para o usuário ler

//fim da criação
}

int deletar()
//inicio da criação
{
	char cpf [40]; //quantidade de cacteres
	
	printf("Digite o CPF a ser deletado: "); //coletando informações do usuário
	scanf("%s",cpf); //%s se refere a string, armazenando/salvando
	
	remove(cpf); //excluindo dado solicitado
	
	FILE *file; //chama uma função e cria o arquivo
	file = fopen(cpf,"r"); // lendo o dado solicitado (read)
	
	if(file == NULL) //arquivo não localizado
	{
		printf("O usuário não se encontra no sistema! \n"); //resposta do sistema de acordo com a solicitação anterior
		system("pause"); //pausa no sistema para o usuário ler
		
	}
 } //fim da criação


int main()
{
	int opcao=0; //Definindo as varíaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	
		{

	
	
	system("cls"); //responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	printf("Escolha a opção desejada:\n\n"); //mensagem de opção para o user
	printf("\t1 - Registrar nomes\n"); // o barra t é somente para um espaço  | opção de escolha
	printf("\t2 - Consultar nomes\n"); //opção de escolha
	printf("\t3 - Deletar nomes\n"); //opção de escolha
	printf("\t4 - Sair do sistema\n\n\n");//opção de escolha
	printf("Opção"); //fim do menu
	
    scanf("%d", &opcao); //armazenando a escolha do usuario
    
    system("cls"); //limpa a tela
    
    switch(opcao) //inicio da seleção do menu
    
    {
    	case 1: //opção 1
    	registro(); //chamada de funções
    	break; 
    	
    	case 2: //opção 2
    	consultar();//chamada de funções
    	break;
    	
    	case 3: //opção 3
    	deletar();	//chamada de funções
    	break;
    	
    	case 4: //opção 4
    	printf("Obrigada por utilizar o sistema!\n"); //chamdaa de função
    	return 0; //retornar o valor a zero, ou seja, quebra laço, função, etc e sai do sistema
    	break;
    	
    	
    	default:
    	printf("Essa opção não está disponivel!\n"); //resposta do sistema de acordo com a solicitação anterior
		system("pause");  //pausa no sistema para o usuário ler
		break;
		
    	
	}
    
   	//fim da seleção	
	
	
	}
	
	
	
}
