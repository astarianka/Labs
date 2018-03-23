/* Singly linked list with constructor for deep copying */
#include <iostream>
#include "singly_linked_list.h"
#include "list_exception.h"
using namespace std;

SinglyLinkedList::SinglyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}
SinglyLinkedList::~SinglyLinkedList()
{
  Node* firstElem = head;
  while(firstElem != nullptr) {
    Node* nextElem = firstElem->next;
    delete firstElem;
    firstElem = nextElem;
  }
}
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& baseList)
{
    if (baseList.head == nullptr)
        head = nullptr;
    else {
        head = new Node;
        head->data = baseList.head->data;
        Node* currPtr = head; //currPtr - point on the current (new) list
        Node* origPtr = baseList.head->next; //origPtr - point on the basic (original) list

        while (origPtr != nullptr) {
            currPtr->next = new Node;
            currPtr = currPtr->next;
            currPtr->data = origPtr->data;
            origPtr = origPtr->next;
        }
        currPtr->next = nullptr;
        tail = currPtr;
    }
      length = baseList.length;
}
void SinglyLinkedList::push(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    length++;
}
void SinglyLinkedList::insert(int id, int value)
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
        newElem->next = head;
        head = newElem;
        return;
    }
    if (id == 1) {
        newElem->next = currentElem->next->next;
        currentElem->next = newElem;
        return;
    }
    for (int i = 1; i < id; i++) {

        if (currentElem->next == nullptr) {
            if (id == i + 1) {
                newElem->data = value;
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
    newElem->next = currentElem->next;
    currentElem->next = newElem;
}
void SinglyLinkedList::showList()
{
  string str = toString();
  cout<<str<< endl;
}
string SinglyLinkedList::toString()
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
int SinglyLinkedList::deleteElem(int id)
{
  Node* temp = new Node;
  if (id < 0) {
    throw NegativeIndex();
  }
  if (head == nullptr) {
      throw EmptyList();
  }
    length--;
    Node* current = head;
    if (id == 0) {
        head = head->next;
        return current->data;
    }
    for (int i = 1; i < id; i++) {
        current = current->next;
        if (current == nullptr) {
            length++;
            throw OutOfRange();
        }
    }
    /* if that is the last element*/
    if (current->next->next == nullptr) {
        temp = current->next;
        current->next = nullptr;
        tail = current;
        return temp->data;
    }
    temp = current->next;
    current->next = current->next->next;
    return temp->data;
}
