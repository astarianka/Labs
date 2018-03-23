#ifndef SINGLY_LINKED_LIST_INCLUDED
#define SINGLY_LINKED_LIST_INCLUDED
#include <string>
class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node *head, *tail;
    int length;
    public:
      class iterator
        {
        private:
            const SinglyLinkedList &list;
            Node *current;
            int index;
        public:
            iterator(const SinglyLinkedList &s): list(s), index(0)
            {
                current = list.head;
            }

            iterator(const SinglyLinkedList &s, int size): list(s),index(size)
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

            bool operator != (const iterator& other)
            {
                return index != other.index;
            }

            int operator *()
            {
                if (current) {
                    return current->data;
                }
                return -1;
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
    SinglyLinkedList();
    ~SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList& baseList);
    void push(int value);
    void insert(int id, int value);
    void showList();
    std::string toString();
    int deleteElem(int id);
};

#endif // SINGLY_LINKED_LIST_INCLUDED
