SRCS=$(wildcard *.c)

OUTS=$(wildcard *.o)
OUTS_OBJ=$(wildcard ../obj/*.o)

all: compile make_output

compile: $(SRCS)
	gcc -c $(SRCS) && mv *.o ../obj/

make_output: $(OUTS_OBJ)
	(cd ../obj && gcc *.o -lncurses -o output && mv output ../src)

run:
	./output

clean:
	(rm output && cd ../obj && rm *.o)

%.o: %.c
	gcc -c $<
