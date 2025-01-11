bin/fetchfetch: bin/art.o bin/args.o bin/stats.o bin/version.o src/fetchfetch.c
	$(CC) -o bin/fetchfetch bin/art.o bin/args.o bin/stats.o bin/version.o src/fetchfetch.c


bin/args.o: src/args.c src/args.h
	$(CC) -c -o bin/args.o src/args.c

bin/art.o: src/art.c src/art.h
	$(CC) -c -o bin/art.o src/art.c

bin/stats.o: src/stats.c src/stats.h src/version.c src/version.h
	$(CC) -c -o bin/stats.o src/stats.c

bin/version.o: src/version.c src/version.h
	$(CC) -c -o bin/version.o src/version.c

.PHONY: format
format:
	clang-format -i src/*

.PHONY: run
run: bin/fetchfetch
	./bin/fetchfetch

.PHONY: install
install: fetchfetch
	cp ./bin/fetchfetch /usr/local/bin/fetchfetch
