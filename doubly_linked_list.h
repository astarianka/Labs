#ifndef DOUBLY_LINKED_LIST_H_INCLUDED
#define DOUBLY_LINKED_LIST_H_INCLUDED
#include "list_exception.h"
#include <string>
class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node *prev, *next;
    };
    Node *head, *tail;
int length;
public:
  class iterator
    {
    private:
        const DoublyLinkedList &list;
        Node *current;
        int index;
    public:
        iterator(const DoublyLinkedList &s): list(s), index(0)
        {
            current = list.head;
        }

        iterator(const DoublyLinkedList &s, int size): list(s),index(size)
        {

        }
        iterator(const iterator& other):list(other.list),index(other.index)
        {

        }
        void operator++()
        {
            current = current->next;
            index++;
        }

        void operator--()
        {
            current = current->prev;
            index++;
        }

        bool operator != (const iterator& other)
        {
            return index != other.index;
        }

        int operator *()
        {
            if (current) {
                return current->data;
            }
            throw OutOfRange();
        }
    };
    iterator begin()
    {
        iterator it(*this);
        return it;
    }
    iterator end()
    {
        iterator it(*this, size());
        return it;
    }
    int size(){
      return length;
    }
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& baseList);
    void push(int value);
    void insert(int id, int value);
    int getElem(int id);
    std::string toString();
    int deleteElem(int id);
};

#endif // DOUBLY_LINKED_LIST_H_INCLUDED
