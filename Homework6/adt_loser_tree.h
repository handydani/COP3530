template <typename T>
class adt_loser_tree
{

    public:
        virtual ~adt_loser_tree() {};
        virtual bool compare(T data1, T data2) = 0;
        virtual T get_winner() = 0;
        virtual void remove_winner() = 0;
        virtual void replace(size_t index) = 0;
        virtual void sort() = 0;
        virtual void kwaymerge() = 0;
};

template <typename T>
class loser_tree : public adt_loser_tree<T>{

    public:
        loser_tree(T data);
        ~ loser_tree ();
        bool compare(T data1, T data2);
        bool compare(T data1, T data2);
        T get_winner();
        void remove_winner();
        void replace(size_t index);
        void sort();
        void kwaymerge();
};
