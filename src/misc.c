#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime_opcoes(int nivel)
 {
	if (nivel>0)
	 {
		printf("0:termina a execucao do programa\n");
		printf("1:imprime a lista de produtos\n");
		printf("2:imprime a lista de clientes\n");
		printf("3:imprime a lista de pedidos\n");
	 }
	if (nivel>1)
	 {
		printf("4:adiciona um elemento a lista de produtos\n");
		printf("5:adiciona um elemento a lista de clientes\n");
		printf("6:adiciona um elemento a lista de pedidos\n");
		printf("7:edita um elemento da lista de produtos\n");
		printf("8:edita um elemento da lista de clientes\n");
		printf("9:edita um elemento da lista de pedidos\n");
	 }
	if (nivel==3)
	 {
		printf("10:remove um elemento da lista de produtos\n");
		printf("11:remove um elemento da lista de clientes\n");
		printf("12:remove um elemento da lista de pedidos(nao implementado)\n");
		printf("13:imprime a lista de usuarios\n");
		printf("14:adiciona um novo usuario\n");
		printf("15:edita um usuario existente\n");
		printf("16:remove um usuario existente\n");
	 }
 }

void modo_1(struct listar *listar,struct listac *listac,struct listap *listap)
 {
	int nivel=1,opcao,fim=0;
	while (!fim)
	 {
		imprime_opcoes(nivel);
		printf("Qual Opcao vc gostaria?\n");
		scanf("%d",&opcao);
		switch (opcao)
		 {
			case 0:fim=1;break;
			case 1:imprime_produtos(listar);break;
			case 2:imprime_lista_clientes(listac);break;
			case 3:imprime_lista_pedidos(listap);break;
		 }
	 }
 }

void modo_2(struct listar *listar,struct listac *listac,struct listap *listap)
 {
	int nivel=2,opcao,fim=0;
	while (!fim)
	 {
		imprime_opcoes(nivel);
		printf("Oq vc gostaria?\n");
		scanf("%d",&opcao);
		switch (opcao)
		 {
			case 0:fim=1;break;
			case 1:imprime_produtos(listar);break;
			case 2:imprime_lista_clientes(listac);break;
			case 3:imprime_lista_pedidos(listap);break;
			case 4:add_produto(listar);break;
			case 5:add_cliente(listac);break;
			case 6:add_pedido(listap);break;
			case 7:edita_produto(listap);break;
			case 8:edita_cliente(listac);break;
			case 9:edita_pedido(listac);break;
		 }
	 }
 }
void modo_3(struct listar *listar,struct listac *listac,struct listap *listap,struct listau *listau)
 {
	int nivel=3,opcao,fim=0;
	while (!fim)
	 {
		imprime_opcoes(nivel);
		printf("Oq vc gostaria?\n");
		scanf("%d",&opcao);
		switch (opcao)
		 {
			case 0:fim=1;break;
			case 1:imprime_produtos(listar);break;
			case 2:imprime_lista_clientes(listac);break;
			case 3:imprime_lista_pedidos(listap);break;
			case 4:add_produto(listar);break;
			case 5:add_cliente(listac);break;
			case 6:add_pedido(listap);break;
			case 7:edita_produto(listap);break;
			case 8:edita_cliente(listac);break;
			case 9:edita_pedido(listac);break;
			case 10:remove_produto(listar);break;
			case 11:remove_cliente(listac);break;
			case 12:printf("nao implementado\n");break;
      case 13:imprime_users(listau);break;
			case 14:add_user(listau);break;
			case 15:edita_user(listau);break;
			case 16:remove_user(listau);break;
		 }
	 }
 }
