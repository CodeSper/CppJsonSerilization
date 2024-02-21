#ifndef JSON_HPP
#define JSON_HPP
#include <map>
#include <vector>
#include <string>
#include <list>
#include <memory>
#include <cstring>
#include <iostream>
namespace JsonOperation
{
#ifndef UNUSED
#define UNUSED(x) (void)(x);
#endif
    using str = std::string;
    using size_t = std::size_t;
    using uchar = unsigned char;
    using ushort = unsigned short;
#ifndef KB
#define KB (1024)
#endif
    template<typename T> struct IsBaseType { const static bool value = false; };
    template<> struct IsBaseType<int> { const static bool value = true; };
    template<> struct IsBaseType<size_t> { const static bool value = true; };
    template<> struct IsBaseType<std::conditional<sizeof(unsigned) == sizeof(size_t), long long, unsigned>::type> { const static bool value = true; };
    template<> struct IsBaseType<short> { const static bool value = true; };
    template<> struct IsBaseType<char> { const static bool value = true; };
    template<> struct IsBaseType<str> { const static bool value = true; };
    template<> struct IsBaseType<unsigned char> { const static bool value = true; };
    template<> struct IsBaseType<unsigned short> { const static bool value = true; };
    template<> struct IsBaseType<double> { const static bool value = true; };
    template<> struct IsBaseType<float> { const static bool value = true; };
    template<> struct IsBaseType<bool> { const static bool value = true; };
    template<typename T>
    struct IsContains { const static bool value = false; };
    template<typename T>
    struct IsContains<std::vector<T>> { const static bool value = true; };
    template<typename T>
    struct IsContains<std::list<T>> { const static bool value = true; };
    template<typename T, unsigned size>
    struct IsContains<T[size]> { const static bool value = true; };
#if 0
    template<typename Top>
    constexpr bool IsContains(...) { return false; }
    template<typename Top>
    constexpr bool IsContains(const std::vector<Top>&) { return  true; }
    template<typename Top>
    constexpr bool IsContains(const std::list<Top>&) { return true; }
#endif
    //#define CHECK_POD
    template<typename T>
    struct IsInObjecct
    {
#ifdef CHECK_POD
        static constexpr bool value = !IsBaseType<Top>::value && std::is_pod<Top>::value;
#else
        static constexpr bool value = !IsBaseType<T>::value && !IsContains<typename std::remove_cv<T>::type>::value;
#endif
    };

    template<typename OType>
    struct UniformObject
    {
        using OrginType = OType;
        UniformObject(OType& dat) :os(dat) {

        }

        OType& os;
    };
    template<typename T>
    using InType = typename std::conditional<IsInObjecct<T>::value, UniformObject<T>, T&>::type;
    template<typename T>
    using OutType = typename std::conditional<IsInObjecct<T>::value, UniformObject<T>, T&>::type;

    static int GetIndex() {
        static int size = 0;
        ++size;
        return  size;
    }
    class str_t
    {
    public:
        str_t(const unsigned& size)
        {
            data = new char[size];
            limit = size;
            expand_size = size;
        }
        str_t()
        {
            data = new char[limit];
        }
        str value()
        {
            if (used != limit)
            {
                data[used] = '\0';
            }
            str ret = data;
            return ret;
        }
        str_t& AddChar(const char& raw)
        {
            if ((used + 1) == limit)
            {
                unsigned newsize = limit + expand_size; 
                char* temp = new char[newsize];
                if (temp != nullptr)
                {
                    memcpy(temp, data, used);
                    char* old = data;
                    data = temp;
                    limit = newsize;
                    expand_size = limit / 2;
                    delete[] old;
                }
                else
                {
                    str error = "Str Realloc Memory Failed!";
                    std::cout<<"error:" << error;
                    return (*this);  
                }
            }
            data[used++] = raw;
            return *(this);
        }
        str_t& operator<<(const char& raw)
        {
            return AddChar(raw);
        }
        str_t& operator<<(const str& st)
        {
            for (unsigned index = 0; index < st.size(); ++index)
            {
                AddChar(st.at(index));
            }
            return *this;
        }

