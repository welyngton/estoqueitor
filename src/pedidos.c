#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxpedidos 15
struct pedidos
 {
	int usado;
	int codigo;
	char cpf[11];
	int codigop;
	int quantidade;
	char data_pedido[15];
	char data_fatura[15];
 } ;

struct listap
 {
  struct pedidos pedidos[maxpedidos];
  int tam;
 } ;
void inicializa_pedidos(struct listap *lista)
 {
	int i;
	for (i=0;i<=maxpedidos;i++)
	 lista->pedidos[i].usado=0;
	lista->tam=0;
 }


/*Testa se um codigo de pedido ja esta em uso.
Caso nao esteja:retorna -1, senao retorna a posicao em que eh usado*/
int checa_codigo_pedido(int codigo,struct listap *lista)
 {

 int cont=0,achou=0,pos;

	while ((!achou)&&(cont<=lista->tam)){
		if (lista->pedidos[cont].codigop==codigo){
			achou=1;
			pos=cont;
			}
		cont++;
		}
	if (achou)
		return(pos);
	else
		return(-1);
  }





void le_pedido(int pos,struct listap *lista){

int fim=0,codigo;

	do {
		printf("Escreva o codigo do pedido: ");
		scanf("%d",&codigo);
		if (checa_codigo_pedido(codigo,lista)==-1)
			fim=1;
		else
			printf("O codigo %d ja esta sendo usado\n",codigo);
		} while (!fim);
	lista->pedidos[pos].codigop=codigo;
	printf("Informe o codigo do produto do pedido: ");
	scanf("%d",lista->pedidos[pos].codigo);
	printf("Informe o cpf do cliente que fez o pedido: ");
	scanf("%d",lista->pedidos[pos].cpf);
	printf("Informe o numero de pecas do produto para o pedido: ");
	scanf("%d",&lista->pedidos[pos].quantidade);
	printf("Informe a data do pedido: ");
	scanf("%c",&lista->pedidos[pos].data_pedido);
	printf("Informe a data da fatura do pedido: ");
	scanf("%c",&lista->pedidos[pos].data_fatura);
	lista->pedidos[pos].usado=1;
 }



void imprime_lista_pedidos(struct listap *lista)
 {
	int i;
	printf("|Codigo|----CPF----|Produto|QTD--|Data-do-Pedido|Data-da-Fatura|\n");
	for (i=0;i<=lista->tam;i++)
	 if (lista->pedidos[i].usado==1)
		{
		 printf("|%6d",lista->pedidos[i].codigo);
		 printf("|%11s",lista->pedidos[i].cpf);
		 printf("|%7d",lista->pedidos[i].codigop);
		 printf("|%5d",lista->pedidos[i].quantidade);
		 printf("|%14s",lista->pedidos[i].data_pedido);
		 printf("|%14s",lista->pedidos[i].data_fatura);
		 printf("|\n");
		}
	printf("|------|-----------|-------|-----|--------------|--------------|\n");
 }

void add_pedido(struct listap *lista)
 {
	int cont=1,aux,achou=0;
	while ((!achou)&&(cont<=lista->tam))
	 {
		if (lista->pedidos[cont].usado==0)
		 {
			aux=cont;
			achou=1;
		 }
		cont++;
	 }
	if (achou)
	 le_pedido(aux,lista);
	else
	 {
		lista->tam++;
		le_pedido(lista->tam,lista);
	 }
 }


int checa_cpf_pedidos(char *cpf,struct listap *lista)
 {
	int achou=0,pos,i=0;
	 while ((!achou)&&(i<=lista->tam))
		{
		 if (lista->pedidos[i].usado==1)
			if (strcmp(lista->pedidos[i].cpf,cpf)==0)
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


void edita_pedido(struct listap *lista)
 {
	int codigo,pos,opcao,auxcod,fim=0;
	printf("Qual eh o codigo do pedido a ser editado?");
	scanf("%d",&codigo);
	if (checa_codigo_pedido(codigo,lista) > -1)
	 {
		printf("Qual campo voce gostaria de editar?\n");
		printf("1:Codigo do pedido.\n2:CPF.\n3:Codigo do produto.\n4:Quantidade.\n5:Data do pedido.\n6:Data da fatura");
		scanf("%d",&opcao);
		pos=checa_codigo_produto(codigo,lista);
		if (pos>=0)
			 switch (opcao)
			 {
				case 1:do
								 {
									printf("Informe o novo codigo do pedido: ");
									scanf("%d",&auxcod);
									if (checa_codigo_pedido(auxcod,lista)!=-1)
									fim=1;
								 } while (!fim);
								 lista->pedidos[pos].codigop=auxcod;
								 break;
				case 2:printf("Informe o novo CPF do cliente: ");
								 scanf("%s",lista->pedidos[pos].cpf);
								 break;
				case 3:printf("Informe o novo codigo do produto: ");
								 scanf("%d",&lista->pedidos[pos].codigop);
								 break;
				case 4:printf("Informe a nova quantidade do produto: ");
								 scanf("%d",&lista->pedidos[pos].quantidade);
								 break;
				case 5:printf("Informe a nova data do pedido no formato \"\\DD\\MM\\AAAA\\\": ");
								 scanf("%s",&lista->pedidos[pos].data_pedido);
								 break;
				case 6:printf("Informe a nova data da fatura no formato \"\\DD\\MM\\AAAA\\\": ");
								 scanf("%s",&lista->pedidos[pos].data_fatura);
								 default:break;
			 }
		else
		 {
			printf("Elemento nao encontrado.\n");
		 }
 }
 }
//
// secao black magic :)
//


int salva_pedidos(struct listap lista)
 {
	FILE *stream;
	if ((stream = fopen("..//db//´PEDIDOS.DAT", "w+b"))== NULL)
	 {
		fprintf(stderr, "Cannot open output file.\n");
		return 1;
	 }
	fwrite(&lista ,sizeof(struct listap),lista.tam, stream);
	fclose(stream);
	return(0);
 }



int le_arq_pedidos(struct listap *lista)
{
	 FILE *stream;
	 if ((stream = fopen("..//db//PEDIDOS.DAT", "rb"))== NULL)
		{
		 fprintf(stderr, "Cannot open output file.\n");
		 return 1;
		}
	 rewind(stream);
	 fread(lista, sizeof(struct listap), 50, stream);
	 fclose(stream);
	 return(0);
}
//
// fim de black magic
//
