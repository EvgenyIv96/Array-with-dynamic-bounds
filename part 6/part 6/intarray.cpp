//
//  intarray.cpp
//  этапы
//
//  Created by Евгений on 14.04.16.
//  Copyright © 2016 Евгений. All rights reserved.
//

#include "intarray.hpp"

IntArray:: IntArray(int lb, int cnt, int val) throw(IntDeque::NoMemory) {
    
    try {
        
        IntList();
        
        size = 0;
        low = 0;
        high = 0;
        firstIndex = lb;
        
        for (int i = 0; i < cnt; i++) {
            
            *this + val;
            
        }

    } catch (IntDeque::NoMemory) {
        
        NoMemory();
        
    }
    
}

IntArray:: IntArray(const IntArray& _array) throw(IntDeque::NoMemory) {
    
    try {
        
        low = 0;
        high = 0;
        size = 0;
        firstIndex = _array.low;
        
        IntDequeElement* element = new IntDequeElement;
        
        element = _array.GetLeft();
        
        for (int i = _array.low; i <= _array.high; i++) {
            
            *this + element->GetElement();
            
            element = element->GetNext();
            
        }

        
    } catch (IntDeque::NoMemory) {
        
        NoMemory();
        
    }
    
}

int IntArray:: Low() throw(ArrayIsEmpty) {
    
    if (!size) {
        
        throw ArrayIsEmpty();
        
    }
    
    return low;
    
}

int IntArray:: High() throw(ArrayIsEmpty) {
    
    if (!size) {
        
        throw ArrayIsEmpty();
        
    }
    
    return high;
    
}

int IntArray:: Size() {
    
    return size;
    
}

int& IntArray:: operator[](int i) throw(WrongIndex, ArrayIsEmpty) {
    
    if (!size) {
        throw ArrayIsEmpty();
    }
    
    if ((i < low) || (i > high)) {
        throw WrongIndex();
    }
    
    
    GoToLeft();
    IntDequeElement* element = current;
    
    while (element->GetIndex() != i) {
        
        element = element->GetNext();
        
    }

    return element->GetElement();
    
}


void IntArray:: operator+(int element) throw(NoMemory) {
    
    try {
        
        IntList:: operator+(element);
        
        if (!size) {
            low = firstIndex;
            high = firstIndex;
        } else {
            high = high + 1;
        }
        
        size = size + 1;
        
        
        GoToRight();
        
        current->SetIndex(high);
        
        
    } catch (NoMemory) {
        
        NoMemory();
        
    }

    
}


void operator+(int element, IntArray& _array) throw(IntDeque::NoMemory) {
    
    try {
        
        IntDeque& deq = _array;
        
        operator+(element, deq);
        
        if (!_array.size) {
            
            _array.high = _array.firstIndex;
            _array.low = _array.firstIndex;
            
        } else {
            _array.low = _array.low - 1;
        }
        
        _array.size = _array.size + 1;
        
        _array.GoToLeft();
        
        _array.current->SetIndex(_array.low);
        
    } catch (IntDeque::NoMemory) {
        
        IntDeque:: NoMemory();
        
    }

}

int IntArray:: operator--() throw(ArrayIsEmpty) {
    
    IntDequeElement* removedElement = GetLeft();
    int removedValue;
    
    if (removedElement) {
        
        removedValue = IntList:: operator--();
        //   printf("---()\n");
        
        if (current) {
            size = size - 1;
            low = low + 1;
        } else {
            size = 0;
            low = 0;
            high = 0;
            firstIndex = removedElement->GetIndex();
        }
        
        return removedValue;
    }
    
    throw ArrayIsEmpty();
}

int IntArray:: operator--(int) throw(ArrayIsEmpty) {
    
    IntDequeElement* removedElement = GetRight();
    
    int removedValue;
    
    if (removedElement) {
        
        removedValue = IntList:: operator--(1);
        //  printf("---(int)\n");
        
        if (current) {
            
            size = size - 1;
            high = high - 1;
            
        } else {
            size = 0;
            low = 0;
            high = 0;
            firstIndex = removedElement->GetIndex();
        }
        
        return removedValue;
    }
    
    throw ArrayIsEmpty();
}

IntArray& IntArray:: operator = (const IntArray& array) {
    
    if (this != &array) {
        
        this->~IntArray();
        
        
        low = 0;
        high = 0;
        size = 0;
        firstIndex = array.low;
        
        IntDequeElement* element = new IntDequeElement;
        
        element = array.GetLeft();
        
        for (int i = array.low; i <= array.high; i++) {
            
            *this + element->GetElement();
            
            element = element->GetNext();
            
        }

        
    }
    
    return *this;
    
}

IntArray:: ~IntArray() {
    
    low = NULL;
    high = NULL;
    size = NULL;
    
}
