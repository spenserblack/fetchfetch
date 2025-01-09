fetchfetch: art.o args.o stats.o version.o fetchfetch.c
	$(CC) -o fetchfetch art.o args.o stats.o version.o fetchfetch.c

args.o: args.c args.h
	$(CC) -c -o args.o args.c

art.o: art.c art.h
	$(CC) -c -o art.o art.c

stats.o: stats.c stats.h version.c version.h
	$(CC) -c -o stats.o stats.c

version.o: version.c version.h
	$(CC) -c -o version.o version.c

.PHONY: format
format:
	clang-format -i *.c *.h

.PHONY: run
run: fetchfetch
	./fetchfetch

.PHONY: install
install: fetchfetch
	cp ./fetchfetch /usr/local/bin/fetchfetch
