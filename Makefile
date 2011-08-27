p=""

clean:
	@find . -name "*.out" -delete

build: clean
	cc -ansi -Wall $(p).c

run: build
	./a.out
