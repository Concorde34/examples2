#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
private:
    struct node
    {
        int data;
        node* pNext;
    };
    node* head;
    int size;

    int min;

public:
    LinkedList();
    ~LinkedList();

    void push_back(int);
    void DebugPrint() const;
    int getElement(int) const;
    int getSize() const;
    int getMax() const;
    int getMin();
    bool allIsIdent() const;
    void remAllMin();
    void removeAt(int);
    void remove();
    void pop_front();

};

#endif // LINKEDLIST_H
