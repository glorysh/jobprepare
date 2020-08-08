#include <iostream>
#include <mutex>
using namespace std;
std::mutex mt;

// 实现一：单线程使用，多线程不安全
// _instance没有加锁，可能会创建多个Singleton对象

// class Singleton {
// public:
//     static Singleton* instance();
// protected:
//     Singleton() {}
// private:
//     static Singleton* _instance;
// };

// Singleton* Singleton::_instance = nullptr;

// Singleton* Singleton::instance() {
//     if (_instance == nullptr) {
//         _instance = new Singleton();
//     }
//     return _instance;
// }


// 实现二：多线程安全，加锁代价高
// 加锁解决了线程安全问题，但是有些资源浪费，每次instance函数调用时都需要请求加锁
// class Singleton {
// public:
//     static Singleton* instance();
// protected:
//     Singleton() {}
// private:
//     static Singleton* _instance;
// };

// Singleton* Singleton::_instance = nullptr;

// Singleton* Singleton::instance() {
//     mt.lock();
//     if (_instance == nullptr) {
//         _instance = new Singleton();
//     }
//     mt.unlock();
//     return _instance;
// }


// 实现三：（C++11版本最简洁的跨平台方案） 推荐版本
// Meyers Singleton
// 局部静态变量只会初始化一次, 线程安全
// C++11 If control enters the declaration concurrently while the variable is being initialized, 
// the concurrent execution shall wait for completion of the initialization.
class Singleton {
public:
    // 注意返回的是引用
    static Singleton& getInstance() {
        static Singleton value;     // 静态局部变量
        return value;
    }

private:
    Singleton() = default;
    Singleton(const Singleton&) = delete;   // 禁用拷贝构造函数
    Singleton& operator=(const Singleton&) = delete;    // 禁用拷贝赋值运算符
};


int main() {
    Singleton& s1 = Singleton::getInstance();
    cout << &s1 << endl;

    Singleton& s2 = Singleton::getInstance();
    cout << &s2 << endl;

    return 0;
}