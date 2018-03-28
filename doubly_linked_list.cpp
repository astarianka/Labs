/* Doubly linked list with constructor for deep copying */
#include "list_exception.h"
#include "doubly_linked_list.h"

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
        return;
    }
    
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
    length = baseList.length;
}

void DoublyLinkedList::push(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    temp->prev = nullptr;
    length++;
    if (head == nullptr) {
        head = temp;
        tail = head;
        return;
    }
    
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}
void DoublyLinkedList::insert(int id, int value)
{
    if (id < 0) {
        throw NegativeIndex();
    }
    if (head == nullptr && id != 0) {
        throw EmptyList();
    }
    if (id > length) {
        throw OutOfRange();
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
    if (id == length - 1) {
        newElem->prev = tail;
        tail->next = newElem;
        newElem->next = nullptr;
        tail = newElem;
        return;
    }
    for (int i = 0; i < id; i++) {
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
    std::string str;
    while (temp != nullptr) {
        str.append(std::to_string(temp->data));
        str.append(" ");
        temp = temp->next;
    }
    return str;
}

int DoublyLinkedList::getElem(int id)
{
    if (id < 0) {
      throw NegativeIndex();
    }
    if (head == nullptr) {
        throw EmptyList();
    }
    if (id > length) {
        throw OutOfRange();
    }
    if( id == 0){
      return head->data;
    }
    if (id == length){
      return tail->data;
    }
    Node* currentElem = head;
    for (int i = 0; i < id; i++) {
        currentElem = currentElem->next;
    }
    return currentElem->data;
}

int DoublyLinkedList::deleteElem(int id)
{
    if (id < 0) {
        throw NegativeIndex();
      }
    if (head == nullptr) {
        throw EmptyList();
    }
    if (id > length - 1) {
        throw OutOfRange();
    }
    length--;
    Node* current = head;
    if (length == 0) {
        head = tail = nullptr;
        return current->data;
    }
    if (id == length) {
        current = tail;
        current->prev->next = nullptr;
        tail = current->prev;
        return current->data;
    }
    if (id == 0) {
        current->next->prev = nullptr;
        head = current->next;
        return current->data;
    }
    for (int i = 0; i < id; i++) {
        current = current->next;
        current->next->prev = current->prev;
        current->prev->next = current->next;
        return current->data;
    }
}
