#include <iostream>
#include <string>
#include "Hash_chain.h"


std::size_t hash(int i) {
	return i;
}



int main(int argv, char** args) {
	Hash_Chain<int, std::string> table(100, hash);		//таблица размерностью 100.
	std::cout << table.ins(2, "test2") << std::endl;
	table.ins(4, "test4");
	table.ins(7, "test7");
	table.ins(12, "test12");
	table.ins(22, "test22");
	table.ins(32, "test32");
	table.ins(42, "test42");

	std::cout << table.search(2) << std::endl;	// добавление повторно элемента
	std::cout << table.ins(2, "test2") << std::endl;
	table.del(2);					// тест - удаление элемента
	std::cout << table.search(2) << std::endl;	// поиск удаленного элемента
	std::cout << table.search(4) << std::endl;	// добавление нового элемента
	std::cout << table.search(7) << std::endl;	// добавление нового элемента
	std::cout << table.search(12) << std::endl;	// добавление элемента в цепочку
	std::cout << table.search(22) << std::endl;	// тест - добавление элемента в цепочку
	std::cout << table.search(32) << std::endl;	// тест - добавление элемента в цепочку
	std::cout << table.del(32) << std::endl;	// тест - удаление элемента
	std::cout << table.search(42) << std::endl;	// тест - поиск в цепочке после удаления элемента из цепочки
	std::cout << table.search(13) << std::endl;     // тест - поиск отсутствующего элемента
	std::cout << table.del(13) << std::endl;	// тест - удаление отсутствующего элемента



	return 0;
}
