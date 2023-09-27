#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr)
        return -1;
    int count = 0;

    if (left < right) {
        int l = left;
        int r = right;
        char *pivot = arr[(l + r) / 2];

        while (l <= r) {
            while (mx_strlen(arr[l]) < mx_strlen(pivot))
                l++;
            while (mx_strlen(arr[r]) > mx_strlen(pivot))
                r--;

            if (l <= r) {
                if (mx_strlen(arr[r]) != mx_strlen(arr[l])) {
                    char *temp = arr[l];
                    arr[l] = arr[r];
                    arr[r] = temp;
                    count++;
                }
                l++;
                r--;
            }
        }
        count += mx_quicksort(arr, left, r);
        count += mx_quicksort(arr, l, right);
    }
    return count;
}
