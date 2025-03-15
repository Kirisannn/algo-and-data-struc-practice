FLAGS = -std=c++23 -g -Wall -Wextra

all: DynamicArrays HashTable PrefixSums

DynamicArrays:	DynamicArrays.cpp
	g++ $(FLAGS) -o out/DynamicArrays DynamicArrays.cpp
	out/DynamicArrays


HashTable:	HashTable.cpp
	g++ $(FLAGS) -o out/HashTable HashTable.cpp
	out/HashTable

PrefixSums:	PrefixSums.cpp
	g++ $(FLAGS) -o out/PrefixSums PrefixSums.cpp
	out/PrefixSums

clean:
	rm out/*