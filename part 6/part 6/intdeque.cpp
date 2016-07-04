#include "intdeque.hpp"
#include "stdio.h"
#include "stdlib.h"
#include "new"

IntDequeElement::IntDequeElement() {
    element = 0;
    prev = NULL;
    next = NULL;
}

IntDequeElement::IntDequeElement(int _element) {
    element = _element;
    prev = NULL;
    next = NULL;
}

IntDequeElement::IntDequeElement(int _element, IntDequeElement * _prev, IntDequeElement * _next) {
    element = _element;
    prev = _prev;
    next = _next;
}

void IntDequeElement::SetElement(int _element) {
    element = _element;
}

int& IntDequeElement::GetElement() {
    return element;
}

void IntDequeElement::SetNext(IntDequeElement * _next) {
    next = _next;
}
IntDequeElement * IntDequeElement::GetNext() {
    return next;
}
void IntDequeElement::SetPrev(IntDequeElement * _prev) {
    prev=_prev;
}
IntDequeElement * IntDequeElement::GetPrev() {
    return prev;
}

int IntDequeElement:: GetIndex() {
    return index;
}

void IntDequeElement:: SetIndex(int _index) {
    index = _index;
}

IntDeque::IntDeque() {
    left = NULL;
    right = NULL;
}

IntDequeElement* IntDeque:: GetLeft() {
    
    return left;
    
}

IntDequeElement* IntDeque:: GetLeft() const {
    
    return left;
    
}

IntDequeElement* IntDeque:: GetRight() {
    
    return right;
    
}

void IntDeque::operator+(int element) throw(NoMemory){
    
    if (left == NULL) {
        
        IntDequeElement *elem;
        
        try {
            elem = new IntDequeElement(element, NULL, NULL);
        }
        
        catch(std::bad_alloc){
            throw NoMemory();
        }
        
        left = elem;
        right = elem;
        
        return;
        
    } else {
        
        IntDequeElement *elem;
        
        try {
            elem = new IntDequeElement(element, right, NULL);
        }
        
        catch(std::bad_alloc){
            throw NoMemory();
        }
        
        right->SetNext(elem);
        right = elem;
        
        return;
    }
}

int IntDeque::operator--() throw(DequeIsEmpty){
   
    IntDequeElement *tmp;

    tmp = left;

    if (left != NULL) {
        if (tmp->GetNext() != NULL) {

            tmp->GetNext()->SetPrev(NULL);
            left = tmp->GetNext();

        } else {

            left = NULL;
            right = NULL;

        }

        int res = tmp->GetElement();
        
     //   printf("--list\n");

        delete tmp;

        return res;
    }

    throw DequeIsEmpty();
}

int IntDeque::operator--(int) throw(DequeIsEmpty){

    IntDequeElement *tmp;

    tmp = right;

    if (right != NULL) {

        if (tmp->GetPrev() != NULL) {

            tmp->GetPrev()->SetNext(NULL);
            right = tmp->GetPrev();

        } else {

            left = NULL;
            right = NULL;

        }

        int res = tmp->GetElement();
        
       // printf("list--\n");

        delete tmp;
        return res;
    }

    throw DequeIsEmpty();
}

void operator+(int element, IntDeque& _deque) throw(IntDeque::NoMemory){

    if (_deque.left == NULL) {
        
        IntDequeElement *elem;
        
        try {
            elem = new IntDequeElement(element, NULL, NULL);
        }
        
        catch(std::bad_alloc){
            throw IntDeque::NoMemory();
        }
        
        _deque.left = elem;
        _deque.right = elem;
        
        return;
        
    } else {
        
        IntDequeElement *elem;
        
        try {
            elem = new IntDequeElement(element, NULL, _deque.left);
        }
        
        catch(std::bad_alloc){
            throw IntDeque::NoMemory();
        }
        
        _deque.left->SetPrev(elem);
        _deque.left = elem;
        
        return;
    }
}

IntDeque::~IntDeque() {
    
    while(left) {
        
        IntDequeElement *tmp;
        
        tmp = left;
        
        if (left != NULL) {
            if (tmp->GetNext() != NULL) {
                
                tmp->GetNext()->SetPrev(NULL);
                left = tmp->GetNext();
                
            } else {
                
                left = NULL;
                right = NULL;
                
            }
            
            delete tmp;
        }
        
    }
        
}
