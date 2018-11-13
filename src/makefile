SRCS=$(wildcard *.c)
OUTS=$(wildcard *.o)

all: compile output run

compile: $(SRCS)
	gcc -c $(SRCS)

output: $(OUTS)
	cd ../obj
	gcc $(OUTS) -o output

run: 
	./output

clean:
	rm *.o output

%.o: %.c
	gcc -c $<