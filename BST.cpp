#include <iostream>
#include "tree_exception.h"
#include "BST.h"

BinaryTree::BinaryTree()
{
    root = nullptr;
    amount = 0;
}
BinaryTree::~BinaryTree()
{
    delete root;
}

double BinaryTree::averadge()
{
  if( amount == 0){
    throw EmptyTree();
  }
    double sum = 0;
    Node* current = root;
    sum = averadge(current, sum);
    return sum / amount;
}
double BinaryTree::averadge(Node* current, double sum)
{
    if (current != nullptr) {
        sum = averadge(current->left, sum);
        sum += (current->value);
        sum = averadge(current->right, sum);
    }
    return sum;
}
std::string BinaryTree::search(double value)
{
  if( amount == 0){
    throw EmptyTree();
  }
    std::string str;
    Node* temp = new Node;
    Node* current = root;
    temp->value = value;
    str = search(current, temp, str);
    return str;
}
std::string BinaryTree::search(Node* current, Node* temp, std::string str)
{


    if (temp->value == current->value) {
        str.append(std::to_string(current->value));
        return str;
    }
    if (temp->value < current->value) {
        if (current->left == nullptr) {
            throw OutOfRange();
        }
        str.append(std::to_string(current->value));
        str.append(" ");
        current = current->left;
        str = search(current, temp, str);
    }

    if (temp->value > current->value) {
        if (current->right == nullptr) {
            throw OutOfRange();
        }
        str.append(std::to_string(current->value));
        str.append(" ");
        current = current->right;
        str = search(current, temp, str);
    }
    return str;
}

void BinaryTree::add(double value)
{
    Node* temp = new Node;
    Node* current = root;
    temp->value = value;
      amount++;
    if (root == nullptr) {
        root = temp;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    add(current, temp);
}
void BinaryTree::add(Node* current, Node* temp)
{

    if (temp->value < current->value)  {
        if (current->left == nullptr) {
            current->left = temp;
            current->left->left = nullptr;
            current->left->right = nullptr;
            return;
        }
        current = current->left;
        add(current, temp);
    }

    if (temp->value >= current->value) {
        if (current->right == nullptr) {
            current->right = temp;
            current->right->left = nullptr;
            current->right->right = nullptr;
            return;
        }
        current = current->right;
        add(current, temp);
    }
}

double BinaryTree::add_averadge()
{
    double num = averadge();
    add(num);
    return num;
}
std::string BinaryTree::inOrderTraversal()
{
  if( amount == 0){
  throw EmptyTree();
  }
    std::string str;
    str = inOrderTraversal(root, str);
    return str;
}
std::string BinaryTree::inOrderTraversal(struct Node* current, std::string str)
{
    if (current != nullptr) {
        str = inOrderTraversal(current->left, str);
        str.append(std::to_string(current->value));
        str.append(" ");
        str = inOrderTraversal(current->right, str);
    }
    return str;
}

std::string BinaryTree::preOrderTraversal()
{
  if( amount == 0){
    throw EmptyTree();
  }
    std::string str;
    str = preOrderTraversal(root, str);
    return str;
}
std::string BinaryTree::preOrderTraversal(struct Node* current, std::string str)
{
    if (current != nullptr) {
        str.append(std::to_string(current->value));
        str.append(" ");
        str = preOrderTraversal(current->left, str);
        str = preOrderTraversal(current->right, str);
    }
    return str;
}

std::string BinaryTree::postOrderTraversal()
{
  if( amount == 0){
    throw EmptyTree();
  }
    std::string str;
    str = postOrderTraversal(root, str);
    return str;
}
std::string BinaryTree::postOrderTraversal(struct Node* current, std::string str)
{
    if (current != nullptr) {
        str = postOrderTraversal(current->left, str);
        str = postOrderTraversal(current->right, str);
        str.append(std::to_string(current->value));
        str.append(" ");
    }
    return str;
}
