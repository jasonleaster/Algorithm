SOURCE_FILE:=	init_stack.c is_empty.c is_full.c pop.c push.c stack_test.c stack_release.c

OBJECT_FILE:=	init_stack.o is_empty.c is_full.o pop.o push.o stack_test.o stack_release.o

a.out:$(OBJECT_FILE)

compile:
	gcc -c $(SOURCE_FILE)

link:
	gcc $(OBJECT_FILE) -o ./a.out

clean:
	rm -r ./*.o ./a.out
