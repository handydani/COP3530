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
        Node <K,V> * remove_recurse( Node <K,V> * root, K key );

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
        remove_recurse(root, key);
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    Node <K,V> * bstleaf<K,V,C,E>::remove_recurse( Node <K,V> * root, K key )
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
    V bstleaf<K,V,C,E>::lookup( K key )
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
