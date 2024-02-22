#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

template<typename T>
class GenericStack {
    unique_ptr<T[]> arr;
    size_t size, capacity;
    constexpr static size_t INITIAL_CAPACITY = 4;

public:
    GenericStack() : size(0), capacity(INITIAL_CAPACITY) {
        arr = make_unique<T[]>(INITIAL_CAPACITY);
    }

    size_t getSize() {
        return size;
    }

    virtual void resize(size_t new_capacity) {
        auto new_arr = make_unique<T[]>(new_capacity);
        for (int i = 0; i < min(size, new_capacity); i++) {
            new_arr[i] = arr[i];
        }
        arr = std::move(new_arr);
        capacity = new_capacity;
    }

    virtual T pop() {
        if (size) {
            return arr[size-- -1];
        }
        throw runtime_error("The stack is empty");
    }

    virtual void push(const T& e) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        arr[size++] = e;
    }

    virtual void push(T&& e) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        arr[size++] = std::move(e);
    }

    virtual T peek() {
        if (size) {
            return arr[size-1];
        }
        throw runtime_error("The stack is empty");
    }
};

class StringStack : public GenericStack<string> {
public:
    void push(const string& s) override {
        if (s.empty()) {
            throw domain_error("Empty string is not allowed");
        }
        GenericStack::push(s);
    }

    void push(string&& s) override {
        if (s.empty()) {
            throw domain_error("Empty string is not allowed");
        }
        GenericStack::push(std::move(s));
    }

    void concatTopTwo() {
        if (GenericStack::getSize() < 2) {
            throw runtime_error("Not enough elements");
        }
        string s2 = GenericStack::pop();
        string s1 = GenericStack::pop();
        GenericStack::push(s1 + s2);
    }
};

int main() {
    StringStack s;
    s.push("123");
    s.push("456");
    s.concatTopTwo();
    cout << s.peek() << endl;
}
