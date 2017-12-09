#include "Map.h"
#include "bin_node.h"
#include <stack>
#include "iostream"
#include <exception>
#include <stdlib.h>

namespace cop3530
{
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    class bstrand : public Map<K,V,C,E>
    {
    public:

        bstrand(void);
        ~bstrand();
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
        void insert_rand( K key, V value );
        void insert_root( Node<K,V> * node, K key, V value );


        void in_order(Node<K,V> * curr);
        Node <K,V> * remove_recurse( Node <K,V> * root, K key );
        int n_counter(Node<K,V> * curr, int count);
        Node <K,V> * rotate_left( Node <K,V> * node );
        Node <K,V> * rotate_right( Node <K,V> * node );

    private:
        Node <K, V> * root;
    };
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    bstrand<K,V,C,E>::bstrand(void)
    {
        root->key = 0;
        root->value = 0;
        root->left = nullptr;
        root->right = nullptr;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    bstrand<K,V,C,E>::~bstrand(void)
    {
        //in order deletion
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstrand<K,V,C,E>::insert( K key, V value )
    {
        //generate random number 0 to n

        int rand_int = rand() % (n_counter(root, 0) + 1);
        if(rand_int){
            insert_leaf(key, value);
        }
        else{
            insert_root(root, key, value);
        }

    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstrand<K,V,C,E>::insert_root( Node<K,V> * node, K key, V value )
    {
        if(!(node->left || node->right)){
            node->key = key;
            node->value = value;
            return;
        }
        if(C(key, node->key)){
            insert_root(node->left, key, value);
            rotate_right(node);
        }
        else{
            insert_root(node->right, key, value);
            rotate_left(node);
        }
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    Node <K,V> * bstrand<K,V,C,E>::rotate_left( Node <K,V> * node )
    {
        Node<K,V> * temp = node->left;
        node->left = temp->right;
        temp->right = node;
        return temp;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    Node <K,V> * bstrand<K,V,C,E>::rotate_right( Node <K,V> * node )
    {
        Node<K,V> * temp = node->right;
        node->right = temp->left;
        temp->left = node;
        return temp;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstrand<K,V,C,E>::insert_leaf( K key, V value )
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
    void bstrand<K,V,C,E>::remove( K key )
    {
        remove_recurse(root, key);
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    Node <K,V> * bstrand<K,V,C,E>::remove_recurse( Node <K,V> * root, K key )
    {
        if(root == NULL) return root;

        if(C(key, root->key)) {
            root->left = remove_recurse(root->left, key);
        }
        else if (C(root->key, key)){
            root->right = remove_recurse(root->right, key);
        }
        else{
            // std::cout << "flag\n";
            if(root->left == nullptr){
                Node <K,V> * temp = root->left;
                free(root);
                return temp;
            }
            else if(root->right == nullptr){
                Node <K,V> * temp = root->right;
                free(root);
                return temp;
            }

            Node <K,V> * temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;

            root->key = temp->key;
            root->value = temp->value;
            root->right = remove_recurse(root->right, temp->key);
        }

        return root;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    V bstrand<K,V,C,E>::lookup( K key )
    {
        if (E(key, root->key))
        {
            return root->value;
        }
        Node <K,V> * itr = root;
        while(itr->left || itr->right)
        {
            if(E(key, itr->key))
                return itr->value;
            if(C(key, itr->key))
            { //key is less than the itr, traverse left
                itr = itr->left;
            }
            else
            {
                itr = itr->right;
            }
        }
        if(E(key, itr->key))
            return itr->value;
        else
            throw std::runtime_error("the key could not be found");

    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstrand<K,V,C,E>::print()
    {
        if(root == nullptr) throw std::runtime_error("tried to print something that doesn't exist");
        else in_order(root);
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstrand<K,V,C,E>::in_order(Node<K,V> * curr)
    {
        if(curr == nullptr)
            return;

        in_order(curr->left);
        std::cout << "[ " << curr->key << " : " << curr->value << " ]\n";
        in_order(curr->right);
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    int bstrand<K,V,C,E>::n_counter(Node<K,V> * curr, int count)
    {
        //TODO TEST
        if(!(curr->left || curr->right))
            return 0;

        in_order(curr->left);
        count++;
        in_order(curr->right);
        return count;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    bool bstrand<K,V,C,E>::is_empty()
    {
        return (!root);
    }
}
