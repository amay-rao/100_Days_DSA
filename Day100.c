#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Node;

void merge(Node arr[], int left, int mid, int right, int count[]) {
    int n = right - left + 1;

    Node temp[n];

    int i = left;
    int j = mid + 1;
    int k = 0;

    int smallerCount = 0;

    while (i <= mid && j <= right) {

        if (arr[j].value < arr[i].value) {
            smallerCount++;
            temp[k++] = arr[j++];
        } else {
            count[arr[i].index] += smallerCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += smallerCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(Node arr[], int left, int right, int count[]) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    Node arr[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    printf("Count of smaller elements on right side:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}