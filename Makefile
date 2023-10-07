all:
	gcc linkedlist.c -c
	gcc example.c linkedlist.o -o TEST

.PHONY: clean
clean:
	rm *.o TEST -f
