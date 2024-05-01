hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -I ./include/ -o ./lib/Bitki.o -c ./src/Bitki.c
	gcc -I ./include/ -o ./bin/Test ./lib/Canli.o ./lib/Bitki.o ./src/Test.c

calistir:
	./bin/Test
