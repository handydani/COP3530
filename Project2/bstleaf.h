#include "Map.h"
#include <stack>
// #include bstnode.h

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
            struct Node {  K key; V value; Node * left; Node * right; }; //Node struct
            void insert( K key, V value ) override;// — adds the specified key-value pair to the map.
            void remove( K key ) override;// — removes the specified key-value pair associated with the key.
            V lookup( K key ) override;

            void print() override;
            bool is_empty() override;
            void insert_leaf( K key, V value );

        private:
            Node * root;
    };
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    bstleaf<K,V,C,E>::bstleaf(void)
    {
        root->key = NULL;
        root->value = NULL;
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
        Node * new_node = new Node{ key, value, nullptr, nullptr };

        //base case, nothing in the tree
        if(is_empty()){ root = new_node; return; }

        Node * itr = root;

        while(!is_empty()) //while there exists a tree
        {
            //overwrite the existing key if you it already exists
            if(E(key, itr->key)){ itr->value = value; return; }

            if(C(key, itr->key)) //if the key is less than the root's key
            {
                if(C(key, itr->left->key)) itr = itr->left; //traverse left
                else
                {
                    itr->left = new_node;
                    return;
                }
            }
            else //if the key is greater than the root's key
            {
                if(C(key, itr->right->key)) itr = itr->right; //traverse right
                else
                {
                    itr->right = new_node;
                    return;
                }
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
        // if (E(key, root->key)){ return root->value; }

        Node * itr = root;
        while(!is_empty())
        {
            if(E(key, itr->key)){ return itr->value; }
            if(C(key, itr->key)){ //key is less than the itr, traverse left
                itr = itr->left;
            }
            else{
                itr = itr->right;
            }
        }
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstleaf<K,V,C,E>::print()
    {
        std::stack<Node> stack;

        stack.push(root);

        while(!stack.empty())
        {
            Node * curr = stack.pop();
            if(curr)
            {
                std::cout << "[ " << curr->key <<" : " << curr->value << " ]\n";
                stack.push(curr->left);
                stack.push(curr->right);
            }
        }
        return;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    bool bstleaf<K,V,C,E>::is_empty()
    {
        return ((bool)!root);
    }
}
