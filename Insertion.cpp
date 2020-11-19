// 2019054957_이용우_12838
#include <stdio.h>

int main(void) {
    int N, key, temp, i, j;
    scanf("%d", &N);

    int arr[30001];
    for(i = 0; i < N; i++) {
        scanf("%d", &key);
        for(j = i-1; j >= 0 && key > arr[j]; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1]/ = key;
    }

    for(i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}