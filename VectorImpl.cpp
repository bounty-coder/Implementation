#include <iostream>
#include <algorithm> // For std::copy

using namespace std;

template <typename T>
class Vector {
    int capacity;
    int size;
    T* data; // Corrected type of data
public:
    Vector() : data(nullptr), capacity(0), size(0) {}

    Vector(int initialCapacity) : capacity(initialCapacity), size(0) {
        data = new T[capacity];
    }

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& element) {
        if (size >= capacity) {
            int newCapacity = capacity * 2;
            if (newCapacity == 0) {
                newCapacity = 1;
            }
            T* newData = new T[newCapacity];
            std::copy(data, data + size, newData);
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size++] = element;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    void resize(int newSize) {
        if (newSize > capacity) {
            int newCapacity = max(capacity * 2, newSize);
            T* newData = new T[newCapacity];
            std::copy(data, data + size, newData);
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        size = newSize;
    }

    int getSize() const { // Renamed to avoid conflict with member variable
        return size;
    }

};

int main() {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    cout << "Size: " << vec.getSize() << endl; // Use getSize() function
    
    vec.resize(2);

    cout << "Size after resize: " << vec.getSize() << endl;
    
    vec.pop_back();

    cout << "Size after pop_back: " << vec.getSize() << endl;

    return 0;
}
