#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	
	printf("Digita o CPF a ser cadastrado: ");

	scanf("%s", cpf); // %s refere se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o W significa escrever
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, "/Nome:"); //implementei essa informação para ficar mais intuitivo na hora de consultar
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //cria o arquivo e o a significa atualizar
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "/Sobrenome:");//implementei essa informação para ficar mais intuitivo na hora de consultar
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "/Cargo:");//implementei essa informação para ficar mais intuitivo na hora de consultar
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale (LC_ALL, "Portuguese"); //definindo linguagem
	
    char cpf[40];
    char conteudo[200];
	
    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); 
    
    if(file == NULL)
    { 
       printf("Esse arquivo não foi localizado\n");
	}
    
   
   while(fgets(conteudo, 200 , file) != NULL)
    {
    	printf("\nInformações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n");
    
	}
	
	
	system("pause");
    
    
     
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema. \n ");
		system("pause");
	
	}
	
	

}



int main()
{
	int opcao=0; //definindo variáveis 
	int x=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("###Cartório da EBAC### \n\n");
	printf("Login de admnistrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao= strcmp(senhadigitada, "admin");
	
	if(comparacao==0)
	{
		
		system("cls");
		for(x=1; x=1;)
	   	{
	
		
        	setlocale (LC_ALL, "Portuguese"); //definindo linguagem
	
	    	printf("###Bem-vindo ao cartório da EBAC### \n\n"); //inicio do menu
	    	printf("Escolha a opção desejada no menu\n\n");
	    	printf("\t1 - Registrar nomes\n");
	    	printf("\t2 - Consultar nomes\n");
	    	printf("\t3 - Deletar nomes\n"); 
	    	printf("\t4 - Sair do sistema\n\n");
	    	printf("Opção: "); //fim do menu
	
	    	scanf("%d", &opcao); //armazenando a escolha do usuário
	
	    	system("cls");
	    
	    	switch(opcao)
	    	{
	    		case 1:
	    		registro();
		    	break;
			
				case 2:
				consulta();
		    	break;
		    
		    	case 3: 
		    	deletar();
		    	break;
		    
		    	case 4:
		    	printf("Obrigado por utilizar o sistema");
		    	return 0; 
		    
		    	default: 
		    	printf("Essa opção não está disponível\n");
		    	system("pause");
		    	break;	
			}
		}
	}
	
	else
	printf("Senha incorreta");
}
