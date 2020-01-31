tudo: sistoq

sistoq: misc.o clientes.o pedidos.o produtos.o user.o sistoq.o
	gcc -g -o sistoq misc.o inicia.o clientes.o pedidos.o produtos.o user.o sistoq.o

sistoq.o: sistoq.c clientes.h pedidos.h produtos.h user.h misc.h
	gcc -g -c sistoq.c

misc.o: misc.c misc.h 
	gcc -g -c misc.c

clientes.o: clientes.c clientes.h
	gcc -g -c clientes.c

pedidos.o: pedidos.c pedidos.h
	gcc -g -c pedidos.c

produtos.o: produtos.c produtos.h
	gcc -g -c produtos.c

user.o: user.c user.h
	gcc -g -c user.c


#limpa:
#rm -f *[~] core* *bak

#faxina: limpa
#rm -f *[.o] ./bin/sistoq


