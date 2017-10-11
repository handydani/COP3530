#ifndef node_cdal_h
#define node_cdal_h

template <typename T>
class Node
{
    public:
        Node();
        Node <T> * next;
        T * data;
};
template <typename T>
Node<T>::Node(){
    next = 0;
    T array[50];
    data = array;
}
#endif
