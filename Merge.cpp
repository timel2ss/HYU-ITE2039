// 2019054957_Lee Yongwoo_12838
#include <stdio.h>

void merge(int arr[], int N, int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int temp[100001];
    while(i <= q && j <= r) {
        if(arr[i] >= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= q) {
        temp[k++] = arr[i++];
    }
    while(j <= r) {
        temp[k++] = arr[j++];
    }
    for(k = p; k <= r; k++) {
        arr[k] = temp[k];
    }
}

void mergeSort(int arr[], int N, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, N, p, q);
        mergeSort(arr, N, q + 1, r);
        merge(arr, N, p, q, r);
    }
}

int main(void) {
    int N, i;
    scanf("%d", &N);

    int arr[100001];

    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, N, 0, N-1);

    for(i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}