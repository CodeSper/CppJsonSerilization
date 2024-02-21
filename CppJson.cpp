

#include "Serialization.hpp"
struct Hack {
	int x;
	int y;
	SerializationFormat(Hack,value.x,value.y)
};

#include <iostream>
int main()
{
	using namespace std;
	Hack h1 = { 1,2 };
	std::string test1 = ObjectToJsonString(h1);
	std::cout << "Hello CMake." << endl;
	h1 = { 0,0 };
	if (JsonStringToObject(test1, h1)) {
		std::cout << "pks";
	}
	return 0;
}