        unsigned Size()
        {
            return used;
        }
        void ClearUse()
        {
            memset(data, 0, sizeof(char) * limit);
            used = 0;
            has_str = false;
            str_end = false;
        }
        char* Data()
        {
            return data;
        }
        bool HasStr()
        {
            return used > 0;
        }
        ~str_t()
        {
            delete[]data;
        }
        char* data{ nullptr };
    private:
        bool has_str{ false };
        bool str_end{ false };
        unsigned used{ 0 };
        unsigned limit{ 128 };
        unsigned expand_size{ 128 };
    };
    static str ToString(const bool& value)
    {
        str ret;
        if (value)
        {
            ret = "true";
        }
        else
        {
            ret = "false";
        }
        return ret;
    }
    static str ToString(const int& value)
    {
        return std::to_string(value);
    }
    static str ToString(const unsigned& value)
    {
        return std::to_string(value);
    }
    static str ToString(const short& value)
    {
        return std::to_string(value);
    }
    static str ToString(const char& value)
    {
        return std::to_string(value);
    }
    static str ToString(const double& value)
    {
        return std::to_string(value);
    }
    static str ToString(const float& value)
    {
        return std::to_string(value);
    }
    static str ToString(const str& value)
    {
        return "\"" + value + "\"";
    }
    static str ToString(const unsigned char& value)
    {
        return std::to_string(value);
    }
    static str ToString(const unsigned short& value)
    {
        return std::to_string(value);
    }
    template<typename T>
    static str ToString(const T&)
    {
        std::count << "Invalid Convert!\n";
        return "";
    }

    template<typename T>
    static T To(const str& value)
    {
        UNUSED(value)
            return T();
    }
    template<>
    bool To(const str& value)
    {
        if (value == "true" || value == "True")
        {
            return true;
        }
        return false;
    }
    static bool To(str& value)
    {
        if (value == "true" || value == "True")
        {
            return true;
        }
        return false;
    }
    template<>
    int To(const str& value)
    {
        return std::atoi(value.data());
    }
    template<>
    unsigned To(const str& value)
    {
        return std::atoll(value.data());
    }
    template<>
    double To(const str& value)
    {
        return std::atof(value.data());
    }

    template<>
    float To(const str& value)
    {
        return static_cast<float>(std::atof(value.data()));
    }

