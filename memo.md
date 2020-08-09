# 2020.8.7
1. RB tree
    - 不是严格平衡的二叉搜索树
    - 性质
        - 每个节点要么是红的，要么是黑的
        - 根节点是黑的
        - 每个叶节点（ 叶结点即指树尾端NIL指针或NULL结点）是黑的
        - 如果一个节点是红的，那么它的两个儿子节点都是黑的
        - 对于任一结点而言，其到叶结点树尾端NIL指针的每一条路径都包含相同数目的黑结点。
    - 左旋、 右旋 O(1)
    - 红黑树 vs AVL树：
        - 红黑树的算法时间复杂度和AVL相同，但统计性能比AVL树更高，所以在插入和删除中所做的后期维护操作肯定会比红黑树要耗时好多，但是他们的查找效率都是O(logN)，所以红黑树应用还是高于AVL树的. 实际上插入AVL树和红黑树的速度取决于你所插入的数据.如果你的数据分布较好,则比较宜于采用AVL树(例如随机产生系列数),但是如果你想处理比较杂乱的情况,则红黑树是比较快的。
2. shared_ptr实现
    - 对象指针、counter指针
    - 构造函数
    - 拷贝构造、拷贝赋值运算符（判断自赋值情况）
    - 析构函数
    - 指针解引用、访问运算符重载
3. 程序从编译到运行步骤 && 程序内存布局
    - 预处理(.i) 编译(汇编代码.s) 汇编(可重定位目标文件.o) 链接(可执行目标文件a.out)
    - 内存布局
        - 低地址->高地址的内存布局，text, data, bss, 堆(堆顶指针brk)，内存映射区，栈，argv/environ,  kernel
4. main函数的执行顺序
    - linux系统下程序的入口是”_start”，这个函数是linux系统库（Glibc）的一部分，当我们的程序和Glibc链接在一起形成最终的可执行文件的之后，这个函数就是程序执行初始化的入口函数。
    - _start函数
    - main函数运行之前的工作
        - 设置栈指针
        - 初始化static静态和global全局变量，即data段的内容
        - 将未初始化部分的赋初值：数值型short，int，long等为0，bool为FALSE，指针为NULL，等等，即.bss段的内容
        - 运行全局构造器，类似c++中全局构造函数
        - 将main函数的参数，argc，argv等传递给main函数，然后才真正运行main函数
5. malloc的原理与实现
    - malloc采用的是内存池的管理方式（ptmalloc），Ptmalloc 采用边界标记法将内存划分成很多块，从而对内存的分配与回收进行管理。为了内存分配函数malloc的高效性，ptmalloc会预先向操作系统申请一块内存供用户使用，当我们申请和释放内存的时候，ptmalloc会将这些内存管理起来，并通过一些策略来判断是否将其回收给操作系统。这样做的最大好处就是，使用户申请和释放内存的时候更加高效，避免产生过多的内存碎片。
6. 内存映射 mmap, munmap, 写时复制
7. brk指针，指向堆顶 brk(), sbrk() 负责分配与回收内存(移动brk指针)
8. 单例模式的3种写法，线程安全的写法(静态局部变量)
9. C++11新特性：
    - 语言可用性强化
        - nullptr 与 constexpr
        - 类型推导
            - auto
            - decltype
            - 尾返回类型、auto与decltype的配合
        - 基于范围的for循环
        - 初始化列表
            - std::initializer_list
            - 统一初始化语法
        - 面向对象
            - 显示虚函数重载
                - override
                - final
    
    - 语言运行期强化
        - lambda表达式
        - 函数对象包装器
            - std::function
            - std::bind/std::placeholder
        - 右值引用
            - 左值、右值（纯右值/将亡值）
            - 右值引用和左值引用
            - 移动语义
            - 完美转发

    - 智能指针和引用计数
        - RAII与引用计数
        - std::shared_ptr
        - std::unique_ptr
        - std::weak_ptr
10. 静态链接库和动态链接库
    - 静态链接库 在链接阶段，会将汇编生成的目标文件.o与引用到的库一起链接打包到可执行文件，因此对应的链接方式称为静态链接。
        - 特点：
            - 静态库对函数库的链接是放在编译时期完成的。
            - 程序在运行时与函数库再无瓜葛，移植方便。
            - 浪费空间和资源，因为所有相关的目标文件与牵涉到的函数库被链接合成一个可执行文件。
            - 静态库对程序的更新、部署和发布会带来麻烦如果静态库liba.lib更新了，所以使用它的应用程序都需要重新编译、发布给用户（对于玩家来说，可能是一个很小的改动，却导致整个程序重新下载，全量更新）。
    - 动态链接库 动态库在程序编译时并不会被连接到目标代码中，而是在程序运行是才被载入。不同的应用程序如果调用相同的库，那么在内存里只需要有一份该共享库的实例，规避了空间浪费问题。动态库在程序运行是才被载入，也解决了静态库对程序的更新、部署和发布页会带来麻烦。用户只需要更新动态库即可，增量更新。
        - 特点：
            - 动态库把对一些库函数的链接载入推迟到程序运行的时期。
            - 可以实现进程之间的资源共享。（因此动态库也称为共享库）
            - 将一些程序升级变得简单。
            - 甚至可以真正做到链接载入完全由程序员在程序代码中控制（显示调用）。
            - 与创建静态库不同的是，不需要打包工具（ar、lib.exe），直接使用编译器即可创建动态库。
# 2020.8.8
1. 类型转换方式
    - static_cast 任何具有明确定义的类型转换，只要不包含底层const，都可以使用static_cast
    - const_cast 只能改变运算对象的底层const属性。使用const_cast去除底层const属性的目的不是去修改它的内容（未定义行为）。**const_cast在重载函数中最有用**。
    ```cpp
    const string &shorterString(const string &s1, const string &s2) {
        return s1.size() <= s2.size() ? s1 : s2;
    }

    string &shorterString(string &s1, string &s2) {
        auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
        return const_cast<string&>(r);
    }
    ```
    - reinterpret_cast 通常为运算对象的位模式提供较低层次上的重新解释
    ```cpp
    int *ip;
    char *pc = reinterpret_cast<char*>(ip);
    // 异常的运行时行为
    string str(pc);
    ```
    - dynamic_cast 用于将基类的指针或引用安全地转换成派生类的指针或引用
        - 向下转型有两种情况：
            - 一种是基类指针所指对象是派生类类型的，这种转换是安全的
            - 一种是基类指针所指对象为基类类型，在这种情况下dynamic_cast在运行时做检查，转换失败，返回结果为0
            ```cpp
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
            ```
2. http相关知识总结
3. git的安装与使用以及关联远程仓库
# 2020.8.9
1. 进程、线程、协程
2. 作业调度算法
3. 进程间通信方式
4. 物理内存和虚拟内存
5. 线程同步
6. 死锁产生的条件和预防