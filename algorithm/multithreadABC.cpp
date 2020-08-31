#include <bits/stdc++.h>
using namespace std;

mutex mtx;
condition_variable cvar;
char g_ch = 0;

void print_fun(char ch) {
    int cyle_cnt = 10;
    char ch_ = ch - 'A';
    for (int i = 0; i < cyle_cnt; ++i) {
        unique_lock<mutex> ulk(mtx);
        cvar.wait(ulk, [ch_] { return ch_ == g_ch; });
        cout << (char)(ch_ + 'A');
        g_ch = (ch_ + 1) % 3;
        ulk.unlock();
        cvar.notify_all();
    }
}

int main() {
    vector<thread> threads;
    threads.push_back(thread(print_fun, 'A'));
    threads.push_back(thread(print_fun, 'B'));
    threads.push_back(thread(print_fun, 'C'));
    for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
}