    template<>
    str To(const str& value)
    {
        return value;
    }
    template<>
    uchar To(const str& value)
    {
        return atoi(value.data());
    }
    template<>
    char To(const str& value)
    {
        return atoi(value.data());
    }
    template<>
    ushort To(const str& value)
    {
        return atoi(value.data());
    }
    template<>
    short To(const str& value)
    {
        return atoi(value.data());
    }
    template<typename K, typename V, typename T>
    bool FindValue(std::map<K, V>& values, unsigned& index, T& value) {
        auto indexFind = values.find("index");
        if (indexFind == values.end()) {
            return false;
        }
        index = To<unsigned>(indexFind->second);
        auto valueFind = values.find("value");
        if (valueFind == values.end()) {
            return false;
        }
        value = To<T>(valueFind->second);
        return true;

    }
    struct JsonObject
    {
        using keyType = str;
        using valueType = str;
        using OType = std::shared_ptr<JsonObject>;
        using objectType = std::map<keyType, OType>;                  //value object
        using propertyType = std::map<keyType, valueType>;                   //self object
        using VectorType = std::vector<OType>;
        using chidlrenType = std::map<keyType, VectorType >;  //verctor peroperty
        //
        str FormatToJsonPrint() {
            const size_t tbuffer = 512;
            str_t result_str(tbuffer);
            const str key_start = "\"";
            const str dic_type = ":";
            const str co_type = ",";
            const str pro_open = "{";
            const str pro_close = "}";
            const str v_open = "[";
            const str v_close = "]";
            const str v_entry = "\n";

            bool isobject = false;
            bool islist = false;

            if (propertys.size() > 0 || objects.size() > 0 || vector_objects.size() > 0) isobject = true;
            else if (self_objs.size() > 0) islist = true;
            else { return ""; }
            //
            if (isobject)
            {
                result_str << pro_open << v_entry;
                size_t count = 0;
                size_t size = propertys.size();
                //bool     hasnext = false;
                //bool     hasprew = false;
                if ((objects.size() + vector_objects.size()) > 0)
                {
                    //hasnext = true;
                }
                //parser propertys
                bool has_ps = false;
                for (auto& item : propertys)
                {
                    result_str << key_start << item.first << key_start << dic_type;
                    result_str << item.second;
                    ++count;
                    if ((count) != size)
                    {
                        result_str << co_type << v_entry;
                    }
                    has_ps = true;

                }
                //parser vector object
                count = 0;
                size = objects.size();
                if (size > 0)
                {
                    //hasnext = true;
                    if (has_ps) {
                        result_str << co_type;
                    }
                }
                for (auto& item : objects)
                {
                    result_str << key_start << item.first << key_start << dic_type;
                    result_str << item.second->FormatToJson();
                    ++count;
                    if ((count) != size)
                    {
                        result_str << co_type;
                    }
                    has_ps = true;
                }
                //parser list type
                count = 0;
                size = vector_objects.size();
                if (size > 0)
                {

                    //hasnext = true;
                    if (has_ps) {
                        result_str << co_type;
                    }
                }
                for (auto& item : vector_objects)
                {
                    result_str << key_start << item.first << key_start << dic_type;
                    result_str << v_open;
                    size_t ssize = item.second.size();
                    size_t scount = 0;
                    for (auto& sub : item.second)
                    {

                        result_str << sub->FormatToJson();
                        ++scount;
                        if ((scount) != ssize)
                        {
                            result_str << co_type;
                        }
                    }
                    result_str << v_close << v_entry;
                    ++count;
                    if ((count) != size)
                    {
                        result_str << co_type;
                    }
                }
                result_str << pro_close << v_entry;
            }
            if (islist)
            {
                result_str << v_open;
                size_t count = 0;
                size_t size = self_objs.size();
                for (auto& item : self_objs)
                {
                    result_str << (item->FormatToJson());
                    ++count;
                    if ((count + 1) != size)
                    {
                        result_str << co_type;
                    }
                }
                result_str << v_close;
            }
            return result_str.value();
        }
        str FormatToJson()
        {
            const size_t tbuffer = 512;
            str_t result_str(tbuffer);
            const str key_start = "\"";
            const str dic_type = ":";
            const str co_type = ",";
            const str pro_open = "{";
            const str pro_close = "}";
            const str v_open = "[";
            const str v_close = "]";

            bool isobject = false;
            bool islist = false;

            if (propertys.size() > 0 || objects.size() > 0 || vector_objects.size() > 0) isobject = true;
            else if (self_objs.size() > 0) islist = true;
            else { return ""; }
            //
            if (isobject)
            {
                result_str << pro_open;
                size_t count = 0;
                size_t size = propertys.size();
                //bool     hasnext = false;
                //bool     hasprew = false;
                if ((objects.size() + vector_objects.size()) > 0)
                {
                    //hasnext = true;
                }
                //parser propertys
                bool has_ps = false;
                for (auto& item : propertys)
                {
                    result_str << key_start << item.first << key_start << dic_type;
                    result_str << item.second;
                    ++count;
                    if ((count) != size)
                    {
                        result_str << co_type;
                    }
                    has_ps = true;

                }
                //parser vector object
                count = 0;
                size = objects.size();
                if (size > 0)
                {
                    //hasnext = true;
                    if (has_ps) {
                        result_str << co_type;
                    }
                }
                for (auto& item : objects)
                {
                    result_str << key_start << item.first << key_start << dic_type;
                    result_str << item.second->FormatToJson();
                    ++count;
                    if ((count) != size)
                    {
                        result_str << co_type;
                    }
                    has_ps = true;
                }
                //parser list type
                count = 0;
                size = vector_objects.size();
                if (size > 0)
                {

                    //hasnext = true;
                    if (has_ps) {
                        result_str << co_type;
                    }
                }
                for (auto& item : vector_objects)
                {
                    result_str << key_start << item.first << key_start << dic_type;
                    result_str << v_open;
                    size_t ssize = item.second.size();
                    size_t scount = 0;
                    for (auto& sub : item.second)
                    {

                        result_str << sub->FormatToJson();
                        ++scount;
                        if ((scount) != ssize)
                        {
                            result_str << co_type;
                        }
                    }
                    result_str << v_close;
                    ++count;
                    if ((count) != size)
                    {
                        result_str << co_type;
                    }
                }
                result_str << pro_close;
            }
            if (islist)
            {
                result_str << v_open;
                size_t count = 0;
                size_t size = self_objs.size();
                for (auto& item : self_objs)
                {
                    result_str << (item->FormatToJson());
                    ++count;
                    if ((count + 1) != size)
                    {
                        result_str << co_type;
                    }
                }
                result_str << v_close;
            }
            return result_str.value();
        }
        void SetProperty(const keyType& key, const valueType& value)
        {
            propertys.insert(std::make_pair(key, value));
        }
        void SetObject(const keyType& key, OType obj)
        {
            objects.insert(std::make_pair(key, obj));
        }
        void PrepareKey(const keyType& key)
        {
            auto find = vector_objects.find(key);
            auto end = vector_objects.end();
            if (find == end)
            {
                VectorType vs;
                vector_objects.insert(std::make_pair(key, vs));
            }
        }
        void SetVectorItem(const keyType& key, OType obj)
        {
            auto find = vector_objects.find(key);
            auto end = vector_objects.end();
            bool result = end == find;
            if (result)
            {
                VectorType vs;
                vs.push_back(std::move(obj));
                vector_objects.insert(std::make_pair(key, vs));
                return;
            }
            VectorType& vt = find->second;
            vt.push_back((obj));
        }
        void SetSelfObject(OType obj)
        {
            self_objs.push_back((obj));
        }
        //
        propertyType propertys;
        objectType   objects;
        chidlrenType vector_objects;
        VectorType   self_objs;
        ~JsonObject()
        {
            propertys.clear();
            objects.clear();
            vector_objects.clear();
            self_objs.clear();
        }

