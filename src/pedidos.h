#ifndef _PEDIDOS_H_
#define _PEDIDOS_H_

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

	void inicializa_pedidos(struct listap *lista);
	void imprime_lista_pedidos(struct listap *lista);
	void le_pedido(int pos,struct listap *lista);
	void add_pedido(struct listap *listas);
	int checa_cpf_pedido(char *cpf,struct listap *lista);
	void edita_pedido(struct listap *lista);
	int salva_pedidos(struct listap);
	int le_arq_pedidos(struct listap *lista);
#include "pedidos.c"

#endif