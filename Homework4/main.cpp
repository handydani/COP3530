#include <iostream>
#include "binnode.h"
#include "morris.h"
#include <stdexcept>
template <typename T>
void morris(Node<int> * root);

void inordermorris(Node<int> * root){
    //SLR
    if (!root){
        return;
    }
    Node <int> * curr = new Node<int>;
    Node <int> * temp = new Node<int>;

    curr = root;
    while(curr != nullptr){
        if (curr->left == nullptr){
            std::cout << curr->data << " ";
            curr = curr->right;
        }
        else{
            temp = curr->left;
            while(temp->right && temp->right != curr){
                temp = temp->right;
            }
                if(temp->right == nullptr){
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    temp->right = nullptr;
                    std::cout << curr->data <<" ";
                    curr = curr->right;
                }
        }
    }

    std::cout <<"\n";

}
void preordermorris(Node<int> * root){
    if (!root){
        return;
    }
    Node <int> * curr = new Node<int>;
    Node <int> * temp = new Node<int>;

    curr = root;
    while(curr != nullptr){
        if (curr->left == nullptr){
            std::cout << curr->data << " ";
            curr = curr->right;
        }
        else{
            temp = curr->left;
            while(temp->right && temp->right != curr){
                temp = temp->right;
            }
                if(temp->right == curr){
                    temp->right = nullptr;
                    curr = curr->right;
                }
                else{
                    std::cout << curr->data <<" ";
                    temp->right = curr;
                    curr = curr->left;
                }
        }
    }

    std::cout <<"\n";

}
void postordermorris(Node<int> * root){
    if (!root){
        return;
    }
    Node <int> * curr = new Node<int>;
    Node <int> * temp = new Node<int>;

    curr = root;
    while(curr != nullptr){
        if (curr->left == nullptr){
            std::cout << curr->data << " ";
            curr = curr->right;
        }
        else{
            temp = curr->left;
            while(temp->right && temp->right != curr){
                temp = temp->right;
            }
                if(temp->right == nullptr){
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    std::cout << curr->data <<" ";
                    temp->left = curr;
                    curr = curr->right;
                }
        }
    }

    std::cout <<"\n";

}
int main()
{
    Node<int> * root = new Node<int>;
    Node<int> * child1 = new Node<int>;
    Node<int> * child2 = new Node<int>;
    Node<int> * grandchild11 = new Node<int>;
    Node<int> * grandchild12 = new Node<int>;

    /*

                                    root
                        child1               child2
            grandchild11 grandchild12
    */
    /*

                    1
                2       3
            4       5

            IN: 4 2 5 1 3
            PRE: 1 2 4 5 3
            POST: 4 5 2 3 1
    */


    root->data = 1;
    root->left = child1;
    root->right = child2;

    child1->data = 2;
    child1->left = grandchild11;
    child1->right = grandchild12;

    child2->data = 3;
    child2->left = nullptr;
    child2->right = nullptr;

    grandchild11->data = 4;
    grandchild11->left = nullptr;
    grandchild11->right = nullptr;

    grandchild12->data = 5;
    grandchild12->left = nullptr;
    grandchild12->right = nullptr;

    inordermorris(root);
    preordermorris(root);
    postordermorris(root);
    return 0;
}
