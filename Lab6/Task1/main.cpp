#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class Wrapper {
public:
    Wrapper(const T& value) : value_(value) {}

    T getValue() const {
        return value_;
    }

private:
    T value_;
};

// Explicit specialization for char*
template <>
class Wrapper<char*> {
public:
    Wrapper(const char* value) : value_(value) {}

    // Modified getValue() to return string length
    int getValue() const {
        return strlen(value_);
    }

private:
    const char* value_;
};

int main() {
    Wrapper<int> intWrapper(42);
    cout << "Wrapped integer value: " << intWrapper.getValue() << endl;

    Wrapper<char*> stringWrapper("Hello, world!");
    cout << "Wrapped string length: " << stringWrapper.getValue() << endl;

    return 0;
}