fetchfetch: art.o fetchfetch.c
	$(CC) -o fetchfetch art.o fetchfetch.c

art.o: art.c
	$(CC) -c -o art.o art.c
