#include "Map.h"
#include "bin_node.h"
#include <stack>
#include "iostream"
#include <exception>

namespace cop3530
{
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    class bstleaf : public Map<K,V,C,E>
    {
    public:

        bstleaf(void);
        ~bstleaf();
        // SSLL(const SSLL&); //copy contructor
        // SSLL& operator =(const SSLL&); //copy assignment operator
        //move constructor
        //move assignment operator
        // ~ SSLL (); //destructor

        void insert( K key, V value ) override;// — adds the specified key-value pair to the map.
        void remove( K key ) override;// — removes the specified key-value pair associated with the key.
        V lookup( K key ) override;

        void print() override;
        bool is_empty() override;

        void insert_leaf( K key, V value );
        void in_order(Node<K,V> * curr);

    private:
        Node <K, V> * root;
    };
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    bstleaf<K,V,C,E>::bstleaf(void)
    {
        root->key = 0;
        root->value = 0;
        root->left = nullptr;
        root->right = nullptr;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    bstleaf<K,V,C,E>::~bstleaf(void)
    {
        //in order deletion
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstleaf<K,V,C,E>::insert( K key, V value )
    {
        insert_leaf(key, value);
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstleaf<K,V,C,E>::insert_leaf( K key, V value )
    {
        Node <K,V> * new_node = new Node<K,V>;

        new_node->key = key;
        new_node->value = value;
        new_node->left = nullptr;
        new_node->right = nullptr;

        //base case, nothing in the tree
        if(!(root->key || root->value)){
            root = new_node;
            return;
        }

        Node <K,V> * itr = root;
        while(itr) //while there exists a tree
        {
            //overwrite the existing key if you it already exists
            if(E(key, itr->key))
            {
                itr->value = value;
                return;
            }
            if(C(key, itr->key)) //if the key is less than the root's key
            {
                if(itr->left !=  nullptr)
                    itr = itr->left;
                else
                    itr->left = new_node;
            }
            else //if the key is greater than the root's key
            {
                if(itr->right != nullptr)
                    itr = itr->right;
                else
                    itr->right = new_node;
            }
        }
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstleaf<K,V,C,E>::remove( K key )
    {
        if(E(key, root->key) && (!(root->left || root->right)))
            free(root);
        else{
            remove_recurse(root, key);
        }

        // if(E(key, root->key)){
        //     root->left = nullptr;
        //     root->right = nullptr
        //     root->key = 0;
        //     root->value = 0;
        //     return;
        // }
        //
        // Node <K,V,C,E> * child = root;
        // Node <K,V,C,E> * parent = root;
        //
        // while(child)
        // {
        //     parent = child
        //     if(C(key,child->key)){
        //         child = child->left;
        //     }
        //     else{
        //         child = child->right;
        //     }
        // }
        //
        // if(E(key, child->key)){
        //
        //     if(parent->left->key == key)
        //     {
        //         parent->left = //max of child's left subtree;
        //         if(child->left){
        //             //find max
        //         }
        //         else if(child->right){
        //             //find min
        //         }
        //     }
        //     if(parent->right->key == key)
        //     {
        //         parent->right =
        //     }
        //     child->key = 0;
        //     child->value = 0;
        //
        // }

    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    Node <K,V> * bstleaf<K,V,C,E>::remove_recurse( Node <K,V> * root, K key )
    {
        if(root == NULL) return root;

        if(C(key, root->key)) {
            root->left = remove_recurse(root->left, key);
        }
        else if (!C(key, root->key)){
            root->right = remove_recurse(root->right, key);
        }
        else{
            if(root->left == nullptr){
                Node <K,V,C,E> * temp = root->left;
                free(root);
                return temp;
            }
            else if(root->right == nullptr){
                Node <K,V,C,E> * temp = root->right;
                free(root);
                return temp;
            }
        //     _                 _                         _
        //    | |__   ___   ___ | | ___ __ ___   __ _ _ __| | __
        //    | '_ \ / _ \ / _ \| |/ / '_ ` _ \ / _` | '__| |/ /
        //    | |_) | (_) | (_) |   <| | | | | | (_| | |  |   <
        //    |_.__/ \___/ \___/|_|\_\_| |_| |_|\__,_|_|  |_|\_\


            Node <K,V,C,E> * temp = minNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }

        return root;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    V bstleaf<K,V,C,E>::lookup( K key )
    {
        V value = '';
        // if (E(key, root->key))
        // {
        //     return root->value;
        // }

        // Node <K,V> * itr = root;
        // while(itr->left || itr->right)
        // {
        //     if(C(key, itr->key))
        //     { //key is less than the itr, traverse left
        //         itr = itr->left;
        //     }
        //     else
        //     {
        //         itr = itr->right;
        //     }
        // }
        // if(E(key, itr->key))
        //     return &itr->value;
        // else
        //     throw std::runtime_error("the key could not be found");

        return value;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstleaf<K,V,C,E>::print()
    {
        if(root == nullptr) throw std::runtime_error("tried to print something that doesn't exist");
        else in_order(root);
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstleaf<K,V,C,E>::in_order(Node<K,V> * curr)
    {
        if(curr == nullptr)
            return;

        in_order(curr->left);
        std::cout << "[ " << curr->key << " : " << curr->value << " ]\n";
        in_order(curr->right);

    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    bool bstleaf<K,V,C,E>::is_empty()
    {
        return (!root);
    }
}
