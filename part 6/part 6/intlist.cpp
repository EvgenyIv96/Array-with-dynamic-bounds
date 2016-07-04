//
//  intlist.cpp
//  этапы
//
//  Created by Евгений on 10.04.16.
//  Copyright © 2016 Евгений. All rights reserved.
//

#include "intlist.hpp"
#include <stdio.h>

IntDequeElement* IntList:: GetCurrent() {
    
    return current;
    
}

void IntList:: GoToLeft() {
    
    current = GetLeft();
   // printf("GoToLeft()\n");
    
}


void IntList:: GoToRight() {
    
    current = GetRight();
   // printf("GoToRight()\n");
    
}

void IntList:: GoToNext() throw(NoCurrentElement, NoNextElement) {
    
    if (current) {
        
        if (current->GetNext()) {
            
            current = current -> GetNext();
            return;
            
        }
            throw NoNextElement();
        
    }
    
    throw NoCurrentElement();
    
}

void IntList:: GoToPrev() throw(NoCurrentElement, NoPrevElement) {
    
    if (current) {
        
        if (current->GetPrev()) {
            
            current = current -> GetPrev();
            return;
            
        }
        throw NoPrevElement();
        
    }
    
    throw NoCurrentElement();
}

int IntList:: Fetch() throw(NoCurrentElement) {
    
    if (current) {
      //  printf("Fetch()\n");
        return current->GetElement();
        
    }
    
    throw NoCurrentElement();
}

void IntList:: Store(int elem) throw(NoCurrentElement) {
    
    if (current) {
        
        current->SetElement(elem);
        return;
    }
    
    throw NoCurrentElement();
    
}


void IntList:: operator+(int element) throw(NoMemory) {
    
    try {
        
        IntDeque:: operator+(element);
        
        GoToRight();
        
    } catch (NoMemory) {
        
        NoMemory();
        
    }
    
    
    
}


int IntList:: operator--() throw(ListIsEmpty) {
    
    IntDequeElement* removedElement = GetLeft();
    int removedValue;
    
    
    if (removedElement) {
        
        removedValue = IntDeque:: operator--();
        //   printf("---()\n");
        
        current = removedElement->GetNext();
        return removedValue;
    }
    
    throw ListIsEmpty();
}

int IntList:: operator--(int) throw(ListIsEmpty) {
    
    IntDequeElement* removedElement = GetRight();
    int removedValue;
    
    if (removedElement) {
        
        removedValue = IntDeque:: operator--(1);
        //  printf("---(int)\n");
        
        current = removedElement->GetPrev();
        return removedValue;
    }
    
    throw ListIsEmpty();
    
}

void operator+(int elem, IntList& _list) throw(IntDeque::NoMemory) {
    
    try {
        
        IntDeque& deq = _list;
        
        operator+(elem, deq);
        
        _list.GoToLeft();
        
    } catch (IntDeque::NoMemory) {
        
        IntDeque:: NoMemory();
        
    }
    
}

IntList::~IntList() {
    
    current = NULL;
    
}