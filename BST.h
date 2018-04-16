#ifndef BST_H
#define BST_H
#include <string>
class BinaryTree {
private:
    struct Node {
        double value;
        Node *left, *right;
    };
    Node* root;
    int amount;

    void add(Node* current, Node* temp);
    double averadge(Node* current, double sum);
    std::string search(Node* current, Node* temp, std::string str);
    std::string inOrderTraversal(struct Node* current, std::string str);
    std::string preOrderTraversal(struct Node* current, std::string str);
    std::string postOrderTraversal(struct Node* current, std::string str);


public:
    BinaryTree();
    ~BinaryTree();
    void add(double value);
    double averadge();
    double add_averadge();
    std::string inOrderTraversal();
    std::string preOrderTraversal();
    std::string postOrderTraversal();
    std::string search(double value);
};

#endif // BST_H
