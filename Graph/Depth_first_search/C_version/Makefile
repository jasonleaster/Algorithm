SOURCE_FILE = init_graph.c print_graph.c release_graph.c test_graph.c add_edge.c  dfs.c


OBJECT_FILE = init_graph.o print_graph.o release_graph.o test_graph.o add_edge.o dfs.o

compile:
	gcc $(SOURCE_FILE) -g -c

link:
	gcc $(OBJECT_FILE) -g -o ./a.out

clean:
	rm -rf ./*.o ./a.out
