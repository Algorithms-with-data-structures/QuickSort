# Quick Sort Implementation in C++

This repository contains an implementation of the Quick Sort algorithm in C++, along with additional functionalities such as sequence generation, sorting using a median pivot, and comparison with Selection Sort.

---

## Overview of Quick Sort
Quick Sort is a highly efficient sorting algorithm that uses the divide-and-conquer paradigm. It works by selecting a pivot element, partitioning the array around the pivot, and then recursively sorting the subarrays. The algorithm has an average time complexity of **O(n log n)**, making it suitable for large datasets.

### Key Features of This Implementation
- **Quick Sort without Median**: The first element is used as the pivot.
- **Quick Sort with Median**: The median of the array is used as the pivot to improve performance.
- **Selection Sort**: Provided as an alternative for comparison, with a time complexity of **O(n^2)**.

---

## Features of the Program
This program offers the following functionalities:

1. Generate a random, ascending, or descending sequence of integers.
2. Display the current sequence.
3. Check if the sequence is sorted.
4. Sort the sequence using:
   - Quick Sort without a median pivot.
   - Quick Sort with a median pivot.
   - Selection Sort.
5. Measure and display the sorting time for performance comparison.

---

## How to Use
### 1. Clone the Repository
```bash
git clone https://github.com/your-repo/quick-sort.git
cd quick-sort
```

### 2. Compile the Program
Use a C++ compiler to compile the program. For example:
```bash
g++ -o quick_sort quick_sort.cpp
```

### 3. Run the Program
Run the compiled program:
```bash
./quick_sort
```

### 4. Program Menu
The program displays the following menu:
```plaintext
Quick Sort - Options:

1) Generate a random sequence
2) Generate an ascending sequence
3) Generate a descending sequence
4) Display the sequence
5) Check if the sequence is sorted
6) Quick Sort without median
7) Quick Sort with median
8) Selection Sort
9) Exit
```
Select an option by entering the corresponding number.

---

## Program Flow and Functionality
### Sequence Generation
- **Random Sequence**: Generates a sequence of random integers.
- **Ascending Sequence**: Generates a sorted sequence in ascending order.
- **Descending Sequence**: Generates a sorted sequence in descending order.

### Sorting Options
1. **Quick Sort without Median**:
   - Uses the first element as the pivot.
   - Average complexity: **O(n log n)**.

2. **Quick Sort with Median**:
   - Uses the median as the pivot for better partitioning.
   - Average complexity: **O(n log n)**.

3. **Selection Sort**:
   - Iteratively selects the smallest element and swaps it to the front.
   - Complexity: **O(n^2)**.

### Performance Measurement
The program measures and displays the time taken to sort the sequence using each algorithm. Time is measured in microseconds (\u03BCs).

---

## Example Usage
### Generate a Random Sequence and Sort It
1. Select option `1` to generate a random sequence.
2. Specify the length of the sequence (e.g., 1000).
3. Select option `4` to view the sequence.
4. Select option `6` or `7` to sort the sequence using Quick Sort.
5. Observe the sorting time displayed.

---

## Example Code Snippet
### Quick Sort Partition Function
```cpp
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
```
