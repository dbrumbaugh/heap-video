CFLAGS="-ggdb"
heaptest: heaptest.c heap.o
	gcc ${CFLAGS} heaptest.c heap.o -o heaptest

query: query.c heap.o
	gcc ${CFLAGS} query.c heap.o -o query

clean:
	rm heap.o heaptest query
