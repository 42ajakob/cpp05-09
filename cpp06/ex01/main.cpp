#include "Serializer.hpp"

int main() {
	Data d;
	d.i = 42;

	uintptr_t raw = Serializer::serialize(&d);
	std::cout << "raw: " << raw << std::endl;

	Data *undo = Serializer::deserialize(raw);
	std::cout << "data: " << undo->i << std::endl;

	return 0;
}