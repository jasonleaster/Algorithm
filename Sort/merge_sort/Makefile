SOURCE_FILE:= merge.c merge_sort_test.c msort.c

OBJECT_FILE:= merge.o merge_sort_test.o msort.o

compile:
	gcc -g -c $(SOURCE_FILE)

link:
	gcc $(OBJECT_FILE) -g -o ./a.out

clean:
	rm -rf ./a.out ./*.o
