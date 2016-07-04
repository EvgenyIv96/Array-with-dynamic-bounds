class IntDequeElement {

    int element;
    IntDequeElement * next;
    IntDequeElement * prev;
    
protected:
    int index;
    
public:
    IntDequeElement();
    IntDequeElement(int _element);
    IntDequeElement(int _element, IntDequeElement * _prev, IntDequeElement * _next);
    void SetElement(int _element);
    int& GetElement();
    void SetNext(IntDequeElement * _next);
    IntDequeElement * GetNext();
    void SetPrev(IntDequeElement * _prev);
    IntDequeElement * GetPrev();
    
    int GetIndex();
    void SetIndex(int index);
};

class IntDeque {
    IntDequeElement * left;
    IntDequeElement * right;

public:
    class NoMemory{};
    class DequeIsEmpty{};
    IntDeque();
    void operator+(int element) throw(NoMemory);
    friend void operator+(int element, IntDeque& _deque) throw(IntDeque::NoMemory);
    int operator--() throw(DequeIsEmpty);
    int operator--(int) throw(DequeIsEmpty);
    ~IntDeque();

protected:
    IntDequeElement* GetLeft();
    IntDequeElement* GetRight();
    IntDequeElement* GetLeft() const;
    
};

void operator+(int elem, IntDeque& _deque) throw(IntDeque::NoMemory);
