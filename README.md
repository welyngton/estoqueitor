# estoqueitor
Sistema de controle de estoque para vendas escrito em C (para terminal)

		#######
		#        ####  #####  ####   ####  #    # ###### # #####  ####  #####
		#       #        #   #    # #    # #    # #      #   #   #    # #    #
		#####    ####    #   #    # #    # #    # #####  #   #   #    # #    #
		#            #   #   #    # #  # # #    # #      #   #   #    # #####
		#       #    #   #   #    # #   #  #    # #      #   #   #    # #   #
		#######  ####    #    ####   ### #  ####  ###### #   #    ####  #    # ver0.1b

# sistoq
	
	
### Desenvolvido por: Rafael Rotelok e Welyngton Dal Pra.


Todos os arquivos se encontram na pasta raiz
	
Nela ainda se encontram os diretorios:
### "bin/" - que guarda os arquivos binarios do programa (executavel);

### "scr/"
armazena todas as bibliotecas e codigos-fonte utilizados pelo programa;
os arquivos em "scr/" sao os codigos-fonte: clientes.c, pedidos.c, produtos.c, sistoq.c, user.c, inicia.c, misc.c
e os arquivos de biblioteca: clientes.h, pedidos.h, produtos.h, user.h, inicia.h, misc.h

### "db/"
diretorio que guarda os arquivos: "estoque.dat", "clientes.dat", "pedidos.dat", "usuarios.dat".
que sao bancos de dados de estruturas.

## como desarquivar o pacote;
	
	- Para compilar o arquivo fonte, basta rodar o makefile na pasta do programa.
	
### Todas as estruturas no momento sao vetores de listas.
