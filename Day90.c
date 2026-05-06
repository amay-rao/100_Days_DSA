#include <stdio.h>

// Check if we can paint with given maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        // If a single board exceeds maxTime → impossible
        if (arr[i] > maxTime)
            return 0;

        if (currentTime + arr[i] > maxTime) {
            painters++;
            currentTime = arr[i];

            if (painters > k)
                return 0;
        } else {
            currentTime += arr[i];
        }
    }

    return 1;
}

int minTime(int arr[], int n, int k) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max;
    int high = sum;
    int ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller time
        } else {
            low = mid + 1;   // increase time
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = minTime(arr, n, k);
    printf("%d", result);

    return 0;
}