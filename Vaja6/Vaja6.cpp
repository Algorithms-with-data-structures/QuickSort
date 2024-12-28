// QUICK SORT

#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;

// Display menu options
void menu() {
    cout << endl;
    cout << "Quick Sort - Options:" << endl;
    cout << endl;
    cout << "1) Generate a random sequence" << endl;
    cout << "2) Generate an ascending sequence" << endl;
    cout << "3) Generate a descending sequence" << endl;
    cout << "4) Display the sequence" << endl;
    cout << "5) Check if the sequence is sorted" << endl;
    cout << "6) Quick Sort without median" << endl;
    cout << "7) Quick Sort with median" << endl;
    cout << "8) Selection Sort" << endl;
    cout << "9) Exit" << endl;
    cout << endl;
    cout << "Choice: ";
}

// Generate a given type sequence
void generateSequence(vector<int>& arr, unsigned int size, unsigned int& upperBound, string type) {
    arr.clear();

    if (type == "random") {
        for (int i = 0; i < size; i++) arr.push_back(rand() % size + 1);
    }
    else if (type == "ascending") {
        for (int i = 0; i < size; i++) arr.push_back(i + 1);
    }
    else if (type == "descending") {
        for (int i = size; i > 0; i--) arr.push_back(i);
    }

    upperBound = arr.size() - 1;
}

// Display the sequence
void print(const vector<int>& arr) {
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Check if the sequence is sorted
bool isSorted(const vector<int>& arr) {
    return is_sorted(arr.begin(), arr.end());
}

// Partition function for Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int left = low;
    int right = high;

    while (left < right) {
        while (arr[left] <= pivot && left < high) left++;
        while (arr[right] >= pivot && right > low) right--;
        if (left < right) swap(arr[left], arr[right]);
    }

    swap(arr[low], arr[right]);
    return right;
}

// Quick Sort without median
void QuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

// Partition function with median
int partitionWithMedian(vector<int>& arr, int low, int high) {
    int medianIndex = low + (high - low) / 2;
    swap(arr[low], arr[medianIndex]);

    return partition(arr, low, high);
}

// Quick Sort with median
void QuickSortWithMedian(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionWithMedian(arr, low, high);
        QuickSortWithMedian(arr, low, pivotIndex - 1);
        QuickSortWithMedian(arr, pivotIndex + 1, high);
    }
}

// Selection Sort
void SelectionSort(vector<int>& arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    bool running = true;
    int choice;

    unsigned int size;
    vector<int> arr;
    unsigned int lowerBound = 0;
    unsigned int upperBound = 0;

    srand(time(nullptr));

    do {
        menu();
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1: // Generate random sequence
            cout << "Length of random sequence: ";
            cin >> size;
            generateSequence(arr, size, upperBound, "random");
            break;

        case 2: // Generate ascending sequence
            cout << "Length of ascending sequence: ";
            cin >> size;
            generateSequence(arr, size, upperBound, "ascending");
            break;

        case 3: // Generate descending sequence
            cout << "Length of descending sequence: ";
            cin >> size;
            generateSequence(arr, size, upperBound, "descending");
            break;

        case 4: // Display sequence
            if (arr.empty()) {
                cout << "The sequence is empty!" << endl;
            }
            else {
                print(arr);
            }
            break;

        case 5: // Check if sorted
            if (isSorted(arr)) {
                cout << "The sequence is sorted." << endl;
            }
            else {
                cout << "The sequence is not sorted." << endl;
            }
            break;

        case 6: // Quick Sort without median
            if (arr.empty()) {
                cout << "The sequence is empty. Please generate a sequence first!" << endl;
            }
            else {
                auto start = chrono::steady_clock::now();
                QuickSort(arr, lowerBound, upperBound);
                auto end = chrono::steady_clock::now();
                cout << "Sorting time: "
                    << chrono::duration_cast<chrono::microseconds>(end - start).count()
                    << "μs." << endl;
            }
            break;

        case 7: // Quick Sort with median
            if (arr.empty()) {
                cout << "The sequence is empty. Please generate a sequence first!" << endl;
            }
            else {
                auto start = chrono::steady_clock::now();
                QuickSortWithMedian(arr, lowerBound, upperBound);
                auto end = chrono::steady_clock::now();
                cout << "Sorting time: "
                    << chrono::duration_cast<chrono::microseconds>(end - start).count()
                    << "μs." << endl;
            }
            break;

        case 8: // Selection Sort
            if (arr.empty()) {
                cout << "The sequence is empty. Please generate a sequence first!" << endl;
            }
            else {
                auto start = chrono::steady_clock::now();
                SelectionSort(arr, size);
                auto end = chrono::steady_clock::now();
                cout << "Sorting time: "
                    << chrono::duration_cast<chrono::microseconds>(end - start).count()
                    << "μs." << endl;
            }
            break;

        case 9: // Exit
            running = false;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (running);

    return 0;
}
