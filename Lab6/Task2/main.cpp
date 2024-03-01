#include <iostream>
#include <unordered_map>

using namespace std;

template <typename K, typename V>
class Dictionary {
public:
    Dictionary() = default;

    // Get value for a key
    V get(const K& key) const {
        auto it = data_.find(key);
        return it != data_.end() ? it->second : V();
    }

    // Insert a key-value pair
    void put(const K& key, const V& value) {
        data_[key] = value;
    }

    // Remove a key-value pair
    void remove(const K& key) {
        data_.erase(key);
    }

    // Size of the dictionary
    size_t size() const {
        return data_.size();
    }

private:
    unordered_map<K, V> data_;
};

// Partial specialization for int values
template <typename K>
class Dictionary<K, int> {
public:
    Dictionary() = default;

    // Get value for a key
    int get(const K& key) const {
        auto it = data_.find(key);
        return (it != data_.end()) ? abs(it->second) : 0;
    }

    // Insert a key-value pair
    void put(const K& key, int value) {
        data_[key] = value;
    }

    // Remove a key-value pair
    void remove(const K& key) {
        data_.erase(key);
    }

    // Size of the dictionary
    size_t size() const {
        int sum = 0;
        for (const auto& [_, value] : data_) {
            sum += value;
        }
        return sum;
    }

private:
    unordered_map<K, int> data_;
};

int main() {
    // Dictionary for strings and integers
    Dictionary<string, int> dict1;
    dict1.put("s1", 25);
    dict1.put("s2", 33);

    cout << "s1: " << dict1.get("s1") << endl;
    cout << "s2: " << dict1.get("s2") << endl;

    // Dictionary for strings and int (using partial specialization)
    Dictionary<string, int> dict2;
    dict2.put("v1", -5);
    dict2.put("v2", 10);

    cout << "v1: " << dict2.get("v1") << endl;
    cout << "Sum: " << dict2.size() << endl;

    return 0;
}
