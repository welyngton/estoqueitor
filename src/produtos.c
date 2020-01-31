#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxloja 20
struct roupa
 {
 	int usado;
	int codigo;
	char nome[16];
	int quantidade;
	float preco;
 } ;

struct listar
 {
	struct roupa roupa[maxloja];
	int tam;
 } ;
void inicializa_produtos(struct listar *lista)
 {
	int i;
	for (i=0;i<=100;i++)
	 lista->roupa[i].usado=0;
	lista->tam=0;
 }

void imprime_produtos(struct listar *lista)
 {
	int i;
	printf("|Cod.|-----NoMe------|Qtd.-|Preco-|\n");
	for (i=0;i<=lista->tam;i++)
	 if (lista->roupa[i].usado==1)
		 {
			 printf("|%4d",lista->roupa[i].codigo);
			 printf("|%15s",lista->roupa[i].nome);
			 printf("|%5d",lista->roupa[i].quantidade);
			 printf("|%6.2f",lista->roupa[i].preco);
			 printf("|\n");
		 }
	printf("|----|---------------|-----|------|\n");
 }

void le_produto(int pos,struct listar *lista)
 {
	int fim=0,codigo;
	do
	 {
		printf("Escreva o codigo do produto: ");
		scanf("%d",&codigo);
		if (checa_codigo_produto(codigo,lista)==-1)
		 {
			fim=1;
		 }
		else
		 {
			printf("O codigo %d ja esta sendo usado\n",codigo);
		 }
		} while (!fim);
	lista->roupa[pos].codigo=codigo;
	printf("Escreva o nome do produto: ");
	scanf("%s",lista->roupa[pos].nome);
	printf("Informe o numero de pecas do produto em estoque:");
	scanf("%d",&lista->roupa[pos].quantidade);
	printf("Informe o preco de cada peca:");
	scanf("%f",&lista->roupa[pos].preco);
	lista->roupa[pos].usado=1;
 }

void add_produto(struct listar *lista)
 {
	int cont=1,aux,achou=0;
	while ((!achou)&&(cont<=lista->tam))
	 {
		if (lista->roupa[cont].usado==0)
		 {
			aux=cont;
			achou=1;
		 }
		cont++;
	 }
	if (achou)
	 {
		le_produto(aux,lista);
	 }
	else
	 {
		lista->tam++;
		le_produto(lista->tam,lista);
	 }
 }


void remove_produto(struct listar *lista)
 {
	int cont=1,codigo,aux,achou=0;
	printf("Qual o codigo do elemento a ser removido?:");
	scanf("%d",&codigo);
	while ((!achou)&&(cont<=lista->tam))
	 {
		if (lista->roupa[cont].codigo==codigo)
		 {
			achou=1;
			aux=cont;
		 }
		cont++;
	 }
	if (achou)
	 {
		lista->roupa[aux].usado=0;
		printf("\nElemento removido\n");
	 }
	else
	 {
		printf("\nElemento nao econtrado\n");
	 }
 }


void edita_produto(struct listar *lista)
 {
	int codigo,pos,opcao,auxcod,fim=0;

	printf("Qual eh o codigo do elemento a ser editado?");
	scanf("%d",&codigo);
	printf("qual coluna voce gostaria de editar?\n");
	printf("1:Codigo\n2:Nome\n3:Quantidade\n4:Preco");
	scanf("%d",&opcao);
	pos=checa_codigo_produto(codigo,lista);
	if (pos>=0)
	 switch (opcao)
		{
		 case 1:do
						 {
							printf("qual eh o novo codigo do produto?");
							scanf("%d",&auxcod);
							if (checa_codigo_produto(auxcod,lista)!=-1)
							 fim=1;
						 } while (!fim);
						 lista->roupa[pos].codigo=auxcod;
						 break;
		 case 2:printf("Qual o novo nome do produto\n");
						scanf("%s",lista->roupa[pos].nome);
						break;
		 case 3:printf("qual eh a nova quantidade do produto?\n");
						scanf("%d",&lista->roupa[pos].quantidade);
						break;
		 case 4:printf("Qual o novo preco do produto\n");
						scanf("%f",&lista->roupa[pos].preco);
						break;
		}
	else
	 {
		printf("Elemento nao encontrado.\n");
	 }
 }

/*funcao checa codigo retorna -1 caso o codigo passado nao seja
  encontrado e a posicao caso o codigo seja encontrado na lista
*/
int checa_codigo_produto(int codigo,struct listar *lista)
 {
	int cont=0,achou=0,pos;
	while ((!achou)&&(cont<=lista->tam))
	 {
		if (lista->roupa[cont].codigo==codigo)
		 {
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


//
// secao black magic :)
//
int salva_produtos(struct listar lista)
 {
	FILE *stream;
	if ((stream = fopen("..//db//ESTOQUE.DAT", "w+b"))== NULL)
	 {
		fprintf(stderr, "Cannot open output file.\n");
		return 1;
	 }
	fwrite(&lista ,sizeof(struct listar),lista.tam, stream);
	fclose(stream);
	return(0);
 }

int le_arq_produtos(struct listar *lista)
{
	 FILE *stream;
	 if ((stream = fopen("..//db//ESTOQUE.DAT", "rb"))== NULL)
		{
		 fprintf(stderr, "Cannot open output file.\n");
		 return 1;
		}
	 rewind(stream);
	 fread(lista, sizeof(struct listar ), 50, stream);
	 fclose(stream);
	 return(0);
}

//
// fim da secao black magic
// 
