#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class CircularBuffer {
private:
    vector<T> v;

public:
    explicit CircularBuffer() = default;

    void push(T e) {
        v.push_back(e);
    }

    T pop(int i) {
        auto t = v[i];
        v.erase(v.begin() + i);
        return t;
    }

    int size() {
        return v.size();
    }

    void empty() {
        v.clear();
    }

    class Iterator;

    Iterator begin() {
        return Iterator(this, 0);
    }

    friend class Iterator;
    class Iterator {
    private:
        CircularBuffer* buffer;
        int p;

        friend CircularBuffer;
        Iterator(CircularBuffer* buffer, int p) : p(p), buffer(buffer) {}

    public:
        T& operator *() {
            return buffer->v[p];
        }

        bool operator==(const Iterator& other) {
            return other.p == p;
        }

        bool operator!=(const Iterator& other) {
            return !operator==(other);
        }

        Iterator& operator++() {
            p++;
            if (p == buffer->v.size()) {
                p = 0;
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator it = *this;
            operator++();
            return it;
        }
    };
};

int main() {
    CircularBuffer<int> b;
    b.push(3);
    b.push(2);
    b.push(1);
    auto it = b.begin();
    for (auto i = 0; i < 9; i++, it++) {
        cout << *it << '\n';
    }
}
