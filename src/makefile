SRCS=$(wildcard *.c)

OUTS=$(wildcard *.o)
OUTS_OBJ=$(wildcard ../obj/*.o)

all: compile make_output 

compile: $(SRCS)
	gcc -c $(SRCS) && mv *.o ../obj/

make_output: $(OUTS_OBJ)
	(cd ../obj && gcc -lncurses *.o -o output && mv output ../src)

run: 
	./output

clean:
	rm *.o output

%.o: %.c
	gcc -c $<