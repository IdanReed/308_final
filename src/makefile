SRCS=$(wildcard *.c)
OUTS=$(wildcard *.o)

all: compile output 

compile: $(SRCS)
	gcc -c $(SRCS)

output: $(OUTS)
	gcc -lncurses $(OUTS) -o output

run: 
	./output

clean:
	rm *.o output

%.o: %.c
	gcc -c $<