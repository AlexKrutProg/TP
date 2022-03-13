#include <iostream>
#include "lib.h"

template<class T>
long long last(T array) {
    return array[array.sz-1];
}

template<class T>
long long first(T array) {
    return array[0];
}
