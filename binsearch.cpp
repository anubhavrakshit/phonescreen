// Binary Search an integer in a sorted array
// Return index of key or -1 for failure

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// O(logN) | O(1)
int binsearch(vector<int> arr, int key) {
    int index = -1;
    int left = 0, right = arr.size() - 1, mid;

    if (arr.empty()) {
        return index;
    }

    while (left <= right) {
        mid = (left + right) / 2;
        int guess = arr[mid];
        
        if (guess == key) {
            index = mid;
            break;
        }

        if (guess < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return index;
}


int main ()
{
    assert(binsearch({1,2,3,4,5}, 4) == 3);
    assert(binsearch({1,2,3,4,5}, 1) == 0);
    assert(binsearch({1,2,3,4,5}, 9) == -1);
    assert(binsearch({}, 9) == -1);
    assert(binsearch({71,112,333,4677777,58888888}, 58888888) == 4);

    return 0;
}