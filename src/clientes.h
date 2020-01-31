#ifndef _CLIENTES_H_
#define _CLIENTES_H_

/* Contem todas as funcoes de adicao,modificacao e remocao de clientes
*/

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

	void inicializa_clientes(struct listac *lista);
	void imprime_lista_clientes(struct listac *lista);
	void le_cliente(int pos,struct listac *lista);
	void add_cliente(struct listac *listac);
	void remove_cliente(struct listac *lista);
	void edita_cliente(struct listac *lista);
	int checa_cliente_cpf(char *cpf,struct listac *lista);
	int salva_clientes(struct listac lista);
	int le_arq_cliente(struct listac *lista);
#include "clientes.c"

#endif