// 2019054957_Lee Yongwoo_12838
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int frequency;
    char ch[5];
    struct node* left;
    struct node* right;
} Node;

typedef struct heap {
    Node* arr[30001];
    int size;
    int capacity;
} Heap;

int sum;

Node* makeLeaf();
void insert(Heap* heap, Node* node);
Node* extractMin(Heap* heap);
void buildHuffman(Heap* heap);
Node* merge(Node* node1, Node* node2);
void traversal(Node* node, int depth);
void freeTree(Node* node);

int main(void) {
    int N, i, S;
    int t = 0; 
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = N;

    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        insert(heap, makeLeaf());    
    }
    scanf("%d", &S);

    buildHuffman(heap);
    traversal(heap->arr[1], 0);

    for (i = 1; i < N; i *= 2) {
        t++;
    }

    if(N == 1) {
        printf("%d\n", S);
        printf("%d\n", S);
    }
    else {
        printf("%d\n", S * t);
        printf("%d\n", sum);
    }
    
    freeTree(heap->arr[1]);
    free(heap);
    return 0;
}

Node* makeLeaf() {
    Node* node = (Node*)malloc(sizeof(Node)); 
    scanf("%4s", node->ch);
    scanf("%d", &node->frequency);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Heap* heap, Node* node) {
    int i;
    for(i = ++heap->size; i != 1 && heap->arr[i / 2]->frequency > node->frequency; i /= 2) {
        heap->arr[i] = heap->arr[i / 2];
    }
    heap->arr[i] = node;
}

Node* extractMin(Heap* heap) {
    int i, child;
    Node* min;
    Node* last;

    min = heap->arr[1];
    last = heap->arr[heap->size--];

    for(i = 1; i * 2 <= heap->size; i = child) {
        child = i * 2;
        if(child < heap->size && heap->arr[child + 1]->frequency < heap->arr[child]->frequency) {
            child++;
        }
        if(last->frequency > heap->arr[child]->frequency) {
            heap->arr[i] = heap->arr[child];
        }
        else {
            break;
        }
    }
    heap->arr[i] = last;
    return min; 
}

void buildHuffman(Heap* heap) {
    Node* temp1;
    Node* temp2;
    Node* parent;
    while(heap->size > 1) {
        temp1 = extractMin(heap);
        temp2 = extractMin(heap);
        parent = merge(temp1, temp2);
        insert(heap, parent);
    }
}

Node* merge(Node* node1, Node* node2) {
    Node* parent = (Node*)malloc(sizeof(Node));
    if(node1->frequency < node2->frequency) {
        parent->left = node1;
        parent->right = node2;
    }
    else {
        parent->left = node2;
        parent->right = node1;
    }
    parent->frequency = node1->frequency + node2->frequency;
    parent->ch[0] = '\0';
    return parent;
}

void traversal(Node* node, int depth) {
    if(node) {
        traversal(node->left, depth + 1);
        if(node->ch[0] != '\0') {
            sum += depth * node->frequency;
        }
        traversal(node->right, depth + 1);
    }
}

void freeTree(Node* node) {
    int i;
    if(node) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}