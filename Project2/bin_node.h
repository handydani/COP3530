
namespace cop3530 {
template <typename K, typename V>
class Node
{
    public:
        Node(void);
        Node <K,V> * left;
        Node <K,V> * right;
        K key;
        V value;
};
template <typename K, typename V>
Node<K,V>::Node(void){
    key = 0;
    value = 0;
    left = nullptr;
    right = nullptr;
}
}
