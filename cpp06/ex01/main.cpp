#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data original(42, "hello sup !", 3.14);

	std::cout << "Origianl Data: " << std::endl;
	std::cout << " Address: " << &original << std::endl;
	std::cout << " n: " << original.n << std::endl;
	std::cout << " s: " << original.s << std::endl;
	std::cout << " d: " << original.d << std::endl;

	//serialize
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "\n one way in representing address - Serialized (uintptr_t): " << raw << std::endl;

	// std::cout << " Data n: " << raw->n << std::endl; // cannot do this
	
	// Deserialize
	Data* restored = Serializer::deserialize(raw);
	std::cout << "\n Address of original: " << &original << std::endl;
	std::cout << "\n value of raw: " << raw << std::endl;
	std::cout << "\n another way in representing address - Deserioalized pointer: " << restored << std::endl;
	
	//verify
	std::cout << "\nVerification: " << std::endl;
	std::cout << " are restored and original the same? " << (restored == &original ? "yes" : "no") << std::endl;
	std::cout << " Data n: " << restored->n << std::endl;
	std::cout << " Data s: " << restored->s << std::endl;
	std::cout << " Data d: " << restored->d << std::endl;

	return 0;

}