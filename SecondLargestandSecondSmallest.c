#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {5, 1, 9, 2, 8};
    int n = 5;

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++) {

        // For Largest and Second Largest
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }

        // For Smallest and Second Smallest
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    printf("Second Largest = %d\n", secondLargest);
    printf("Second Smallest = %d\n", secondSmallest);

    return 0;
}
