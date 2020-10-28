3t: 3t.o
	@$(CC) 3t.o -o 3t

3t.o:
	@$(CC) -c src/3t.c