        str GetValue(const keyType& key)
        {
            auto find = propertys.find(key);
            if (find != propertys.end())
            {
                return find->second;
            }
            return "";
        }
        OType GetObject(const keyType& key)
        {
            auto find = objects.find(key);
            if (find != objects.end())
            {
                return find->second;
            }
            return nullptr;
        }
        OType GetObejectAt(const keyType& key, const unsigned& index)
        {
            auto find = vector_objects.find(key);
            if (find != vector_objects.end())
            {
                std::vector<OType>& vts = find->second;
                if (index < vts.size())
                {
                    return vts[index];
                }
            }
            return nullptr;
        }

        //
        enum class ParserType :unsigned char
        {
            unkonwn,
            value,
            object,
            list,
        };
        ParserType detype{ ParserType::unkonwn };
        str de_key;
        JsonObject& operator>>(const str& target)
        {
            de_key = target;
            if (propertys.find(target) != propertys.end())
            {
                detype = ParserType::value;

                return *this;
            }
            if (objects.find(target) != objects.end())
            {
                detype = ParserType::object;
                return *this;
            }
            if (vector_objects.find(target) != vector_objects.end())
            {
                detype = ParserType::list;
                return *this;
            }
            return *this;

        }
        //function trait
        template<typename T, unsigned length>
        typename std::enable_if<IsBaseType<T>::value, JsonObject&>::type operator<<(T(&ref)[length]) {
            if (de_key != "")
            {
                //VectorType collects;
                if (length == 0)
                {
                    PrepareKey(de_key);
                }
                for (unsigned index = 0; index < length; ++index) {
                    OType pb = std::make_shared<JsonObject>();
                    T value = ref[index];
                    unsigned i = index;
                    (*pb).SetProperty("index", ToString(i));
                    (*pb).SetProperty("value", ToString(value));
                    SetVectorItem(de_key, pb);
                }
                de_key = "";
            }
            return *this;
        }


        template<typename T, unsigned length>
        typename std::enable_if<IsBaseType<T>::value, JsonObject&>::type operator>>(T(&ref)[length]) {
            if (detype == ParserType::list)
            {
                auto find = vector_objects.find(de_key);
                if (find != vector_objects.end())
                {
                    std::vector<OType>& fcal = find->second;
                    if (fcal.size() > 0)
                    {
                        for (int index = 0; index < fcal.size(); ++index) {
                            OType& ovalue = fcal[index];
                            if (ovalue->propertys.size() == 2) {
                                unsigned index;
                                T value;
                                if (FindValue(ovalue->propertys, index, value)) {
                                    if (index < length) {
                                        ref[index] = value;
                                    }
                                }
                            }
                            else {
                                std::cout << "Error! Json Parser Error!" << " POD Property Has " << ovalue->propertys.size() << " \n";
                            }
                        }
                    }
                }
            }
            return *this;
        }
        template<typename T, unsigned length>
        typename std::enable_if<IsInObjecct<T>::value, JsonObject&>::type operator<<(T(&ref)[length]) {
            if (de_key != "")
            {
                //VectorType collects;
                if (length == 0)
                {
                    PrepareKey(de_key);
                }
                for (unsigned index = 0; index < length; ++index) {
                    OType pb = std::make_shared<JsonObject>();
                    (*pb) << ref[index];
                    SetVectorItem(de_key, pb);
                }
                de_key = "";
            }
            return *this;
        }

