SOURCE_FILE = is_empty.c push_stack.c creat_stack.c pop_stack.c comupter.c release_stack.c comupter_test.c new_string.c del_string.c str_read.c

OBJECT_FILE = is_empty.o push_stack.o creat_stack.o pop_stack.o comupter.o release_stack.o comupter_test.o new_string.o del_string.o str_read.o

a.out: $(OBJECT_FILE)

compile:$(SOURCE_FILE)
	gcc -g -c $(SOURCE_FILE)  

link:$(OBJECT_FILE)
	gcc $(OBJECT_FILE) -g -o ./a.out

clean:
	rm  -f ./*.o ./*.gch ./a.out
