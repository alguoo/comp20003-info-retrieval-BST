dict1: dict3.o reader3.o bst3.o
	gcc -o dict1 dict3.o reader3.o bst3.o
dict3.o: dict3.c dict3.h reader3.c reader3.h bst3.c bst3.h
	gcc -c -Wall dict3.c reader3.c bst3.c
reader3.o: reader3.c reader3.h bst3.c bst3.h
	gcc -c -Wall reader3.c bst3.c
bst3.o: bst3.c bst3.h
	gcc -c -Wall bst3.c

dict2: dict2.o reader2.o bst2.o list.o
	gcc -o dict2 dict2.o reader2.o bst2.o list.o
dict2.o: dict2.c dict2.h reader2.c reader2.h bst2.c bst2.h
	gcc -c -Werror dict2.c reader2.c bst2.c
reader2.o: reader2.c reader2.h bst2.c bst2.h list.c list.h
	gcc -c -Wall reader2.c bst2.c list.c
bst2.o: bst2.c bst2.h list.c list.h
	gcc -c -Wall list.c bst2.c
list.o: list.c list.h
	gcc -c -Wall list.c
