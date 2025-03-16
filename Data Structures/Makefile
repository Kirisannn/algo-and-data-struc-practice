FLAGS = -std=c++23 -g -Wall -Wextra

all: DynamicArrays HashTable PrefixSums ContainsDuplicate

DynamicArrays:	DynamicArrays.cpp
	g++ $(FLAGS) -o out/DynamicArrays DynamicArrays.cpp
	out/DynamicArrays


HashTable:	HashTable.cpp
	g++ $(FLAGS) -o out/HashTable HashTable.cpp
	out/HashTable

PrefixSums:	PrefixSums.cpp
	g++ $(FLAGS) -o out/PrefixSums PrefixSums.cpp
	out/PrefixSums

ContainsDuplicate:	ContainsDuplicate.cpp
	g++ $(FLAGS) -o out/ContainsDuplicate ContainsDuplicate.cpp
	out/ContainsDuplicate

ValidAnagram:	ValidAnagram.cpp
	g++ $(FLAGS) -o out/ValidAnagram ValidAnagram.cpp
	out/ValidAnagram

clean:
	rm out/*