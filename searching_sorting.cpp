#include <iostream>
using namespace std;

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int linearSearch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int array[], int size, int target) {
    int leftIndex = 0;
    int rightIndex = size - 1;
    
    while (leftIndex <= rightIndex) {
        int middleIndex = (leftIndex + rightIndex) / 2;
        
        if (array[middleIndex] == target) {
            return middleIndex;
        }
        
        if (target < array[middleIndex]) {
            rightIndex = middleIndex - 1;
        }
        else {
            leftIndex = middleIndex + 1;
        }
    }
    return -1;
}

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minimumIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minimumIndex]) {
                minimumIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[minimumIndex];
        array[minimumIndex] = temp;
    }
}

void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int currentValue = array[i];
        int j = i - 1;
        
        while (j >= 0 && array[j] > currentValue) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = currentValue;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    cout << "Original array: ";
    printArray(arr, n);
    
    int searchKey = 25;
    int pos = linearSearch(arr, n, searchKey);
    if (pos != -1) {
        cout << "Found " << searchKey << " at position " << pos << endl;
    }
    else {
        cout << searchKey << " not found" << endl;
    }
    
    bubbleSort(arr, n);
    cout << "After bubble sort: ";
    printArray(arr, n);
    
    int sortedArr[] = {11, 12, 22, 25, 34, 64, 90};
    pos = binarySearch(sortedArr, 7, searchKey);
    if (pos != -1) {
        cout << "Binary search found " << searchKey << " at position " << pos << endl;
    }
    
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr2, 7);
    cout << "After selection sort: ";
    printArray(arr2, 7);
    
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr3, 7);
    cout << "After insertion sort: ";
    printArray(arr3, 7);
    
    return 0;
}
