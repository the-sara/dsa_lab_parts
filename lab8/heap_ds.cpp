#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>  // For exception handling
using namespace std;

// Define the template class
template <typename elem>
class heap_class {
public:
    int capacity;
    pair<int, elem>* arr;
    int size;

    // Constructor and Destructor
    heap_class(pair<int, elem> array[], int mysize, int cap);
    ~heap_class();

    // Member functions
    int peak();
    void insert(pair<int,elem> p);
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int parent(int i) { return (i - 1) / 2; }
    void print();
    void heapify(int i);
    void heap_heapify();
    pair<int,elem> deletting();
};

// Constructor and Destructor
template <typename elem>
heap_class<elem>::heap_class(pair<int, elem> array[], int mysize, int cap) {
    capacity = cap;
    size = mysize;
    arr = array; // No need to allocate memory here if array is passed externally
}

template <typename elem>
heap_class<elem>::~heap_class() {
    // No need to delete arr here if it was passed from outside
    // If you were dynamically allocating arr, you would delete[] here
}

// Peak method
template <typename elem>
int heap_class<elem>::peak() {
    return arr[0].first;  // The smallest element is at the root in a min-heap
}

// Insert method
template <typename elem>
void heap_class<elem>::insert(int k, elem data) {
    if (size == capacity) {
        throw std::overflow_error("Heap is full");  // More standard exception handling
    } else {
        arr[size] = make_pair(k, data);
        int i = size;
        size++;

        // Heapify up (adjust to maintain heap property for min-heap)
        while (i > 0 && arr[i].first < arr[parent(i)].first) {  // Change comparison for min-heap
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
}

// Print method
template <typename elem>
void heap_class<elem>::print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i].first << " ";
    }
    cout << endl;
}

// Heapify method (swap entire pair, not just the 'first' part)
template <typename elem>
void heap_class<elem>::heapify(int i) {
    int l = left(i);
    int r = right(i);
    int min = i;

    // Adjust comparisons for min-heap
    if (l < size && arr[l].first < arr[min].first) {  // Find the smallest child
        min = l;
    }

    if (r < size && arr[r].first < arr[min].first) {  // Find the smallest child
        min = r;
    }

    if (min != i) {
        swap(arr[i], arr[min]);  // Swap the entire pair to maintain min-heap
        heapify(min);  // Recursively heapify the affected subtree
    }
}

// Heapify the entire heap
template <typename elem>
void heap_class<elem>::heap_heapify() {
    // Start from the last parent node and heapify down to root
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(i);  // Ensure the min-heap property is maintained for the entire heap
    }
}

// Deleting the root and reheapifying
template <typename elem>
pair<int,elem> heap_class<elem>::deletting() {
    if (size > 0) {
        pair<int,elem> ret= arr[0]
        arr[0] = arr[size - 1];  // Replace root with the last element
        size--;  // Decrease size
        heapify(0);  // Heapify the root to restore min-heap property
    }
    return ret;
}

/*int main() {
    // Example usage (you can test with actual values here):
    pair<int, int> arr[] = {{10, 1}, {20, 2}, {5, 3}, {30, 4}};
    heap_class<int> h(arr, 4, 10);
    h.print();  // Should print: 5 10 20 30 (min-heap)
    h.insert(2, 5);
    h.print();  // Should print: 2 5 20 30 10 (min-heap)
    h.deletting();
    h.print();  // Should print: 5 10 20 30 (min-heap)
}*/

