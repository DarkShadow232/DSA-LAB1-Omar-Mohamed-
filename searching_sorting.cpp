#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] == key) {
            return mid;
        }
        
        if (key < arr[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minPos]) {
                minPos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
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
