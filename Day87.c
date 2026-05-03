#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;  // element found
        } else if (arr[mid] < key) {
            low = mid + 1;  // search right
        } else {
            high = mid - 1; // search left
        }
    }

    return -1; // not found
}

int main() {
    int n, key;

    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("%d", result);  // index
    else
        printf("-1");

    return 0;
}