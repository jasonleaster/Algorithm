SOURCE_FILE:= dequeue.c enqueue.c is_empty.c is_full.c queue_init.c queue_release.c queue_test.c

OBJECT_FILE:= dequeue.o enqueue.o is_empty.o is_full.o queue_init.o queue_release.o queue_test.o

a.out: $(OBJECT_FILE)

compile:
	gcc -g -c $(SOURCE_FILE)

link:
	gcc $(OBJECT_FILE) -g -o ./a.out

clean:
	rm -rf ./*.o ./a.out
