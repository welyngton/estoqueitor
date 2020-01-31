#ifndef _PRODUTOS_H_
#define _PRODUTOS_H_

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

	void inicializa_produtos(struct listar *lista);
	void imprime_produtos(struct listar *lista);
	void le_produto(int pos,struct listar *lista);
	void add_produto(struct listar *lista);
	void remove_produto(struct listar *lista);
	void edita_produto(struct listar *lista);
	int checa_codigo_produto(int codigo,struct listar *lista);
	int salva_produtos(struct listar lista);
	int le_arq_produtod(struct listar *lista);
#include "produtos.c"

#endif