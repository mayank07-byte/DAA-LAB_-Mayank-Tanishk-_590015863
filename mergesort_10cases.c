#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[low + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void merge_sort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (high + low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    srand(1); 

    // Test Case 1: Small array
    int arr1[] = {5, 3, 8, 1, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("\n--- Test Case 1 (Small array) ---\nInput: ");
    print_array(arr1, n1);
    merge_sort(arr1, 0, n1 - 1);
    printf("Output: ");
    print_array(arr1, n1);

    // Test Case 2: Already sorted
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("\n--- Test Case 2 (Already sorted) ---\nInput: ");
    print_array(arr2, n2);
    merge_sort(arr2, 0, n2 - 1);
    printf("Output: ");
    print_array(arr2, n2);

    // Test Case 3: Reverse sorted
    int arr3[] = {9, 8, 7, 6, 5, 4, 3};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("\n--- Test Case 3 (Reverse sorted) ---\nInput: ");
    print_array(arr3, n3);
    merge_sort(arr3, 0, n3 - 1);
    printf("Output: ");
    print_array(arr3, n3);

    // Test Case 4: Duplicates
    int arr4[] = {4, 2, 2, 1, 1, 3, 5, 5};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("\n--- Test Case 4 (Duplicates) ---\nInput: ");
    print_array(arr4, n4);
    merge_sort(arr4, 0, n4 - 1);
    printf("Output: ");
    print_array(arr4, n4);

    // Test Case 5: With negatives
    int arr5[] = {-5, 10, -2, -7, 9, 0, 3, -1};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("\n--- Test Case 5 (With negatives) ---\nInput: ");
    print_array(arr5, n5);
    merge_sort(arr5, 0, n5 - 1);
    printf("Output: ");
    print_array(arr5, n5);

    // Test Case 6: Odd-sized array
    int arr6[] = {11, 3, 7, 2, 9, 14, 1};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    printf("\n--- Test Case 6 (Odd-sized array, n=7) ---\nInput: ");
    print_array(arr6, n6);
    merge_sort(arr6, 0, n6 - 1);
    printf("Output: ");
    print_array(arr6, n6);

    // Test Case 7: Even-sized array
    int arr7[] = {20, 11, 5, 8, 19, 2, 14, 1, 7, 10};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    printf("\n--- Test Case 7 (Even-sized array, n=10) ---\nInput: ");
    print_array(arr7, n7);
    merge_sort(arr7, 0, n7 - 1);
    printf("Output: ");
    print_array(arr7, n7);

    // Test Case 8: Large random array (n=1000)
    int n8 = 1000;
    int arr8[n8];
    for (int i = 0; i < n8; i++) arr8[i] = rand() % 200;
    merge_sort(arr8, 0, n8 - 1);
    printf("\n--- Test Case 8 (Large random array, n=1000) ---\nOutput (first 20 elements): ");
    for (int i = 0; i < 20; i++) printf("%d ", arr8[i]);
    printf("...\n");

    // Test Case 9: Very large random array (n=10000)
    int n9 = 10000;
    int arr9[n9];
    for (int i = 0; i < n9; i++) arr9[i] = rand() % 500;
    merge_sort(arr9, 0, n9 - 1);
    printf("\n--- Test Case 9 (Very large random array, n=10000) ---\nOutput (first 20 elements): ");
    for (int i = 0; i < 20; i++) printf("%d ", arr9[i]);
    printf("...\n");

    // Test Case 10: All elements same
    int arr10[] = {7, 7, 7, 7, 7, 7, 7, 7};
    int n10 = sizeof(arr10) / sizeof(arr10[0]);
    printf("\n--- Test Case 10 (All elements same) ---\nInput: ");
    print_array(arr10, n10);
    merge_sort(arr10, 0, n10 - 1);
    printf("Output: ");
    print_array(arr10, n10);

    return 0;
}
