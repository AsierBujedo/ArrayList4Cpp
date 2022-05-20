#include "ArrayList.h"
#include <iostream>

using namespace std;

template<class T>
ArrayList<T>::ArrayList() {
    arraySize = 2;
    size = 0;
    data = new T[arraySize];
}

template <class T> ArrayList<T> :: ~ArrayList() {
    delete []data;
};

template <class T> T ArrayList<T> :: get(int index) {
    if (!isValidIndex(index)) return 0;
    return data[index];
}

template <class T> int ArrayList<T> :: indexOf(T &d) {
    for (int i = 0; i < size; i++) {
        if (data[i] == *d) return i;
    }
    return -1;
}

template <class T> void ArrayList<T> :: add(T &d) {
    if (needsExpansion()) expandArray();
    data[size++] = d;
}

template <class T> void ArrayList<T> :: add(T &d, int index) {
    if (needsExpansion()) expandArray();

    if (!(index >= 0 && index <= size)) return;

    for (int i = size() - 1; i >= 0; i--) {
        if (i >= index) {
            data[i + 1] = data[i];
        }
    }
    data[index] = d;
    size++;
}

template <class T> bool ArrayList<T> :: remove(int index) {
    if (!isValidIndex(index)) return false;

    for (int i = index + 1; i < size(); i++) {
        data[i - 1] = data[i];
    }

    data[size--] = nullptr;
    return true;
}

template <class T> bool ArrayList<T> ::contains(T &d) {
    return indexOf(d) >= 0;
}

template <class T> void ArrayList<T> :: clear() {
    size = 0;
    arraySize = 2;
    delete []data;
    *data = new T[arraySize];
}

template <class T> bool ArrayList<T> :: isEmpty() {
    return size == 0;
}

template<class T> bool ArrayList<T> :: needsExpansion() {
    return size >= arraySize;
}

template<class T> void ArrayList<T> :: expandArray() {
    arraySize *= 2;
    T *newData = new T[arraySize];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete []data;
    data = newData;
}

template<class T>
bool ArrayList<T>::isValidIndex(int index) {
    return index >= 0 && index < size;
}
