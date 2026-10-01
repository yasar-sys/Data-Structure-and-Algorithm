#include <stdio.h>

int main() {
    int a[100], n, i, j, temp, key;
    int low, high, mid, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (in any order):\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // ১. অ্যারে সর্ট করা (Bubble Sort)
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                // অদল-বদল (Swap)
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // সর্ট করার পর অ্যারেটি কেমন হলো তা দেখানো (ঐচ্ছিক)
    printf("\nSorted elements: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter element to search: ");
    scanf("%d", &key);

    // ২. বাইনারি সার্চ (Binary Search)
    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(a[mid] == key) {
            printf("Element found at position %d (in sorted array)\n", mid + 1);
            found = 1;
            break;
        }
        else if(key < a[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if(found == 0) {
        printf("Element not found\n");
    }

    return 0;
}