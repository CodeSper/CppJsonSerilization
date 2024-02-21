#ifndef CPPJSON_HPP
#define CPPJSON_HPP
#include "Json.hpp"
#include "Foreach.h"
#include <utility>
#include <type_traits>
using str = std::string;
using size_t = std::size_t;
#define Str(value) #value

//
struct TypeFeild
{
    int    tips;
    bool   fo;
    double po;
    str    colroful;
};
static str RemoveDot(const str& value)
{
    size_t off = 0;
    size_t size = value.size();
    for (unsigned index = 0; index < size; ++index)
    {
        if (value.data()[index] == '.')
        {
            off = index;
        }
    }
    if (off > 0)
    {
        return value.substr(off + 1);
    }
    return value;
}


#define SS(in_value) <<RemoveDot(Str(in_value))<<JsonOperation::InType<typename std::remove_cv<decltype(in_value)>::type>(in_value)
#define TS(in_value) >>RemoveDot(Str(in_value))>>JsonOperation::OutType<typename std::remove_cv<decltype(in_value)>::type>(in_value)

static JsonOperation::JsonObject& operator>>(JsonOperation::JsonObject& target, TypeFeild& value)
{
    target For_Each(TS, value.tips, value.fo, value.po, value.colroful);
    return target;
}
static JsonOperation::JsonObject& operator<<(JsonOperation::JsonObject& target, TypeFeild& value)
{
    target For_Each(SS, value.tips, value.fo, value.po, value.colroful);
    return target;
}

//--------------------------------------------------------------------------------------------------------
struct GoWay
{
    int x;
    double y;
};

struct Piece
{
    int x;
    int y;
    GoWay ty;
    int z;
};

#define PropertySet(Target,Property) Target<<RemoveDot(Str(Property));\
                             target.CreateObject()<<Property;

static JsonOperation::JsonObject& operator>>(JsonOperation::JsonObject& target, GoWay& value)
{
    target For_Each(TS, value.x, value.y);
    return target;
}
static JsonOperation::JsonObject& operator<<(JsonOperation::JsonObject& target, GoWay& value)
{
    target For_Each(SS, value.x, value.y);
    return target;
}

static JsonOperation::JsonObject& operator>>(JsonOperation::JsonObject& target, Piece& value)
{
    target For_Each(TS, value.x, value.y, value.ty, value.z);
    return target;
}
static JsonOperation::JsonObject& operator<<(JsonOperation::JsonObject& target, Piece& value)
{
    target For_Each(SS, value.x, value.y, value.ty, value.z);
    return target;
}

//---------------------------------------------------------------------------------------------------------
//list property

struct Point
{
    double x;
    double y;
};

struct Piece_List
{
    int x;
    int y;
    GoWay ty;
    int z;
    std::vector<Point> points;
};
static JsonOperation::JsonObject& operator>>(JsonOperation::JsonObject& target, Point& value)
{
    target For_Each(TS, value.x, value.y);
    return target;
}
static JsonOperation::JsonObject& operator<<(JsonOperation::JsonObject& target, Point& value)
{
    target For_Each(SS, value.x, value.y);
    return target;
}

static JsonOperation::JsonObject& operator>>(JsonOperation::JsonObject& target, Piece_List& value)
{
    target For_Each(TS, value.x, value.y, value.ty, value.z, value.points);
    return target;
}
static JsonOperation::JsonObject& operator<<(JsonOperation::JsonObject& target, Piece_List& value)
{
    target For_Each(SS, value.x, value.y, value.ty, value.z, value.points);
    return target;
}

#define OutSerializationFormat(type,...)\
static JsonOperation::JsonObject& operator<<(JsonOperation::JsonObject& target, type & value) {\
target For_Each(SS, __VA_ARGS__);\
return target;\
}\
static JsonOperation::JsonObject& operator>>(JsonOperation::JsonObject& target, type& value) {\
target For_Each(TS, __VA_ARGS__);\
return target;\
}

#define SerializationFormat(type,...)\
    friend JsonOperation::JsonObject& operator<<(JsonOperation::JsonObject& target, type & value) {\
        target For_Each(SS, __VA_ARGS__);\
        return target;\
    }\
    friend JsonOperation::JsonObject& operator>>(JsonOperation::JsonObject& target, type& value) {\
        target For_Each(TS, __VA_ARGS__);\
        return target;\
    }
struct ASize {
    float x1;
    float xy;
    SerializationFormat(ASize, value.x1, value.xy)
};
struct TypeHolder {
    bool bouns[6];
    int  inection[12];
    ASize tsize[2];
    SerializationFormat(TypeHolder, value.bouns, value.inection, value.tsize)
};

struct MapTest {
    std::map<int, int> map1;
    std::map<std::string, ASize> map2;
    SerializationFormat(MapTest, value.map1, value.map2)
};
#endif