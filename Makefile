clean:
	@find . -name "*.out" -delete

build: clean
	cc -ansi -Wall $(e).c

run: build
	./a.out < $(e).in
