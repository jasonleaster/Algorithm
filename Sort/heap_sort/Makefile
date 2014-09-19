SOURCE_FILE:=	build_heap.c delete_heap.c destroy_heap.c init_heap.c insert_heap.c is_empty.c is_full.c  heap_sort.c print_heap.c percolate_down.c

OBJECT_FILE:=	build_heap.o delete_heap.o destroy_heap.o init_heap.o insert_heap.o is_empty.o is_full.o  heap_sort.o print_heap.o percolate_down.o

compile:
	gcc -g -c $(SOURCE_FILE)

link:
	gcc $(OBJECT_FILE) -g -o ./a.out

clean:
	rm -rf ./*.o ./a.out
