SOURCE_FILE = queue_destory.c queue_enter.c queue_init.c queue_out.c queue_print.c add_edge.c init_graph.c init_table.c print_graph.c release_graph.c release_table.c topsort.c test_graph.c  table_print.c

OBJECT_FILE = queue_destory.o queue_enter.o queue_init.o queue_out.o queue_print.o add_edge.o init_graph.o init_table.o print_graph.o release_graph.o release_table.o topsort.o test_graph.o table_print.o

compile:
	gcc -g -c $(SOURCE_FILE)

link:
	gcc $(OBJECT_FILE) -g -o ./a.out

clean:
	mv ./*.o ./a.out ~/.trash/
