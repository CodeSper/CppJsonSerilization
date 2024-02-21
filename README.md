# CppJsonSerilization
Serialization and Deserialization of CPP Struct and JSON Object

## describe

CppJsonSerialization is a modern cpp serialization library.

You only need to define a structure, and the library can automatically complete the assignment and conversion

## how to use

```c++
#import library
#include "Serialization.hpp"
#defien struct
struct Hack {
	int x;
	int y;
	SerializationFormat(Hack,value.x,value.y)
};
//use
std::string test1 = ObjectToJsonString(h1);
std::cout << "Hello here " << test1<<"\n";
h1 = { 0,0 };
if (JsonStringToObject(test1, h1)) {
	std::cout << "pks";
}
```

support base type: int,doube,short,float

support contains:std::vector std::list

support strings：std::string

## limit:

Each structure can support a maximum of 52 parameters. If there are too many parameters, please use nested structures.

