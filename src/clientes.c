#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente
 {
	int usado;
	char nome[20];
	char cpf[11];
	char email[25];
 } ;

struct listac
 {
	struct cliente cliente[15];
	int tam;
 } ;

void inicializa_clientes(struct listac *lista)
 {
	int i;
	for (i=0;i<=15;i++)
	 lista->cliente[i].usado=0;
	lista->tam=0;
 }

void imprime_lista_clientes(struct listac *lista)
 {
	int i;
	printf("|-------NOME---------|---CPF----|-------E-MAIL-------|\n");
	for (i=0;i<=lista->tam;i++)
	 if (lista->cliente[i].usado==1)
		 {
			printf("|%20s",lista->cliente[i].nome);
			printf("|%10s",lista->cliente[i].cpf);
			printf("|%20s",lista->cliente[i].email);
			printf("|\n");
		 }
	printf("|--------------------|----------|--------------------|\n");
 }

void le_cliente(int pos,struct listac *lista)
 {
	printf("Escreva o nome do Cliente:");
	scanf("%s",lista->cliente[pos].nome);
	printf("Escreva o CPF do cliente:");
	//implementar o teste para ver se o CPF eh valido e se nao existe igual
	scanf("%s",lista->cliente[pos].cpf);
	printf("Escreva o E-Mail do cliente:");
	scanf("%s",lista->cliente[pos].email);
  lista->cliente[pos].usado=1;
 }

void add_cliente(struct listac *lista)
 {
	int cont=0,aux,achou=0;
	while ((!achou)&&(cont<=lista->tam))
	 {
		if (lista->cliente[cont].usado==0)
		 {
			aux=cont;
			achou=1;
		 }
		cont++;
	 }
	if (achou)
	 le_cliente(aux,lista);
	else
	 {
		lista->tam++;
		le_cliente(lista->tam,lista);
	 }
 }

void remove_cliente(struct listac *lista)
	{
	 int cont=1,aux,achou=0,opcao;
	 char cpf[11];
	 printf("Digite o cpf do cliente a ser removido:");
	 scanf("%s",cpf);
	 while ((!achou)&&(cont<=lista->tam))
		{
		 if (strcmp(cpf,lista->cliente[cont].cpf)==0)
			{
			 achou=1;
			 aux=cont;
			}
		 cont++;
		}
	 if (achou)
		{
		 printf("Voce tem certeza q deseja remover o cliente %s?\n1:sim\n2:nao\n",lista->cliente[aux].nome);
		 scanf("%d",&opcao);
			if (opcao)
			 {
				lista->cliente[aux].usado=0;
				// completar a remocao dos outros itens
			 }
		}
	 else
		printf("Cliente nao econtrado\n");
	}

void edita_cliente(struct listac *lista)
 {
	int pos,opcao;
	char cpf[11];
	printf("qual eh o cpf do cliente a ser editado?");
	scanf("%s",cpf);
	printf("qual coluna vc gostaria de editar?\n11:nome\n2:CPF\n3:to pensando ainda");
	scanf("%d",&opcao);
	pos=checa_cliente_cpf(cpf,lista);
	if (pos>=0)
	 switch (opcao)
		{
		 case 1:printf("Qual eh o novo nome do cliente %s?\n",lista->cliente[pos].nome);
						scanf("%s",lista->cliente[pos].nome);break;
		 case 2:printf("Qual eh o novo CPF do cliente %s?\n",lista->cliente[pos].nome);
						scanf("%s",lista->cliente[pos].cpf);break;
		 case 3:break;
		}

 }

int checa_cliente_cpf(char *cpf,struct listac *lista)
 {
	int i=0,achou=0,pos;
	while((!achou)&&(i<=lista->tam))
	 {
		if (lista->cliente[i].usado==1)
		 if (strcmp(lista->cliente[i].cpf,cpf)==0)
			{
			 achou=1;
			 pos=i;
			}
		 i++;
	 }
	if (achou)
	 return(pos);
	else
	 return(-1);
 }

//
// Secao black magic :)
//

int salva_clientes(struct listac lista)
 {
	FILE *stream;
	if ((stream = fopen("..//db//CLIENTES.DAT", "w+b"))== NULL)
	 {
		fprintf(stderr, "Cannot open output file.\n");
		return 1;
	 }
	fwrite(&lista ,sizeof(struct listac),lista.tam, stream);
	fclose(stream);
	return(0);
 }


int le_arq_clientes(struct listac *lista)
{
	 FILE *stream;
	 if ((stream = fopen("..//db//CLIENTES.DAT", "rb"))== NULL)
		{
		 fprintf(stderr, "Cannot open output file.\n");
		 return 1;
		}
	 rewind(stream);
	 fread(lista, sizeof(struct listac ), 50, stream);
	 fclose(stream);
	 return(0);
}

//
//fim da secao black magic
//
