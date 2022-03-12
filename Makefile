pc2:
	gcc PC2.c -o pc2.o -lm

clean: 
	rm -f programa *.o

run:
	./pc2.o