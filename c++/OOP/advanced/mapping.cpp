#include <iostream>
#include <assert.h>
#include <string>
#include <sstream>


template<typename KeyType, typename ValueType>
class Mapping{

    public:
    Mapping(KeyType key, ValueType value) : key_(key), value_(value){}

    std::string Print() const {
        std::ostringstream stream;
        stream<<key_<<": "<<value_;
        return stream.str();
    }

    KeyType key_;
    ValueType value_;


};

int main(){
    Mapping<std::string,int> mapping("age" , 29);
    assert(mapping.Print() == "age: 29");
}