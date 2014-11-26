SOURCE_FILE:=	is_empty.c push_stack.c creat_stack.c pop_stack.c stack_test.c comupter.c release_stack.c

OBJECT_FILE:=	is_empty.o push_stack.o creat_stack.o pop_stack.o stack_test.o comupter.o release_stack.o

a.out: $(OBJECT_FILE)

compile:$(SOURCE_FILE)
	gcc -g -c $(SOURCE_FILE)  

link:$(OBJECT_FILE)
	gcc $(OBJECT_FILE) -g -o ./a.out

clean:
	rm  -f ./*.o ./*.gch ./a.out
