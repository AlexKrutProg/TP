#include <iostream>
#include "main.h"


Array::Array(size_t sz): sz(sz) {
    arr = new long long[sz];
    for (size_t i = 0; i < sz; ++i) {
        *(arr + i) = i + 1;
    }
}

Array::~Array() {
    delete arr;
}


long long& Array::operator[](size_t index) {
    return *(arr + index);
}

void print(size_t sz) {
    Array array(sz);
    for (size_t i = 0; i < sz; ++i) {
        std::cout<< array[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    print(10);
    Array arr(5);
    std::cout << last<Array>(arr);
    //std::cout << first<Array>(Array(10));
    return 0;
}