        template<typename T, unsigned length>
        typename std::enable_if<IsInObjecct<T>::value, JsonObject&>::type operator>>(T(&ref)[length]) {
            if (detype == ParserType::list)
            {
                auto find = vector_objects.find(de_key);
                if (find != vector_objects.end())
                {
                    std::vector<OType>& fcal = find->second;
                    if (fcal.size() > 0)
                    {
                        for (int index = 0; index < fcal.size(); ++index) {
                            OType& ovalue = fcal[index];
                            if (ovalue->propertys.size() == 2) {
                                unsigned index;
                                T value;
                                if (FindValue(ovalue->propertys, index, value)) {
                                    if (index < length) {
                                        ref[index] = value;
                                    }
                                }
                            }
                            else {
                                std::cout << "Error! Json Parser Error!" << " POD Property Has " << ovalue->propertys.size() << " \n";
                            }
                        }
                    }
                }
            }
            return *this;
        }
        //
        template<typename K, typename V>
        typename std::enable_if<IsBaseType<V>::value, JsonObject&>::type operator<<(std::map<K, V>& value) {
            if (de_key != "")
            {
                OType fpb = std::make_shared<JsonObject>();
                for (auto& item : value) {
                    OType pb = std::make_shared<JsonObject>();
                    str  key = ToString(item.first);
                    str  val = ToString(item.second);
                    pb->SetProperty("value", val);
                    fpb->SetObject(key, pb);
                }
                this->SetObject(de_key, fpb);
            }
            de_key = "";
            return *this;
        }
        template<typename K, typename V>
        typename std::enable_if<IsBaseType<V>::value, JsonObject&>::type operator>>(std::map<K, V>& value) {
            if (detype == ParserType::object)
            {
                OType c = this->GetObject(de_key);
                if (c != nullptr)
                {
                    for (auto& obj : c->objects) {
                        K key = To<K>(obj.first);
                        str value = obj.second->GetValue("value");
                        if (value != "") {
                            value[key] = To<V>(value);
                        }
                        else {
                            std::cout << " Error Translate : key =" << obj.first << " whole key =" << de_key;
                        }
                    }
                }
                else
                {
                    std::cout<<"error:Not Find Key"<<de_key<<"\n";
                }

            }
            return *this;
        }

        template<typename K, typename V>
        typename std::enable_if<IsInObjecct<V>::value, JsonObject&>::type operator<<(std::map<K, V>& value) {
            if (de_key != "")
            {
                OType fpb = std::make_shared<JsonObject>();
                for (auto& item : value) {
                    OType pb = std::make_shared<JsonObject>();
                    str  key = ToString(item.first);
                    (*pb) << item.second;
                    fpb->SetObject(key, pb);
                }
                this->SetObject(de_key, fpb);
            }
            de_key = "";
            return *this;
        }
        template<typename K, typename V>
        typename std::enable_if<IsInObjecct<V>::value, JsonObject&>::type operator>>(std::map<K, V>& target) {
            if (detype == ParserType::object)
            {
                OType c = this->GetObject(de_key);
                if (c != nullptr)
                {
                    for (auto& obj : c->objects) {
                        K key = To<K>(obj.first);
                        V value;
                        (*obj.second) >> value;
                        target[key] = value;
                    }
                }
                else
                {
                    std::cout << "error:Not Find Key" << de_key << "\n";
                }

            }
            return *this;
        }

        template<typename T>
        JsonObject& operator>>(std::vector<T>& value)
        {
            if (detype == ParserType::list)
            {
                auto find = vector_objects.find(de_key);
                if (find != vector_objects.end())
                {
                    std::vector<OType>& fcal = find->second;
                    if (fcal.size() > 0)
                    {
                        for (size_t index = 0; index < fcal.size(); ++index)
                        {
                            T temp;
                            (*fcal[index]) >> temp;
                            value.push_back(std::move(temp));
                        }
                    }
                }
            }
            return *this;
        }
        template<typename T>
        JsonObject& operator>>(std::list<T>& value)
        {
            if (detype == ParserType::list)
            {
                auto find = vector_objects.find(de_key);
                if (find != vector_objects.end())
                {
                    std::vector<OType>& fcal = find->second;
                    if (fcal.size() > 0)
                    {
                        for (size_t index = 0; index < fcal.size(); ++index)
                        {
                            T temp;
                            (*fcal[index]) >> temp;
                            value.push_back(std::move(temp));
                        }
                    }
                }
            }
            return *this;
        }
        template<typename T>
        JsonObject& operator>>(T& source)
        {
            if (detype == ParserType::value)
            {
                source = To<T>(GetValue(de_key));
            }
            return *this;
        }

