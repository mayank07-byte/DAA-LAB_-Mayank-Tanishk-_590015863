#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary Search function
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Not found
}

// Function to run one test case and return execution time in microseconds
double runTest(int arr[], int size, int target) {
    clock_t start, end;
    start = clock();
    binarySearch(arr, size, target);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1e6; // microseconds
}

int main() {
    int sizes[] = {1, 10, 100, 1000, 10000};
    FILE *fp = fopen("binary_search_results.csv", "w");

    if (!fp) {
        printf("Error: Could not open file for writing.\n");
        return 1;
    }

    // CSV header
    fprintf(fp, "CaseType,CaseNumber,InputSize,TimeMicroseconds\n");

    printf("Binary Search Performance Analysis\n");
    printf("Results also saved to binary_search_results.csv\n\n");

    // BEST CASES: target found at middle
    for (int i = 0; i < 5; i++) {
        int size = sizes[i];
        int *arr = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) arr[j] = j - size/2; // includes negatives
        int target = arr[size / 2];
        double time = runTest(arr, size, target);
        printf("Best Case %d | Size: %d | Time: %.3f µs\n", i + 1, size, time);
        fprintf(fp, "Best,%d,%d,%.3f\n", i + 1, size, time);
        free(arr);
    }

    printf("\n");

    // WORST CASES: target not present
    for (int i = 0; i < 5; i++) {
        int size = sizes[i];
        int *arr = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) arr[j] = j;
        int target = -99999; // definitely not in array
        double time = runTest(arr, size, target);
        printf("Worst Case %d | Size: %d | Time: %.3f µs\n", i + 1, size, time);
        fprintf(fp, "Worst,%d,%d,%.3f\n", i + 1, size, time);
        free(arr);
    }

    printf("\n");

    // AVERAGE CASES: target at random position
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int size = sizes[i];
        int *arr = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) arr[j] = j * 2; // even numbers
        int target = arr[rand() % size]; // pick a random present number
        double time = runTest(arr, size, target);
        printf("Average Case %d | Size: %d | Time: %.3f µs\n", i + 1, size, time);
        fprintf(fp, "Average,%d,%d,%.3f\n", i + 1, size, time);
        free(arr);
    }

    fclose(fp);
    printf("\nAll results saved in binary_search_results.csv\n");
    return 0;
}
