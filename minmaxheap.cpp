#include <iostream>
#include <array>
#include <cassert>

using namespace std;


class MaxHeap {
  private:
  int maxSize; // total capacity
  int size;    // current size     
  int *heap;

  public:
  MaxHeap(int arr[], int size) : heap {arr}, size {size}, maxSize {size} {
      HeapifyMax();
      cout << "MaxHeap Initialised with " << size << " elements." << endl;
  }

  int leftChild(int i)
  {
      return (2 * i) + 1;
  }
  int rightChild(int i)
  {
      return (2 * i) + 2;
  }
  int parent(int i)
  {
      assert(i > 0);
      return (i - 1) / 2;
  }

  void HeapifyMax()
  {
      if (size < 2) {
          return;
      }
      // Start from second last level
      // sift down
      int startIndex = parent(size - 1);
      for (int i = startIndex; i >= 0; i--) {
          siftDown(i);
      }
  }

  int popMax() {
      int res = heap[0];
      if (size > 0) {
        heap[0] = heap[size -1];
        size -= 1;
        siftDown(0);
      } 
      return res;
  }

  void siftDown(int i) {
      int maxIndex = i;

      int left = leftChild(i);
      if (left <= size - 1) {
          if (heap[left] > heap[maxIndex]) {
              maxIndex = left;
          }
      }

      int right = rightChild(i);
      if (right <= size - 1) {
          if (heap[right] > heap[maxIndex]) {
              maxIndex = right;
          }
      }

      if (maxIndex != i) {
          swap(heap[i], heap[maxIndex]);
          siftDown(maxIndex);
      }
  }

  void siftUp(int i) {
      int maxIndex = i;
      int parentIndex = parent(i);
      
      if (parentIndex >= 0) {
          if (heap[maxIndex] > heap[parentIndex]) {
              maxIndex = parentIndex;
          }
      }

      if (maxIndex != i) {
          swap(heap[i], heap[maxIndex]);
          siftUp(maxIndex);
      }
  }

};


int main() {
    int arr[] = {45,12,123,34,40,1};
    int size = sizeof(arr) / sizeof(int);

    MaxHeap mheap(arr,size);
    assert(mheap.popMax() == 123);
    assert(mheap.popMax() == 45);
    assert(mheap.popMax() == 40);
    assert(mheap.popMax() == 34);
    assert(mheap.popMax() == 12);
    assert(mheap.popMax() == 1);

    return 0;
}