        template<typename T>
        JsonObject& operator>>(UniformObject<T>& value)
        {
            void* asdk = (void*)&value;
            if (detype == ParserType::object)
            {
                OType c = this->GetObject(de_key);
                if (c != nullptr)
                {
                    (*c) >> value.os;
                }
                else
                {
                    std::cout << "error:Not Find Key" << de_key << "\n";
                }

            }
            return *this;
        }
        template<typename T>
        JsonObject& operator>>(UniformObject<T>&& value)
        {

            if (detype == ParserType::object)
            {
                OType c = this->GetObject(de_key);
                if (c != nullptr)
                {
                    (*c) >> value.os;
                }
                else
                {
                    std::cout << "error:Not Find Key" << de_key << "\n";
                }

            }
            return *this;
        }
        JsonObject& operator<<(const str& target)
        {
            if (de_key != "")
            {
                this->SetProperty(de_key, ToString(target));
                de_key = "";
                return *this;
            }
            de_key = target;

            return *this;
        }
        template<typename T>
        JsonObject& operator<<(const T& value)
        {
            if (de_key != "")
            {
                this->SetProperty(de_key, ToString(value));
            }
            de_key = "";
            return *this;
        }
        //uniform type
        template<typename T>
        JsonObject& operator<<(const UniformObject<T>& value)
        {
            if (de_key != "")
            {
                OType pb = std::make_shared<JsonObject>();
                *pb << value.os;
                this->SetObject(de_key, pb);
            }
            de_key = "";
            return *this;
        }
        template<typename T>
        JsonObject& operator<<(const std::vector<T>& value)
        {
            if (de_key != "")
            {
                //VectorType collects;
                if (value.size() == 0)
                {
                    PrepareKey(de_key);
                }
                for (auto& item : value)
                {
                    OType pb = std::make_shared<JsonObject>();
                    (*pb) << *(T*)(const_cast<T*>(&item));
                    SetVectorItem(de_key, pb);
                }
                de_key = "";
            }
            return *this;
        }
        template<typename T>
        JsonObject& operator<<(const std::list<T>& value)
        {
            if (de_key != "")
            {
                if (value.size() == 0)
                {
                    PrepareKey(de_key);
                }
                for (auto& item : value)
                {
                    OType pb = std::make_shared<JsonObject>();
                    (*pb) << *(T*)(const_cast<T*>(&item));
                    SetVectorItem(de_key, pb);
                }
                de_key = "";
            }
            return *this;
        }

    };

    enum class PropertyType :unsigned char
    {
        Nomal,
        Object,
        Vector,
    };
    enum  class PropertyProgross :unsigned char
    {
        Yet,
        key,
        Value,
        Finish,
    };
    struct JsonParserNode
    {
        std::shared_ptr<JsonObject> current;   
        JsonParserNode* parent{ nullptr };    
        JsonParserNode* next{ nullptr };     
        PropertyType Type{ PropertyType::Nomal };
        ~JsonParserNode() {
        }
        void ConnectNext(JsonParserNode* next)
        {
            next->parent = this;
            this->next = next;
        }
        bool handle_object_open{ false };  //{
        bool handle_object_close{ false };  //}
        bool handle_vector_open{ false };  //[
        bool handle_vector_close{ false };  //]
        bool handle_dic_Delimiter{ false }; //:
        bool key_open{ false };
        bool key_close{ false };
        void ClearAllState()
        {
            ClearBuffer();
            ClearMarkState();
            ClearKeyParser();
            Type = PropertyType::Nomal;
        }
        void ClearKeyParser()
        {
            key_open = false;
            key_close = false;
            pro_prc_type = PropertyProgross::Yet;
            is_str = false;
        }
        void ClearMarkState()
        {
            handle_object_open = false;
            handle_object_close = false;
            handle_vector_open = false;
            handle_vector_close = false;
            handle_dic_Delimiter = false;
        }
        PropertyProgross pro_prc_type{ PropertyProgross::Yet };      
        str_t key_buffer;                   
        str_t value_buffer;                
        bool  is_str{ false };              
        void ClearBuffer()                 
        {
            key_buffer.ClearUse();
            value_buffer.ClearUse();
            is_str = false;
        }
        bool TrySetProperty()
        {
            if (key_buffer.HasStr() && value_buffer.HasStr())
            {
                current->SetProperty(key_buffer.value(), value_buffer.value());
                ClearBuffer();
                ClearKeyParser();
                return true;
            }
            if (key_buffer.HasStr() && !value_buffer.HasStr())
            {
                ClearBuffer();
                ClearKeyParser();
            }
            return false;
        }
        bool TrySetObject(JsonObject::OType  target)
        {
            if (key_buffer.HasStr())
            {
                current->SetObject(key_buffer.value(), target);
                ClearBuffer();
                ClearKeyParser();
                return true;
            }
            return false;
        }
        bool TrySetVectorItem(const JsonObject::keyType& key, JsonObject::OType  obj)
        {
            if (current != nullptr)
            {
                current->SetVectorItem(key, obj);
                return true;
            }
            return false;
        }
    };

    class JsonLexer
    {
    public:
        using uni_tr = std::unique_ptr<JsonLexer>;
        static uni_tr CreaetLexer() {
            auto ptr = new JsonLexer();
            uni_tr ret;
            ret.reset(ptr);
            return (ret);
        }
        void Parser(const char* buffer, const size_t& length)
        {
            parser_buffer = const_cast<char*>(buffer);
            parser_length = length;
            for (handle_index = 0; handle_index < length; ++handle_index)
            {
                HandleOne(buffer[handle_index]);
            }
        }
        ~JsonLexer()
        {
            for (auto& item : alloc_item)
            {
                delete item;
            }
        }

