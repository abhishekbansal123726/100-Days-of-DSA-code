#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, count = 0;
    int hash[200001] = {0};

    hash[100000] = 1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        count += hash[sum + 100000];
        hash[sum + 100000]++;
    }

    printf("%d", count);
    return 0;
}
