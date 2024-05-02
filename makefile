hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -I ./include/ -o ./lib/Bitki.o -c ./src/Bitki.c
	gcc -I ./include/ -o ./lib/Bocek.o -c ./src/Bocek.c
	gcc -I ./include/ -o ./lib/Sinek.o -c ./src/Sinek.c
	gcc -I ./include/ -o ./lib/Pire.o -c ./src/Pire.c
	gcc -I ./include/ -o ./lib/kutuphane.o -c ./src/kutuphane.c
	gcc -I ./include/ -o ./bin/Test ./lib/Canli.o ./lib/Bitki.o ./lib/Bocek.o ./lib/Sinek.o ./lib/Pire.o ./lib/kutuphane.o ./src/Test.c

calistir:
	./bin/Test
