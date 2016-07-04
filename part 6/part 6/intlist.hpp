#include "intdeque.hpp"

class IntList : public IntDeque {
    
public:
    
    IntList():IntDeque(), current(GetLeft()){}

    IntDequeElement *current;

    class NoCurrentElement{};
    class NoNextElement{};
    class NoPrevElement{};
    class ListIsEmpty{};
    
    IntDequeElement* GetCurrent();
    
    void GoToLeft();
    void GoToRight();
    void GoToNext() throw(NoCurrentElement, NoNextElement);
    void GoToPrev() throw(NoCurrentElement, NoPrevElement);
    
    int Fetch() throw(NoCurrentElement);
    void Store(int elem) throw(NoCurrentElement);
    
    void operator+(int element) throw(NoMemory);
    friend void operator+(int element, IntList& _list) throw(IntDeque::NoMemory);
    int operator--() throw(ListIsEmpty);
    int operator--(int) throw(ListIsEmpty);
    
    ~IntList();
    
};

void operator+(int elem, IntList& _list) throw(IntDeque::NoMemory);
