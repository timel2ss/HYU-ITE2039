// 2019054957_Lee Yongwoo_12838
#include <stdio.h>

typedef struct Heap_ {
    int arr[100001];
    int total;
    int size;
} Heap;

void minHeapify(Heap* heap, int idx) {
    int child, temp, i;
    for(i = idx; i * 2 <= heap->size; i = child) {
        child = i * 2;
        if(child < heap->size && heap->arr[child + 1] < heap->arr[child]) {
            child++;
        }
        if(heap->arr[i] > heap->arr[child]) {
            temp = heap->arr[i];
            heap->arr[i] = heap->arr[child];
            heap->arr[child] = temp;
        }
        else
            break;
    }
}

void HeapSort(Heap* heap) {
    int i, temp;
    // BuildMinHeap
    for(i = heap->total / 2; i > 0; i--) {
        minHeapify(heap, i);
    }
    
    while(heap->size > 1) {
        // ExtractMin
        temp = heap->arr[1];
        heap->arr[1] = heap->arr[heap->size];
        heap->arr[heap->size--] = temp;
        minHeapify(heap, 1);
    }
}

int main(void) {
    int N, k;
    Heap heap;
    
    scanf("%d %d", &N, &k);
    heap.size = 0;
    heap.total = N;
    while(N--) {
        scanf("%d", &heap.arr[++heap.size]);
    }

    HeapSort(&heap);

    for(N = 1; N <= k; N++) {
        printf("%d ", heap.arr[N]);
    }
    printf("\n");

    for(N = k + 1; N <= heap.total; N++) {
        printf("%d ", heap.arr[N]);
    }
    return 0;
}