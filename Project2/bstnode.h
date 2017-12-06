template <typename K, typename V, typename C, typename E>
class Node
{
    public:
        Node(void);
        Node <K,V,C,E> * left;
        Node <K,V,C,E> * left;
        K key;
        V value;
        C compare;
        E equal;
};
template <typename T>
Node<T>::Node(void){
    K key = 0;
    V value = 0;
    C compare = 0;
    E equal = 0;
}
}
