#include <iostream>
#include "main.h"

void print() {
    for (size_t i = 0; i < sz; ++i) {
        std::cout<< arr[i] << " ";
    }
}

int main() {
    print();
    return 0;
}
