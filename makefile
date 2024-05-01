hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -I ./include/ -o ./lib/Kare.o -c ./src/Kare.c
	gcc -I ./include/ -o ./bin/Test ./lib/Canli.o ./lib/Kare.o ./src/Test.c

calistir:
	./bin/Test
