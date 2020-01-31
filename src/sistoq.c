// programa final... teoricamente
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "clientes.h"
#include "pedidos.h"
#include "produtos.h"
#include "user.h"
#include "misc.h"


/*Programa principal*/
int main()
 {
	int nivel;
	char user[15],senha[10];
	struct listar listar;
	struct listac listac;
	struct listau listau;
	struct listap listap;
	inicializa_produtos(&listar);
	inicializa_clientes(&listac);
	inicializa_users(&listau);
	inicializa_pedidos(&listap);
	le_arq_produtos(&listar);
	le_arq_clientes(&listac);
	le_arq_usuarios(&listau);
	le_arq_pedidos(&listap);
	printf("#######\n");
	printf("#        ####  #####  ####   ####  #    # ###### # #####  ####  #####\n");
	printf("#       #        #   #    # #    # #    # #      #   #   #    # #    #\n");
	printf("#####    ####    #   #    # #    # #    # #####  #   #   #    # #    #\n");
	printf("#            #   #   #    # #  # # #    # #      #   #   #    # #####\n");
	printf("#       #    #   #   #    # #   #  #    # #      #   #   #    # #   #\n");
	printf("#######  ####    #    ####   ### #  ####  ###### #   #    ####  #    # ver0.7b\n\n");
	printf("\nDigite seu Usuario e Senha para comecar a usar o programa.\n");
	printf("Digite seu usuario: ");
	scanf("%s",user);
	printf("Digite sua senha:");
	scanf("%s",senha);
	nivel=checa_user(user,senha,&listau);
	if (nivel > -1)
		switch (nivel)
		 {
			case 1:modo_1(&listar,&listac,&listap);break;
			case 2:modo_2(&listar,&listac,&listap);break;
			case 3:modo_3(&listar,&listac,&listap,&listau);break;
		 }
	else
		printf("Usuario ou senha incorretos!");
	salva_usuarios(listau);
	salva_pedidos(listap);
	salva_produtos(listar);
	salva_clientes(listac);
	printf("tchau!\n");
  	}
