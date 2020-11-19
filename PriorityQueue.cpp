// 2019054957_Lee Yongwoo_12838
#include <stdio.h>

typedef struct Heap_ {
    int arr[100001];
    int size;
    int deleted[100001];
    int delSize;
} Heap;

void upHeapify(Heap* heap, int idx){
    int i, temp;
    for(i = idx; i != 1 && heap->arr[i / 2] < heap->arr[i]; i /= 2) {
        temp = heap->arr[i];
        heap->arr[i] = heap->arr[i / 2];
        heap->arr[i / 2] = temp;
    }
}

void downHeapify(Heap* heap, int idx) {
    int child, temp, i;
    for(i = idx; i * 2 <= heap->size; i = child) {
        child = i * 2;
        if(child < heap->size && heap->arr[child + 1] >= heap->arr[child]) {
            child++;
        }
        if(heap->arr[i] < heap->arr[child]) {
            temp = heap->arr[i];
            heap->arr[i] = heap->arr[child];
            heap->arr[child] = temp;
        }
        else
            break;
    }
}

void insert(Heap* heap, int val) {
    int i;
    if(heap->size >= 100000) {
        return;
    }
    for(i = ++heap->size; i != 1 && heap->arr[i / 2] < val; i /= 2) {
        heap->arr[i] = heap->arr[i / 2];
    }
    heap->arr[i] = val;
}

void extractMax(Heap* heap) {
    if(heap->size <= 0) {
        return;
    }
    if(heap->size == 1) {
        int max = heap->arr[heap->size--];
        heap->deleted[++heap->delSize] = max;
        return;
    }
    int max = heap->arr[1];
    int last = heap->arr[heap->size--];
    heap->arr[1] = last;
    downHeapify(heap, 1);
    heap->deleted[++heap->delSize] = max;
}

void substitute(Heap* heap, int idx, int val) {
    if(heap->arr[idx] > val) {
        heap->arr[idx] = val;        
        downHeapify(heap, idx);
    }
    else if(heap->arr[idx] < val) {
        heap->arr[idx] = val;        
        upHeapify(heap, idx);
    }
    else {
        heap->arr[idx] = val;
    }
}

int main(void) {
    Heap heap;
    heap.size = 0;
    heap.delSize = 0;
    int first, second, third, i;
    while(1) {
        scanf("%d", &first);

        switch(first) {
            case 0:
                for(i = 1; i <= heap.delSize; i++){
                    printf("%d ", heap.deleted[i]);
                }
                printf("\n");
                for(i = 1; i <= heap.size; i++) {
                    printf("%d ", heap.arr[i]);
                }
                break;
            case 1:
                scanf("%d", &second);
                insert(&heap, second);
                break;
            case 2:
                extractMax(&heap);
                break;
            case 3:
                scanf("%d %d", &second, &third);
                substitute(&heap, second, third);
                break; 
        }
        if(first == 0)
            break;
    }
    return 0;
}