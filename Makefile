clean:
	@git clean -dfx

build: clean
	cc -ansi -Wall $(e).c

run: build
	./a.out < $(e).in
