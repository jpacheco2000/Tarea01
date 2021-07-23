radixSort.o: radixSort.c
	gcc -c radixSort.c -o radixSort.o

ejemploRadix: radixSort.o ejemploRadix.c
	gcc -o ejemploRadix ejemploRadix.c radixSort.o

insertionSort.o: insertionSort.c
	gcc -c insertionSort.c -o insertionSort.o

ejemploInsertion: insertionSort.o ejemploInsertion.c
	gcc -o ejemploInsertion ejemploInsertion.c insertionSort.o

quickSort.o: quickSort.c
	gcc -c quickSort.c -o quickSort.o

ejemploQuickSort: quickSort.o ejemploQuickSort.c
	gcc -o ejemploQuickSort ejemploQuickSort.c quickSort.o

ejemploSorts: ejemploSorts.c quickSort.o insertionSort.o radixSort.o
	gcc -o ejemploSorts ejemploSorts.c quickSort.o insertionSort.o radixSort.o

tarea2: tarea2.c quickSort.o insertionSort.o radixSort.o
	gcc -o tarea2 tarea2.c quickSort.o insertionSort.o radixSort.o

tarea3: tarea3.c quickSort.o insertionSort.o radixSort.o
	gcc -o tarea3 tarea3.c quickSort.o insertionSort.o radixSort.o
