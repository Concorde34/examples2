#include "linkedlist.h"
#include <QDebug>

LinkedList::LinkedList() :
    head(nullptr),
    size(0)
    {}

LinkedList::~LinkedList()
{
    remove();
    delete head;
}

void LinkedList::remove()
{
    node* temp = head;
    while(temp != nullptr)
    {
        head = temp->pNext;
        delete temp;
        temp = head;
    }
    head = temp;
    size = 0;
}

void LinkedList::push_back(int data)
{
    node* temp;
    if(head == nullptr)
    {
        temp = new node;
        temp->pNext = nullptr;
        head = temp;
        head->data = data;
    }
    else
    {
        temp = head;
        while(temp->pNext != nullptr)
        {
            temp = temp->pNext;
        }
        node* temp2;
        temp2 = new node;
        temp2->data = data;
        temp2->pNext = nullptr;
        temp->pNext = temp2;
    }
    size++;
}

void LinkedList::DebugPrint() const
{
    qDebug() << "Список:\n";
    node* temp;
    if(head == nullptr)
    {
        qDebug() << "Список пустой!\n";
    }
    else
    {
        temp = head;
        while(temp != nullptr)
        {
            qDebug() << temp->data << "\n";
            temp = temp->pNext;
        }
    }
}

int LinkedList::getElement(int el) const
{
    if(head == nullptr)
    {
        throw (QString)"List is empty";
    }
    else
    {
        if(el < size && el >= 0)
        {
            node* temp = head;

            for(int i = 0; i != el; i++)
            {
                temp = temp->pNext;
            }
            return temp->data;
       }
        else
        {
            throw (QString)"Incorrect number of element";
        }

    }
}
//            int i = 0;
//            while(temp != nullptr)
//            {
//                if(i == el)
//                {
//                    return temp->data;
//                }
//                else
//                {
//                    temp = temp->pNext;
//                    i++;
//                }
//            }

int LinkedList::getSize() const
{
    return size;
}

int LinkedList::getMin()
{
    if(size > 0)
    {
        int min = getElement(0);
        for(int i = 0; i < size; i++)
        {
            if(getElement(i) < min)
            {
                min = getElement(i);
            }
        }
        this->min = min;
        return min;
    }
    else
    {
        throw (QString)"Error, List is empty!";
    }
}

int LinkedList::getMax() const
{
    if(size > 0)
    {
        int max = getElement(0);
        for(int i = 0; i < size; i++)
        {
            if(getElement(i) > max)
            {
                max = getElement(i);
            }
        }
        return max;
    }
    else
    {
        throw (QString)"Error, List is empty!";
    }
}

bool LinkedList::allIsIdent() const
{
    if(size > 1)
    {
        int tmp = getElement(0);
        for(int i = 0; i < size; i++)
        {
            if(tmp != getElement(i))
            {
                return false;
            }
        }
        return true;
    }
}

void LinkedList::remAllMin()
{
    int min = getMin();
    for(int i = 0; i < size; i++)
    {
        if(getElement(i) == min)
        {
            removeAt(i); // Также проблема может быть в передачи неверного индекса
        }
    }
}

void LinkedList::removeAt(int index)
{
    if(index == 0)
    {
        // pop_front работает, значит нужно искать проблему в остальном коде этой функции.
        pop_front();
    }
    else
    {
        node* previous = head;
        for(int i = 0; i < index; i++)
        {
            previous = previous->pNext;
        }
        node* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        size--;
    }
}

void LinkedList::pop_front()
{
    node* temp = head;
    head = head->pNext;
    delete temp;

    size--;
}















