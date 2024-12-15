#include <vector>

using namespace std;

template<typename T>
class PriorityQueue {
private:
    vector<T> heap;
    bool isMinHeap;

    bool (*comparator)(T, T); // Returns true if the first argument should be before the second

    int parent(int index) {
        return (index - 1) / 2;
    }

    int left(int index) {
        return 2 * index + 1;
    }

    int right(int index) {
        return 2 * index + 2;
    }

    void heapify(int index) {
        int left = this->left(index);
        int right = this->right(index);
        int prioritized = index;

        if (left < heap.size() && isPrioritized(left, prioritized)) {
            prioritized = left;
        }

        if (right < heap.size() && isPrioritized(right, prioritized)) {
            prioritized = right;
        }

        if (prioritized != index) {
            swap(heap[index], heap[prioritized]);
            heapify(prioritized);
        }
    }

    bool isPrioritized(int index1, int index2) {
        if (isMinHeap) {
            return !comparator(heap[index1], heap[index2]);
        }
        return comparator(heap[index1], heap[index2]);
    }

public:

    PriorityQueue(bool (*comparator)(T, T), bool isMinHeap) {
        this->comparator = comparator;
        this->isMinHeap = isMinHeap;
    }

    PriorityQueue(bool (*comparator)(T, T), vector<T> values, bool isMinHeap) {
        this->comparator = comparator;
        this->isMinHeap = isMinHeap;
        for (T value: values) {
            push(value);
        }
    }

    void push(T value) {
        heap.push_back(value);
        int index = heap.size() - 1;

        while (index > 0 && isPrioritized(index, this->parent(index))) {
            swap(heap[index], heap[this->parent(index)]);
            index = this->parent(index);
        }
    }

    T pop() {
        T value = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return value;
    }

    T top() {
        return heap[0];
    }

    int size() {
        return heap.size();
    }

    bool empty() {
        return heap.empty();
    }
};
