#include "ThreadPool.h"
#include <iostream>
#include <unistd.h>
using namespace std;

class work {
public:
    work(int x) : id(x) {}
    ~work() {}
    
    void process() {
        printf("doing job %d\n", id);
    }

    int id;
};

int main() {
    auto *pool = new threadpool<work>();
    work* jobs[10];
    for (int i = 0; i < 10; ++i) {
        jobs[i] = new work(i);
        pool->append(jobs[i]);
    }
    sleep(10);
    delete pool;
    for (int i = 0; i < 10; ++i) {
        delete jobs[i];
    }
}