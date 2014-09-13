SOURCE_FILE:=	is_empty.c push_stack.c creat_stack.c pop_stack.c stack_test.c 

OBJECT_FILE:=	is_empty.o push_stack.o creat_stack.o pop_stack.o stack_test.o

a.out: $(OBJECT_FILE)

compile:$(SOURCE_FILE)
	gcc -c $(SOURCE_FILE)  

link:$(OBJECT_FILE)
	gcc $(OBJECT_FILE) -o ./a.out

clean:
	rm -f ./*.o ./*.gch ./a.out
