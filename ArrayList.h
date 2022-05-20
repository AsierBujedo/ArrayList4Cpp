#pragma once
template <class T> class ArrayList {

public:
    ArrayList();
    ~ArrayList();
    T get(int index);
    int indexOf(T &d);
    void add(T &d);
    void add(T &d, int position );
    bool remove(int index);
    bool contains(T &d);
    void clear( );
    bool isEmpty( );
    inline int listSize() { return size; }

private:

    int arraySize;
    int size;
    T *data = nullptr;
    bool needsExpansion();
    void expandArray();
    bool isValidIndex(int index);
};
