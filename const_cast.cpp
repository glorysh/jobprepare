#include <iostream>
using namespace std;

class B {
    int _x;
public:
    B(int x) : _x(x) {}
    virtual void f() {
        cout << "base virtual function." << endl;
    }
};

class D : public B{
    int _y;
public:
    D(int x, int y) : B(x), _y(y) {}
    void f() {
        cout << "derived virtual function." << endl;
    }
};

int main() {
    B b(1);
    D d(2, 3);
    B* p1 = &d;
    // B* p1 = &b; 转型失败
    if (D* p2 = dynamic_cast<D*>(p1)) {
        p2->f();
    }
    else {
        cout << "dynamic_cast failure" << endl;
    }
}