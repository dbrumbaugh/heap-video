CFLAGS="-ggdb"
heaptest: heaptest.c heap.o
	gcc ${CFLAGS} heaptest.c heap.o -o heaptest

heapsort: heapsort.c heap.o
	gcc ${CFLAGS} heapsort.c heap.o -o heapsort

clean:
	rm heap.o heaptest heapsort
