#ifndef node_h
#define node_h
namespace cop3530 {
template <typename T>
class Node
{
    public:
        Node(void);
        Node <T> * next;
        T data;
};
template <typename T>
Node<T>::Node(void){
    next = 0;
    data = 0;
}
}
#endif
