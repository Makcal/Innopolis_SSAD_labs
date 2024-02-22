#include <iostream>
#include <memory>

using namespace std;

class Box {
public:
    int val;
    weak_ptr<Box> wp;

    explicit Box(int v) : val(v) {
        cout << "Created " << v << endl;
    }

    virtual ~Box() {
        cout << "Deleted " << val << endl;
    };
};

int create_unique(int n) {
    auto box_p = make_unique<Box>(n);
    auto another_p = std::move(box_p);
    return another_p->val;
}

void create_shared_boxes() {
    auto p1 = make_shared<Box>(1);
    auto p2 = make_shared<Box>(2);
    cout << "Before: " << p2.use_count() << endl;
    auto p3 = p2;
    cout << "After copying: " << p2.use_count() << endl;
    p3.reset();
    cout << "After reset: " << p2.use_count() << endl;
    p2.reset();
    cout << "Finally: " << p2.use_count() << endl;
}

void show_weak_pointers() {
    auto p1 = make_shared<Box>(1);
    auto p3 = make_shared<Box>(2);
    p1->wp = weak_ptr(p3);
    auto p2 = weak_ptr(p1);
    cout << "Is expired: " << p2.expired() << endl;
    cout << shared_ptr(p2)->val << endl;
    p1.reset();
    cout << "Is expired: " << p2.expired() << endl;
}

int main() {
    cout << create_unique(5) << endl;
    cout << "========================" << endl;
    create_shared_boxes();
    cout << "========================" << endl;
    show_weak_pointers();
}

/* report
 Unique_ptr:
Manages exclusive ownership.
Allows efficient transfer of ownership.
Automatically deallocates resources when out of scope.

 Shared_ptr:
Enables shared ownership.
Maintains reference count for shared objects.
Facilitates collaborative memory management.

 Weak_ptr:
Holds non-owning references.
Allows checking object validity without affecting ownership.
Helps break circular references.
 */
