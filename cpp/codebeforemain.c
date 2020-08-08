#include <stdio.h>

__attribute__((constructor)) void f() {
    printf("function before main\n");
    printf("%s\n", __FUNCTION__);
}

__attribute__((destructor)) void g() {
    printf("%s\n", __FUNCTION__);
    printf("function after main\n");
}
int main() {
    printf("hello world\n");
    return 0;
}
