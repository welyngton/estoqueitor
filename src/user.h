#ifndef _USER_H_
#define _USER_H_

/* Contem todas as funcoes de adicao,modificacao e remocao de usuarios.
*/
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

	void inicializa_users(struct listau *lista);
	void imprime_lista_users(struct listau *lista);
	void le_user(int pos,struct listau *lista);
	void add_user(struct listau *lista);
	void remove_user(struct listau *lista);
	void edita_user(struct listau *lista);
	void muda_senha_user(char *user,struct listau *lista);
	int checa_user(char *user,char *senha,struct listau *lista);
	int salva_usuarios(struct listau lista);
	int le_arq_usuarios(struct listau *lista);
#include "user.c"

#endif