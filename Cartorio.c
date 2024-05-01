#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>	//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por ciudar das strings(conjunto de variaveis)


int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de variaveis/string (conjunto de variaveis
	char arquivo[40]; //o n�mero 40 se refere a quantidade caracteres
	char cpf[40]; //o n�mero 40 se refere a quantidade caracteres
	char nome[40]; //o n�mero 40 se refere a quantidade caracteres
	char sobrenome[40]; //o n�mero 40 se refere a quantidade caracteres
	char cargo[40]; //o n�mero 40 se refere a quantidade caracteres
	//Final da cria��ode variaveis/string (conjunto de variaveis
	
	printf("Digitar o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //armazena a variavel

	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; //chama uma fun��o e cria o arquivo
	file = fopen(arquivo , "w"); // quando queremos escrever usamos W que vem do ingl�s write / cria o arquivo
	fprintf(file,cpf); //salva no arquivo o valor da v�riavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // a letra "a" significa atualiza��o
	fprintf(file, ","); //salvando os dados separados por virgula
	fclose(file); //fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",nome); //%s se refere a string, armazenando/salvando
	
	file = fopen(arquivo, "a"); //criando o arquivo e atualizando
	fprintf(file,nome); //salva o nome na variavel
	fclose(file);	//fecha o arquivo
	
	
	file = fopen(arquivo, "a"); //criando o arquivo e atualizando
	fprintf(file, ","); //salvando os dados separados por virgula
	fclose(file);//fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",sobrenome); //armazenando e salvando
	
	file = fopen(arquivo, "a"),//criando o arquivo e atualizando
	fprintf(file,sobrenome); //salvando os dados 
	fclose(file); //fechando o arquivo
	
	
	file = fopen(arquivo, "a"); //criando o arquivo e atualizando
	fprintf(file, ","); //salvando os dados separados por virgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "), //coletando informa��es do usu�rio
	scanf("%s",cargo); //%s se refere a string, armazenando/salvando
	
	file = fopen(arquivo, "a");//criando o arquivo e atualizando
	fprintf(file,cargo); //salvando os dados 
	fclose(file); //fechando o arquivo
	
	system("pause"); //pausa no sistema para o usu�rio ler
	

}

int consultar()
//inicio da cria��o das variaveis
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem, por conta dos acentos
	
	char cpf[40]; //o n�mero 40 se refere a quantidade caracteres
	char conteudo [200]; //somente 200 caracteres
	
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //conjunto de variaiveis/string salvando e armazenando
	
	FILE *file; //chama uma fun��o e cria o arquivo
	file = fopen(cpf,"r"); // A letra "r" � de ler (read)
	
	if(file == NULL) //caso o arquivo n�o localize
	
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o locaizado!. n/"); //resposta do sistema de acordo com a solicita��o anterior
	}


	while(fgets(conteudo, 200, file)!=NULL) //la�o de repeti��o
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //resposta do sistema de acordo com a solicita��o anterior
		printf("%s", conteudo); //%s se refere a string, armazenando/salvando
		printf("\n\n"); //espa�o
	}
	

	system("pause"); //pausa no sistema para o usu�rio ler

//fim da cria��o
}

int deletar()
//inicio da cria��o
{
	char cpf [40]; //quantidade de cacteres
	
	printf("Digite o CPF a ser deletado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s se refere a string, armazenando/salvando
	
	remove(cpf); //excluindo dado solicitado
	
	FILE *file; //chama uma fun��o e cria o arquivo
	file = fopen(cpf,"r"); // lendo o dado solicitado (read)
	
	if(file == NULL) //arquivo n�o localizado
	{
		printf("O usu�rio n�o se encontra no sistema! \n"); //resposta do sistema de acordo com a solicita��o anterior
		system("pause"); //pausa no sistema para o usu�rio ler
		
	}
 } //fim da cria��o


int main()
{
	int opcao=0; //Definindo as var�aveis
	int laco=1;
	
	for(laco=1;laco=1;)
	
		{

	
	
	system("cls"); //responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	printf("Escolha a op��o desejada:\n\n"); //mensagem de op��o para o user
	printf("\t1 - Registrar nomes\n"); // o barra t � somente para um espa�o  | op��o de escolha
	printf("\t2 - Consultar nomes\n"); //op��o de escolha
	printf("\t3 - Deletar nomes\n"); //op��o de escolha
	printf("\t4 - Sair do sistema\n\n\n");//op��o de escolha
	printf("Op��o"); //fim do menu
	
    scanf("%d", &opcao); //armazenando a escolha do usuario
    
    system("cls"); //limpa a tela
    
    switch(opcao) //inicio da sele��o do menu
    
    {
    	case 1: //op��o 1
    	registro(); //chamada de fun��es
    	break; 
    	
    	case 2: //op��o 2
    	consultar();//chamada de fun��es
    	break;
    	
    	case 3: //op��o 3
    	deletar();	//chamada de fun��es
    	break;
    	
    	case 4: //op��o 4
    	printf("Obrigada por utilizar o sistema!\n"); //chamdaa de fun��o
    	return 0; //retornar o valor a zero, ou seja, quebra la�o, fun��o, etc e sai do sistema
    	break;
    	
    	
    	default:
    	printf("Essa op��o n�o est� disponivel!\n"); //resposta do sistema de acordo com a solicita��o anterior
		system("pause");  //pausa no sistema para o usu�rio ler
		break;
		
    	
	}
    
   	//fim da sele��o	
	
	
	}
	
	
	
}
