#include "map.h"
#include <stack>
#include "iostream"
#include <exception>
// #include bstnode.h

namespace cop3530
{
    template<typename K, typename V>
    struct Node
    {
        K key;
        V value;
        Node * left;
        Node * right;
    }; //Node struct

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

    private:
        Node <K, V> root;
    };
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    bstleaf<K,V,C,E>::bstleaf(void)
    {
        root.key = NULL;
        root.value = NULL;
        root.left = nullptr;
        root.right = nullptr;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstleaf<K,V,C,E>::insert( K key, V value )
    {
        insert_leaf(key, value);
    }

    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstleaf<K,V,C,E>::insert_leaf( K key, V value )
    {
        Node <K,V> new_node;
        new_node.key = key;
        new_node.value = value;
        new_node.left = nullptr;
        new_node.right = nullptr;

        //base case, nothing in the tree
        if(root.left == nullptr && root.right == nullptr){
//            std::cout << "is this what happens?\n";
            root = new_node;
            return;

        }

        Node <K,V> itr = root;

        while(itr.left || itr.right) //while there exists a tree
        {
            //overwrite the existing key if you it already exists
            if(E(key, itr.key)) itr.value = value; return;

            if(C(key, itr.key)) //if the key is less than the root's key
            {
                if(C(key, itr.left->key)) itr = *itr.left; //traverse left
                else
                {
                    itr.left = &new_node;
                    return;
                }
            }
            else //if the key is greater than the root's key
            {
                if(C(key, itr.right->key)) itr = *itr.right; //traverse right
                else
                {
                    itr.right = &new_node;
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
        V value;
        if (E(key, root.key)){ return root.value; }

        Node <K,V> itr = root;
        while(itr.left || itr.right)
        {
            if(C(key, itr.key))
            { //key is less than the itr, traverse left
                itr = *itr.left;
            }
            else
            {
                itr = *itr.right;
            }
        }
        if(E(key, itr.key))
            value = itr.value;
        else
            throw std::runtime_error("the key could not be found");


        return value;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    void bstleaf<K,V,C,E>::print()
    {
        std::stack<Node<K,V> > stack;
        Node <K,V> curr = root;
        bool done = false;

        while(!done)
        {

            if(curr.left != nullptr || curr.right != nullptr)
            {
                stack.push(curr);
                curr = *curr.left;
            }
            else
            {
                if(stack.empty())
                    done = true;
                else
                {
                    curr = stack.top();
                    stack.pop();
                    std::cout << "[ " << curr.key << " : " << curr.value << " ]\n";
                    curr = *curr.right;
                }
            }

        }
        std::cout << "popping/printing successful\n";

        return;
    }
    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    bool bstleaf<K,V,C,E>::is_empty()
    {
        return (!(root.left || root.right));
    }
}