        JsonObject::OType Result()
        {
            if (parser_sentry == nullptr) {
                JsonObject::OType dt;
                return dt;
            }
            return parser_sentry->current;
        }


        void HandleOne(const char& one)
        {

            if (parser_sentry != nullptr) {
                if (parser_sentry->is_str && one != '\"') {
                    ParserValue(one);
                    return;
                }
            }
            switch (one) {
            case '{': ParserBracesOpen();  break;
            case '}': ParserBracesClose(); break;
            case '[': ParserSquareOpen();  break;
            case ']': ParserSquareClose(); break;
            case ',': ParserComma();       break;
            case ':': ParserColon();       break;
            case '\"': ParserQuotation();  break;
            case ' ':ParserSpace();       break;
            default: ParserValue(one);     break;

            }
        }

        void ParserBracesOpen()  //{
        {
            if (parser_sentry == nullptr)
            {
                parser_sentry = AllocJsonParserNode();
                parser_sentry->current = AllocJsonObject();
                parser_sentry->ClearBuffer();
                parser_sentry->Type = PropertyType::Object;
            }
            else
            {

                if (parser_sentry->pro_prc_type == PropertyProgross::key || parser_sentry->pro_prc_type == PropertyProgross::Value)
                {
                    if (parser_sentry->key_open && !parser_sentry->key_close)
                    {
                        ParserValue('{');
                        return;
                    }
                }

                if (parser_sentry->handle_object_open && !parser_sentry->key_buffer.HasStr())
                {
                    throw "Error! ParserIndex=" + std::to_string(handle_index);
                }
                JsonParserNode* sub = AllocJsonParserNode();
                sub->current = AllocJsonObject();
                sub->handle_object_open = true;
                sub->ClearBuffer();
                parser_sentry->ConnectNext(sub);
                sub->Type = PropertyType::Object;
                parser_sentry = sub; 
            }
        }
        void ParserBracesClose()//}
        {
            if (parser_sentry == nullptr || parser_sentry->parent == nullptr)
            {
                if (parser_sentry != nullptr)
                {
                    parser_sentry->TrySetProperty();
                }

                return;
            }
            if (parser_sentry->pro_prc_type == PropertyProgross::key || parser_sentry->pro_prc_type == PropertyProgross::Value)
            {
                if (parser_sentry->key_open && !parser_sentry->key_close)
                {
                    ParserValue('}');
                    return;
                }
            }
            if (parser_sentry->handle_object_close || !parser_sentry->handle_object_open)
            {
                throw "Error! ParserIndex=" + std::to_string(handle_index);
            }
            if (parser_sentry->Type == PropertyType::Object)
            {
                parser_sentry->TrySetProperty();
            }
            JsonParserNode* p = parser_sentry->parent; 

            if (p == nullptr)
            {
                return;
            }
            if (p->Type == PropertyType::Vector)
            {
                p->current->SetVectorItem(p->parent->key_buffer.value(), parser_sentry->current);
            }
            else if (p->Type == PropertyType::Object) {

                if (!p->TrySetObject(parser_sentry->current))
                {
                    throw "Error! ParserIndex=" + std::to_string(handle_index);
                }
            }
            FreeJsonParserNode(parser_sentry);
            parser_sentry = p; 

        }
        void ParserSquareOpen()//[
        {

            if (parser_sentry == nullptr)
            {
                parser_sentry = AllocJsonParserNode();
                parser_sentry->current = AllocJsonObject();
                parser_sentry->handle_vector_open = true;
                parser_sentry->ClearBuffer();
                parser_sentry->Type = PropertyType::Vector;
            }
            else
            {
                if (parser_sentry->handle_vector_open)
                {
                    //
                    throw "Error! ParserIndex=" + std::to_string(handle_index);
                }
                JsonParserNode* sub = AllocJsonParserNode();;
                sub->current = parser_sentry->current;
                sub->handle_vector_open = true;
                //
                if (!parser_sentry->key_buffer.HasStr())
                {
                    throw "Error! ParserIndex =" + std::to_string(handle_index);
                }
                JsonObject::VectorType vs;
                sub->current->vector_objects.insert(std::make_pair(parser_sentry->key_buffer.value(), vs));
                //
                sub->ClearBuffer();
                parser_sentry->ConnectNext(sub);
                sub->Type = PropertyType::Vector;
                parser_sentry = sub; //
            }
        }
        void ParserSquareClose()//]
        {
            if (!parser_sentry->handle_vector_open || parser_sentry->handle_vector_close)
            {
                return;
            }
            parser_sentry->handle_vector_close = true;

            JsonParserNode* p = parser_sentry->parent;
            FreeJsonParserNode(parser_sentry);
            if (p == nullptr) {
                return;
            }
            parser_sentry = p;
        }
        void ParserComma()//,
        {
            if (parser_sentry == nullptr) {
                throw "Error! ParserIndex=" + std::to_string(handle_index);
            }
            if (parser_sentry->key_buffer.Size() == 0 && parser_sentry->value_buffer.Size() == 0)
            {
                return;
            }
            if (parser_sentry->key_open && !parser_sentry->key_close)
            {
                parser_sentry->value_buffer.AddChar(',');
                return;
            }
            if (!parser_sentry->TrySetProperty())
            {
                //throw "Error! ParserIndex=" + std::to_string(handle_index);
            }
        }
        void ParserColon()//:
        {
            if (parser_sentry == nullptr) {
                throw "Error! ParserIndex=" + std::to_string(handle_index);
            }
            if (parser_sentry->key_open && parser_sentry->key_close)
            {
                parser_sentry->pro_prc_type = PropertyProgross::Value;
                parser_sentry->key_open = false;
                parser_sentry->key_close = false;
            }
            else
            {
                throw "Error! ParserIndex=" + std::to_string(handle_index);
            }
        }
        void ParserSpace()
        {
            if (parser_sentry == nullptr)
            {
                return;
            }
            if (parser_sentry->key_open && !parser_sentry->key_close && parser_sentry->pro_prc_type == PropertyProgross::key)
            {
                parser_sentry->key_buffer.AddChar(' ');
            }
            else if (parser_sentry->key_open && !parser_sentry->key_close && parser_sentry->pro_prc_type == PropertyProgross::Value)
            {
                parser_sentry->value_buffer.AddChar(' ');
            }
            return;
        }
        void ParserQuotation()//"
        {
            if (parser_sentry == nullptr)
            {
                throw "Error! ParserIndex = " + std::to_string(handle_index);
            }
            if (parser_sentry->pro_prc_type == PropertyProgross::Yet)
            {
                parser_sentry->pro_prc_type = PropertyProgross::key;
            }

            if (parser_sentry->pro_prc_type == PropertyProgross::key)
            {
                if (parser_sentry->key_open && parser_sentry->key_close)
                {
                    throw "Error! ParserIndex=" + std::to_string(handle_index);
                }
            }
            else if (parser_sentry->pro_prc_type == PropertyProgross::Value)
            {
                if (parser_sentry->key_open && parser_sentry->key_close)
                {
                    throw "Error! ParserIndex=" + std::to_string(handle_index);
                }
                if (parser_sentry->key_open)
                {
                    parser_sentry->pro_prc_type = PropertyProgross::Yet;
                }
            }

            if (parser_sentry->key_open)
            {
                parser_sentry->is_str = false;
                parser_sentry->key_close = true;
            }
            else
            {
                parser_sentry->is_str = true;
                parser_sentry->key_open = true;
            }
        }
        void ParserValue(const char& value)
        {
            if (value == '\r' || value == '\n' || value == '\t')
            {
                return;
            }
            if (value == '\t') {
                std::cout << "Invalid keycode:  " << handle_index << " value: " << value;
                return;
            }
            if (parser_sentry == nullptr)
            {
                return;
            }
            if (parser_sentry->pro_prc_type == PropertyProgross::key)
            {
                parser_sentry->key_buffer.AddChar(value);
            }
            else if (parser_sentry->pro_prc_type == PropertyProgross::Value)
            {
                parser_sentry->value_buffer.AddChar(value);
            }
        }


    private:
        JsonParserNode* parser_sentry{ nullptr };
        //
        char* parser_buffer{ nullptr };
        size_t parser_length{ 0 };
        //
        size_t handle_index;

        std::vector< JsonParserNode* > free_list;
        std::vector<JsonParserNode*> alloc_item;
        JsonParserNode* AllocJsonParserNode()
        {
            if (free_list.empty())
            {
                JsonParserNode* value = new JsonParserNode();
                alloc_item.push_back(value);
                return value;
            }
            JsonParserNode* ret = free_list.front();
            free_list.erase(free_list.begin());
            return ret;
        }

        JsonObject::OType AllocJsonObject() {
            JsonObject::OType type = std::make_shared<JsonObject>();
            return type;
        }

        void FreeJsonParserNode(JsonParserNode* target)
        {
            target->ClearAllState();
            target->current = nullptr;
            free_list.push_back(target);
        }
    };
}
#endif // JSON_HPP
