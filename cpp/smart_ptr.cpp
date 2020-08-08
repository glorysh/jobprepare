#include <iostream>
#include <assert.h>
using namespace std;

template<typename T> 
class smart_ptr {
private:
    T* _ptr;
    size_t* _count;

public:
    smart_ptr(T* ptr = nullptr) : _ptr(ptr) {
        if (_ptr) {
            _count = new size_t(1);
        }
        else {
            _count = new size_t(0);
        }
    }

    smart_ptr(const smart_ptr& ptr) {
        if (this != &ptr) {
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;
            (*this->_count)++;
        }
    }

    smart_ptr& operator=(const smart_ptr& ptr) {
        if (this->_ptr == ptr._ptr) {
            return *this;
        }
        if (this->_ptr) {
            (*this->_count)--;
            if (*this->_count == 0) {
                delete this->_count;
                delete this->_ptr;
            }
        }
        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
        return *this;
    }

    T& operator*() {
        assert(this->_ptr != nullptr);
        return *this->_ptr;
    }
    
    T* operator->() {
        assert(this->_ptr != nullptr);
        return this->_ptr;
    }

    ~smart_ptr() {
        (*this->_count)--;
        if (*this->_count == 0) {
            delete this->_count;
            delete this->_ptr;
        }
    }

    size_t use_count() {
        return *this->_count;
    }
};


int main() {
    smart_ptr<int> sp(new int(100));
    smart_ptr<int> sp2(sp);
    smart_ptr<int> sp3(new int(20));
    sp2 = sp3;
    cout << sp.use_count() << endl;
    cout << sp3.use_count() << endl;
    cout << *sp3 << endl;
}