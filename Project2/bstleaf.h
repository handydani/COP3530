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

    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    V bstleaf<K,V,C,E>::lookup( K key )
    {
        V value;
        if (E(key, root->key)){ return root->value; }

        Node <K,V> * itr = root;
        while(itr->left || itr->right)
        {
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
            value = itr->value;
        else
            throw std::runtime_error("the key could not be found");

        if(C(key, itr->key))
        { //key is less than the itr, traverse left
            itr = itr->left;
        }

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
