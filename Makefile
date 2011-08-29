clean:
	@git clean -dfX

build: clean
	cc -ansi -Wall $(e).c

run: build
	./a.out < $(e).in

test: build
	./a.out
