#ifndef node_cdal_h
#define node_cdal_h

template <typename T>
class Node_CDAL
{
    public:
        Node_CDAL(void);
        Node_CDAL <T> * next;
        T * data;
};
template <typename T>
Node_CDAL<T>::Node_CDAL(void){
    next = 0;
    T * array = new T[50];
    for(int i = 0; i < 50; ++i)
        array[i] = 0;
    data = &array[0];
}
#endif
