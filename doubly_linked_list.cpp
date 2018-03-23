/* Doubly linked list with constructor for deep copying */
#include <iostream>
#include "list_exception.h"
#include "doubly_linked_list.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}
DoublyLinkedList::~DoublyLinkedList()
{
  Node* firstElem = head;
  while(firstElem != nullptr) {
    Node* nextElem = firstElem->next;
    delete firstElem;
    firstElem = nextElem;
  }
}
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& baseList) //copy constructor
{
    if (baseList.head == nullptr) {
        head = nullptr;
    }
    else {
        head = new Node;
        head->data = baseList.head->data;
        head->prev = nullptr;
        Node* currPtr = head;//currPtr - point on the current (new) list
        Node* origPtr = baseList.head->next;//origPtr - point on the basic (original) list


        while (origPtr != nullptr) {
            Node* temp = currPtr;
            currPtr->next = new Node;

            currPtr = currPtr->next;
            currPtr->data = origPtr->data;

            currPtr->prev = temp;
            currPtr->prev->data = temp->data;

            origPtr = origPtr->next;
        }
        currPtr->next = nullptr;
        tail = currPtr;
    }
    length = baseList.length;
}

void DoublyLinkedList::push(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    temp->prev = nullptr;
    if (head == nullptr) {
        head = temp;
        tail = head;
    }
    else {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    length++;
}
void DoublyLinkedList::insert(int id, int value)
{
    if (id < 0) {
        throw NegativeIndex();

    }
    if (head == nullptr && id != 0) {
        throw EmptyList();
    }

    Node* newElem = new Node;
    newElem->data = value;
    Node* currentElem = head;
    length++;

    if (id == 0) {
        newElem->prev = nullptr;
        newElem->next = head;
        head->prev = newElem;
        head = newElem;
        return;
    }

    for (int i = 0; i < id; i++) {
        if (currentElem->next == nullptr) {
            if (id == i + 1) {
                newElem->next = nullptr;
                newElem->prev = currentElem;
                currentElem->next = newElem;
                newElem->next = nullptr;
                tail = newElem;
            }
            else {
                length--;
                throw OutOfRange();
            }
            return;
        }
        currentElem = currentElem->next;
    }

    newElem->prev = currentElem->prev;
    newElem->next = currentElem;
    currentElem->prev->next = newElem;
    currentElem->prev = newElem;
}
string DoublyLinkedList::toString()
{
    Node* temp = new Node;
    temp = head;
    string str = "";
    while (temp != nullptr) {
        str +=  to_string(temp->data) + " ";
        temp = temp->next;
    }
    return str;
}
void DoublyLinkedList::showList()
{
  string str = toString();
  cout<<str<< endl;
}

int DoublyLinkedList::deleteElem(int id)
{
    if (id < 0) {
        throw NegativeIndex();
      }
    if (head == nullptr) {
        throw EmptyList();
    }
    length--;
    Node* current = head;
    for (int i = 0; i < id; i++) {
        current = current->next;
        if (current == nullptr) {
            length++;
            throw OutOfRange();
        }
    }

    if (current->next == nullptr && current->prev == nullptr) {
        head = tail = nullptr; //if that is the only element in the list
    }
    else if (current->prev == nullptr) {
        current->next->prev = nullptr; //if that is the first element
        head = current->next;
    }
    else if (current->next == nullptr) {
        current->prev->next = nullptr; //if that is the last element
        tail = current->prev;
    }
    else {
        current->next->prev = current->prev;
        current->prev->next = current->next;
    }
    return current->data;
}
