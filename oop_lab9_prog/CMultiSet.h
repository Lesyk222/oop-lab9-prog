#pragma once    
//#include "CFixedPointNumber.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class CMultiSet {
private:
    int size;
    T* values;

public:
    CMultiSet();
    CMultiSet(int capacity);
    CMultiSet(const CMultiSet& other);
    CMultiSet(CMultiSet&& other) noexcept;
    ~CMultiSet();
    
    T getElement(int index) const noexcept;
    
    int countOfCertainElement(const T& value) const noexcept;
    
    int cardinality() const noexcept;
    T findMax() const;
    T findMin() const;

    void addElement(const T& temp);
    void deleteElement(const T& temp);
    
    void readArray();
    void printArray();

    CMultiSet<T> operator+(const CMultiSet<T>& other) const noexcept;
    CMultiSet<T> operator-(const CMultiSet<T>& other) const noexcept;
    CMultiSet<T> operator/(const CMultiSet<T>& other) const noexcept;
    CMultiSet<T>& operator=(const CMultiSet<T>& other);
    CMultiSet<T>& operator=(CMultiSet<T>&& other) noexcept;

    template <typename T>
    friend istream& operator>>(istream& input, CMultiSet<T>& other) noexcept;
    template <typename T>
    friend  ostream& operator<<(ostream& output, CMultiSet<T>& other) noexcept;
};

template<typename T>
CMultiSet<T>::CMultiSet()
    : values(nullptr), size(0) { }

template<typename T>
CMultiSet<T>::CMultiSet(int capacity)
    : values(nullptr) {
    this->size = capacity;
    values = new T[size];
    if (!values) {
        throw bad_alloc();
    }
    for (int i = 0; i < size; i++)
    {
        values[i] = T();
    }
}

template<typename T>
CMultiSet<T>::CMultiSet(const CMultiSet& other) {
    size = other.size;
    values = new T[size];
    if (!values) {
        throw bad_alloc();
    }
    for (int i = 0; i < size; i++) {
        values[i] = other.values[i];
    }
}

template<typename T>
CMultiSet<T>::CMultiSet(CMultiSet&& other) noexcept {
    size = other.size;
    values = other.values;
    other.size = 0;
    other.values = nullptr;
}

template<typename T>
CMultiSet<T>::~CMultiSet() {
    delete[] values;
}

template<typename T>
T CMultiSet<T>::getElement(int index) const noexcept {
    return values[index];
}

template<typename T>
int CMultiSet<T>::countOfCertainElement(const T& value) const noexcept {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (values[i] == value)
            count++;
    }
    return count;
}

template<typename T>
int CMultiSet<T>::cardinality() const noexcept {
    return size;
}

template<typename T>
T CMultiSet<T>::findMax() const {
    if (size == 0) {
        throw runtime_error("Empty multiset");
    }
    else {
        T max = values[0];
        for (int i = 0; i < size; i++) {
            if (values[i] > max) {
                max = values[i];
            }
        }
        return max;
    }
}

template<typename T>
T CMultiSet<T>::findMin() const {
    if (size == 0) {
        throw runtime_error("Empty multiset");
    }
    else {
        T min = values[0];
        for (int i = 0; i < size; i++) {
            if (values[i] < min) {
                min = values[i];
            }
        }
        return min;
    }
}

template<typename T>
void CMultiSet<T>::addElement(const T& temp) {
    size++;
    T* newValues = new T[size];
    if (!newValues) {
        throw bad_alloc();
    }
    for (int i = 0; i < size - 1; i++) {
        newValues[i] = values[i];
    }
    delete[] values;
    values = newValues;
    values[size - 1] = temp;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                T temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void CMultiSet<T>::deleteElement(const T& temp) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (values[i] == temp) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        throw runtime_error("Element not found");
    }

    size--;
    for (int i = index; i < size; i++) {
        values[i] = values[i + 1];
    }

    T* newValues = new T[size];
    if (!newValues) {
        throw  bad_alloc();
    }
    for (int i = 0; i < size; i++) {
        newValues[i] = values[i];
    }
    delete[] values;
    values = newValues;
}

template<typename T>
void CMultiSet<T>::readArray() {
    int count;
    cout << "Enter count: ";
    if (!(cin >> count)) {
        throw runtime_error("Bad input");
    }
    for (int i = 0; i < count; i++) {
        T value;
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        if (!value) {
            throw runtime_error("Bad input");
        }
        addElement(value);
    }
}

template<typename T>
CMultiSet<T> CMultiSet<T>::operator+(const CMultiSet<T>& other) const noexcept {
    CMultiSet<T> multiSet(0);
    for (int i = 0; i < size; i++) {
        multiSet.addElement(values[i]);
    }
    for (int i = 0; i < other.cardinality(); i++) {
        multiSet.addElement(other.values[i]);
    }
    return multiSet;
}

template<typename T>
CMultiSet<T> CMultiSet<T>::operator-(const CMultiSet<T>& other) const noexcept {
    CMultiSet<T> multiSet(0);
    for (int i = 0; i < size; i++) {
        T currentElement = values[i];
        bool isContains = false;
        for (int j = 0; j < other.size; j++) {
            if (currentElement == other.values[i]) {
                isContains = true;
                break;
            }
        }
        if (isContains) {
            multiSet.addElement(currentElement);
        }
    }
    return multiSet;
}


template<typename T>
CMultiSet<T> CMultiSet<T>::operator/(const CMultiSet<T>& other) const noexcept {
    CMultiSet<T> multiSet(0);
    for (int i = 0; i < size; i++) {
        T currentElement = values[i];
        bool isContains = false;
        for (int j = 0; j < other.size; j++) {
            if (currentElement == other.values[i]) {
                isContains = true;
                break;
            }
        }
        if (!isContains) {
            multiSet.addElement(currentElement);
        }
    }
    return multiSet;
}

template<typename T>
CMultiSet<T>& CMultiSet<T>::operator=(const CMultiSet<T>& other) {
    size = other.size;
    values = new T[size];
    if (!values) {
        throw bad_alloc();
    }
    for (int i = 0; i < size; i++) {
        values[i] = other.values[i];
    }
    return *this;
}

template<typename T>
CMultiSet<T>& CMultiSet<T>::operator=(CMultiSet<T>&& other) noexcept {
    size = other.size;
    values = other.values;
    other.size = 0;
    other.values = nullptr;
    return *this;
}

template<typename T>
void CMultiSet<T>::printArray() {
    for (int i = 0; i < size; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
}

template<typename T>
istream& operator>>(istream& input, CMultiSet<T>& other) noexcept {
    other.readArray();
    return input;
}

template<typename T>
ostream& operator<<(ostream& output, CMultiSet<T>& other) noexcept {
    if (other.size == 0) {
        throw runtime_error("Empty multiset");
    }
    other.printArray();
    return output;
}
