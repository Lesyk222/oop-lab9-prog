#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class CMultiSet {
private:
    int size;
    T* values;

public:
    CMultiSet()
        : values(nullptr), size(0) { }

    CMultiSet(int capacity)
        : values(nullptr) {
        this->size = capacity;
        values = new T[size];
        if (!values) {
            throw bad_alloc();
        }
    }

    CMultiSet(const CMultiSet& other) {
        size = other.size;
        values = new T[size];
        if (!values) {
            throw bad_alloc();
        }
        for (int i = 0; i < size; i++) {
            values[i] = other.values[i];
        }
    }

    CMultiSet(CMultiSet&& other) noexcept {
        size = other.size;
        values = other.values;
        other.size = 0;
        other.values = nullptr;
    }

    ~CMultiSet() {
        delete[] values;
    }

    T getElement(int index) const noexcept {
        return values[index];
    }

    int countOfCertainElement(const T& value) const noexcept {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (values[i] == value)
                count++;
        }
        return count;
    }

    int cardinality() const noexcept {
        return size;
    }

    T findMax() const {
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

    T findMin() const {
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

    void addElement(const T& temp) {
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

    void deleteElement(const T& temp) {
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

    void readArray() {
        int count;
         cout << "Enter count: ";
        if (!( cin >> count)) {
            throw runtime_error("Bad input");
        }
        for (int i = 0; i < count; i++) {
            T value;
             cout << "Enter value " << i + 1 << ": ";
            if (!( cin >> value)) {
                throw runtime_error("Bad input");
            }
            addElement(value);
        }
    }

    CMultiSet<T> operator+(const CMultiSet<T>& other) const noexcept {
        CMultiSet<T> multiSet(0);
        for (int i = 0; i < size; i++) {
            multiSet.addElement(values[i]);
        }
        for (int i = 0; i < other.cardinality(); i++) {
            multiSet.addElement(other.values[i]);
        }
        return multiSet;
    }

    CMultiSet<T> operator-(const CMultiSet<T>& other) const noexcept {
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



    CMultiSet<T> operator/(const CMultiSet<T>& other) const noexcept {
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

    CMultiSet<T>& operator=(const CMultiSet<T>& other) {
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

    CMultiSet<T>& operator=(CMultiSet<T>&& other) noexcept {
        size = other.size;
        values = other.values;
        other.size = 0;
        other.values = nullptr;
        return *this;
    }

    friend  istream& operator>>( istream& input, CMultiSet<T>& other) noexcept {
        other.readArray();
        return input;
    }

    friend  ostream& operator<<( ostream& output, const CMultiSet<T>& other) {
        if (other.size == 0) {
            throw runtime_error("Empty multiset");
        }
        for (int i = 0; i < other.size; i++) {
            output << other.values[i] << " ";
        }
        output <<  endl;
        return output;
    }
};