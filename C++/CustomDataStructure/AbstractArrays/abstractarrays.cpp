#include <fstream>
#include <iostream>

class AbstractArray {
public:
    int total_size;
    int array_size;
    int* pointer = NULL; // A pointer that points to the starting element of array stored in heap.

    AbstractArray(int tsize, int asize)
    {
        total_size = tsize;
        array_size = asize;

        pointer = new int[total_size];
    }

    void show()
    {
        for (int i = 0; i < array_size; i++) {
            std::cout << pointer[i] << std::endl;
        }
    }

    void set_array(...)
    {
        // Create a variable list in C++
        va_list valist;
        va_start(valist, array_size); // Insert values in variable list.

        for (int i = 0; i < array_size; i++) {
            pointer[i] = va_arg(valist, int);
        }
        // Clear the memory for variable list.
        va_end(valist);
    }

    void proper_insertion(int value, int index)
    { // O(n)
        for (int i = index; i < array_size + 1; i++) {
            pointer[i + 1] = pointer[i];
        }
        pointer[index] = value;
        array_size++;
    }

    void insertion(int value)
    { // O(1)
        pointer[array_size] = value;
        array_size++;
    }

    void deletion(int index)
    { // O(n)
        for (int i = index; i < array_size; i++) {
            pointer[i] = pointer[i + 1];
        }
        array_size--;
    }

    int linear_search(int value)
    { // O(n)
        for (int i = 0; i < array_size; i++) {
            if (pointer[i] == value) {
                return i;
            }
        }
    }

    int binary_search(int value)
    { // O(nlogn) + O(logn) = O(nlogn) -- For unsorted
        int start = 0;
        int end = array_size - 1;

        if (pointer[start] == value) {
            return start;
        } else if (pointer[end] == value) {
            return end;
        } else {
            while (start <= end) {
                int mid = (start + end) / 2;

                if (pointer[mid] == value) {
                    return mid;
                }
                if (pointer[mid] > value) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }

        return -1;
    }
};

int main()
{

    AbstractArray marks(100, 2);
    marks.set_array(1, 2);
    marks.show();

    marks.proper_insertion(5, 1);
    marks.show();

    marks.insertion(8);
    marks.show();

    // Currently the array is - [1,5,2,8]
    marks.deletion(1);
    std::cout << "Array after deletion" << std::endl;
    marks.show();

    // Currently the array is - [1,2,8];
    std::cout << "Index of element 8 is " << marks.linear_search(8) << std::endl;

    AbstractArray nums(100, 6);
    nums.set_array(5, 10, 67, 333, 1000, 2000);

    nums.show();

    std::cout << "Value is at :" << nums.binary_search(67) << std::endl;

    return 0;
}