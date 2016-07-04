//
//  intarray.hpp
//  этапы
//
//  Created by Евгений on 14.04.16.
//  Copyright © 2016 Евгений. All rights reserved.
//

#include <stdio.h>
#include "intlist.hpp"

class IntArray : public IntList {
    int low;
    int high;
    int size;
    int firstIndex;

public:
    
    class ArrayIsEmpty{};
    class WrongIndex{};
    
    IntArray(): IntList(), size(0), low(0), high(0), firstIndex(1) {}
    IntArray(int lb): IntList(), size(0), low(0), high(0), firstIndex(lb) {}
    IntArray(int lb, int cnt, int val) throw(IntDeque::NoMemory);
    IntArray(const IntArray& _array) throw(IntDeque::NoMemory);
    
    int Low() throw(ArrayIsEmpty);
    int High() throw(ArrayIsEmpty);
    int Size();
    int& operator[](int i) throw(WrongIndex, ArrayIsEmpty);
    
    void operator+(int element) throw(NoMemory);
    friend void operator+(int element, IntArray& _array) throw(IntDeque::NoMemory);
    int operator--() throw(ArrayIsEmpty);
    int operator--(int) throw(ArrayIsEmpty);
    IntArray& operator=(const IntArray& array);
    
    ~IntArray();

};

void operator+(int element, IntArray& _array) throw(IntDeque::NoMemory);