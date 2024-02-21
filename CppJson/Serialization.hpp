#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP
#include "CppJson.hpp"

template<typename T>
bool JsonStringToObject(const std::string& data, T& obj)
{
    try {
        JsonOperation::JsonLexer lexer;
        lexer.Parser(data.data(), data.length());
        JsonOperation::JsonObject* r = lexer.Result().get();
        if (r != nullptr)
        {
            *r >> obj;
            return true;
        }
        return false;
    }
    catch (std::string error) {
        std::cout << "some thing get wrong " << error;
        return false;
    }
    catch (std::exception& ex)
    {
        return false;
    }
}

template<typename T>
std::string ObjectToJsonString(T& data)
{
    JsonOperation::JsonObject obj;
    obj << data;
    return obj.FormatToJson();
}
template<typename T>
std::string FormatToJsonString(T& data) {
    JsonOperation::JsonObject obj;
    obj << data;
    return obj.FormatToJsonPrint();
}
template<typename T>
std::string FormatToJsonMiniString(T& data) {
    JsonOperation::JsonObject obj;
    obj << data;
    return obj.FormatToJson();
}
#endif // SERIALIZATION_HPP
