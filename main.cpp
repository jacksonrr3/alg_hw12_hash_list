#include <iostream>
#include <string>
#include "Hash_chain.h"

int main(int argv, char ** args) {
	Hash_Chain<std::string> table(100);
	table.ins(2, "test2");
	table.ins(4, "test4");
	table.ins(7, "test7");
	table.ins(12, "test12");
	table.ins(22, "test22");
	table.ins(32, "test32");
	table.ins(42, "test42");

	std::cout << table.search(2) << std::endl;
	table.del(2);
	std::cout << table.search(2) << std::endl;
	std::cout << table.search(4) << std::endl;
	std::cout << table.search(7) << std::endl;
	std::cout << table.search(12) << std::endl;
	std::cout << table.search(22) << std::endl;
	std::cout << table.search(32) << std::endl;
	table.del(32);
	std::cout << table.search(42) << std::endl;
	std::cout << table.search(13) << std::endl;
	


	return 0;
}