#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxuser 7
struct user
 {
	int usado;
	char nome[15];
	int nivel;
	char senha[10];
 } ;

struct listau
 {
	struct user user[maxuser];
	int tam;
 } ;
void inicializa_users (struct listau *lista)
 {
	int i;
	for (i=1;i<=maxuser;i++)
	 lista->user[i].usado=0;
	lista->tam=1;
	lista->user[0].usado=1;
	strcpy(lista->user[0].nome,"root");
	lista->user[0].nivel=3;
	strcpy(lista->user[0].senha,"branco");
 }

void imprime_users(struct listau *lista)
 {
	int i;
	printf("|----Nome-------|Nivel|---Senha--|\n");
	for (i=0;i<=lista->tam;i++)
	 if (lista->user[i].usado==1)
		{
		 printf("|%15s",lista->user[i].nome);
		 printf("|%5d",lista->user[i].nivel);
		 printf("|%10s",lista->user[i].senha);
		 printf("|\n");
		}
	printf("|---------------|-----|----------|\n");
 }

void le_user(int pos,struct listau *lista)
 {
	char senha1[10],senha2[10];
	int aux,fim=1;
	printf("Escreva o nome do ususario\n");
	scanf("%s",&lista->user[pos].nome);
	 do
		{
		 printf("Escreva a senha do usuario");
		 scanf("%s",senha1);
		 printf("Repita sua senha");
		 scanf("%s",senha2);
		 fim=strcmp(senha1,senha2);
		 if (fim==0)
			strcpy(lista->user[pos].senha,senha1);
		} while (fim!=0);
	 do
		{
		 printf("Qual eh o nivel do usuario?\n(1,2 ou 3)\n");
		 scanf("%d",&aux);
		 if ((aux>3)|(aux<0))
			printf("Opcao de nivel invalida");
		} while ((aux>3)|(aux<1));
	lista->user[pos].nivel=aux;
	lista->user[pos].usado=1;
 }

void add_user(struct listau *lista)
 {
	int cont=0,aux,achou=0;
	while ((!achou)&&(cont<=lista->tam))
	 {
		if (lista->user[cont].usado==0)
		 {
			aux=cont;
			achou=1;
		 }
		cont++;
	 }
	 if (achou)
		le_user(aux,lista);
	 else
		{
		 lista->tam++;
		 le_user(lista->tam,lista);
		}
 }

void remove_user(struct listau *lista)
 {
	int cont=0,aux,achou=0,opcao;
	char user[15];
  imprime_users(lista);
	printf("Digite o nome do usuario a ser removido:");
	scanf("%s",user);
	while ((!achou)&&(cont<=lista->tam))
	 {
		if (strcmp(user,lista->user[cont].nome)==0)
		 {
			achou=1;
			aux=cont;
		 }
		cont++;
	 }
	if (achou)
	 {
		printf("Usuario %s encontrado,tem certeza que deseja remove-lo?\n\n1:sim\n2:nao\n",user);
		scanf("%d",&opcao);
		if (opcao)
		 lista->user[aux].usado=0;
	 }
	else
	 {
		printf("Usuario %s nao encontrado.",user);
	 }
 }

void edita_user(struct listau *lista)
 {
	int cont=0,aux,achou=0,opcao;
	char user[15];
	printf("Escreva o nome do usuario que voce deseja editar: ");
	scanf("%s",user);
	while((!achou)&&(cont<=lista->tam))
	 {
		if (strcmp(user,lista->user[cont].nome)==0)
		 {
			achou=1;
			aux=cont;
		 }
		cont++;
	 }
	if (achou)
	 {
		printf("Qual campo voce deseja alterar?\n1:Nivel\n2:senha\n");
		scanf("%d",&opcao);
		switch (opcao)
		 {
			case 1:printf("O nivel atual eh %d. Qual sera o novo nivel?",lista->user[aux].nivel);
						 scanf("%d",&lista->user[aux].nivel);break;
			case 2:printf("Qual sera a nova senha?");
						 scanf("%s",lista->user[aux].senha);break;
		 }
	 }
	else
	 printf("Usuario nao encontrado");
 }

void muda_senha_user(char *user,struct listau *lista)
 {
	int cont=0,pos=-1,fim=0;
	char senha[10],senha1[10],senha2[10];
	while (cont<=lista->tam)
	 {
		if (strcmp(user,lista->user[cont].nome)==0)
			pos=cont;
		cont++;
	 }
	if (pos==-1)
	 printf("Usuario nao encontrado");
	else
	 {
		printf("Digite sua senha atual:");
		scanf("%s",senha);
		if (strcmp(senha,lista->user[pos].senha)==0)
		 {
			do
			 {
				printf("Digite sua nova senha:");
				scanf("%s",senha1);
				printf("Confirme sua nova senha:");
				scanf("%s",senha2);
				if (strcmp(senha1,senha2)==0)
				 fim=1;
				else
				 printf("As senhas nao conferem! Por favor tente novamente.\n");
			 }while (!fim);
		 }
	 }
 }


// a funcao retorna o nivel do usuario 1 2 ou 3
// retornando -1 caso o usuario nao for encontrado
// ou a senha digitada for invalida

int checa_user(char *user, char *senha, struct listau *lista)
 {
	int i;
	for (i=0;i<=lista->tam;i++)
	 {
		if (lista->user[i].usado==1)
			if (strcmp(user,lista->user[i].nome)==0)
				if (strcmp(senha,lista->user[i].senha)==0)
				 return(lista->user[i].nivel);
	 }
	return(-1);
 }

//
//inicio da secao black magic :)
//
int salva_usuarios(struct listau lista)
 {
	FILE *stream;
	if ((stream = fopen("..//db//USUARIOS.DAT", "w+b"))== NULL)
	 {
		fprintf(stderr, "O arquivo nao pode ser aberto.\n");
		return 1;
	 }
	fwrite(&lista ,sizeof(struct listau),lista.tam, stream);
	fclose(stream);
	return(0);
 }

int le_arq_usuarios(struct listau *lista)
{
	 FILE *stream;
	 if ((stream = fopen("..//db//USUARIOS.DAT", "rb"))== NULL)
		{
		 fprintf(stderr, "O arquivo nao pode ser aberto..\n");
		 return 1;
		}
	 rewind(stream);
	 fread(lista, sizeof(struct listau ), 50, stream);
	 fclose(stream);
	 return(0);
}

//
//fim da secao black magic
//
