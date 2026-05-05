#include <stdio.h>

// Check if allocation is possible with maxPages limit
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book exceeds maxPages → impossible
        if (arr[i] > maxPages)
            return 0;

        if (currentPages + arr[i] > maxPages) {
            students++;
            currentPages = arr[i];

            if (students > m)
                return 0;
        } else {
            currentPages += arr[i];
        }
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m) {
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

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller maximum
        } else {
            low = mid + 1;   // increase limit
        }
    }

    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = allocateBooks(arr, n, m);
    printf("%d", result);

    return 0;
}