SOURCE_FILE:= quick_sort.c Qsort_test.c median.c swap.c

OBJECT_FILE:= quick_sort.o Qsort_test.o median.o swap.o

compile:
	gcc -g -c $(SOURCE_FILE)

link:
	gcc $(OBJECT_FILE) -g -o ./a.out

clean:
	rm -rf ./a.out ./*.o
