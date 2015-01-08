SOURCE_FILE = flush_hp_num.c init_inserting_num.c init_skip_list.c insert_node.c node_level.c release_skip_list.c test.c

OBJECT_FILE = flush_hp_num.o init_inserting_num.o init_skip_list.o insert_node.o node_level.o release_skip_list.o test.o

compile:
	gcc -g -c $(SOURCE_FILE)
link:
	gcc $(OBJECT_FILE) -g -o ./a.out
clean:
	mv ./*.o ~/.trash/
