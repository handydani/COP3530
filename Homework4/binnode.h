#ifndef binnode_h
#define binnode_h
template <typename T>
class Node
{
    public:
        Node();
        Node <T> * left;
        Node <T> * right;

        T data;
};
template <typename T>
Node<T>::Node(){
    left = 0;
    right = 0;
    data = 0;
}
#endif
