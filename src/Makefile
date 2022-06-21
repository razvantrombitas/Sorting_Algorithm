main_function: main_1 main_2 main_3 main_4
	@ echo "Recursive Merge Sort unoptimized: "
	@ ./main_1
	@ echo "Recursive Merge Sort optmized: "
	@ ./main_2 
	@ echo "Iterative Merge Sort unoptimized: "
	@ ./main_3
	@ echo "Iterative Merge Sort optimized: "
	@ ./main_4

main_1: recursive_mergesort.cpp
	@ g++ recursive_mergesort.cpp -o main_1

main_2: recursive_mergesort.cpp
	@ g++ recursive_mergesort.cpp -O3 -fopenmp -o main_2

main_3: iterative_mergesort.cpp
	@ g++ iterative_mergesort.cpp -o main_3

main_4: iterative_mergesort.cpp
	@ g++ iterative_mergesort.cpp -O3 -fopenmp -o main_4
