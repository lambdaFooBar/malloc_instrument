
#include <cstdio>
#include <iostream>
#include <cassert>
#include <algorithm>

#include "MyArray.h"

MyArray::MyArray(int aMaxSize): numel{0}, maxSize{aMaxSize}, currSize{2} {
    //std::cout << "Allocated: " << this << std::endl;
    arr = (int*) malloc(currSize*sizeof(int));
    assert((arr == nullptr, "Cannot allocate. Out of memory!"));
}

MyArray::~MyArray() {
    //std::cout << "Freed: " << this << std::endl;
    free(arr);
}

int MyArray::append(int aVal) {
    //Check if current size is big enough
    //If it is not, realloc double of previous size to the max limit
    if (currSize >= maxSize) {
        return -1;
    }
    if (currSize < numel + 1) {
        currSize *= 2;
        currSize = std::min(currSize, maxSize);
        arr = (int*)realloc(arr, currSize * sizeof(int));
        assert((arr == nullptr, "Out of memory!"));
    }
    arr[numel++] = aVal; 
    return numel;
}

void MyArray::print() {
    std::cout << "[";
    for(int i = 0; i < numel; i++)
        std::cout << arr[i] << ", ";
    std::cout << "]" << std::endl;
}
