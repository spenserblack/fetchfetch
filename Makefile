fetchfetch: art.o args.o stats.o fetchfetch.c
	$(CC) -o fetchfetch art.o args.o stats.o fetchfetch.c

args.o: args.c args.h
	$(CC) -c -o args.o args.c

art.o: art.c art.h
	$(CC) -c -o art.o art.c

stats.o: stats.c stats.h version.h
	$(CC) -c -o stats.o stats.c

.PHONY: run
run: fetchfetch
	./fetchfetch

.PHONY: install
install: fetchfetch
	cp ./fetchfetch /usr/local/bin/fetchfetch
