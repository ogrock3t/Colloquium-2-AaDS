void SiftUp(int* heap, int i) {
    int root = (i - 1) / 2;

    if (i > 0 && heap[i] > heap[root]) {
        std::swap(heap[i], heap[root]);
        SiftUp(heap, root);
    }
}

void SiftDown(int* heap, int i, int N) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int root = i;

    if (left < N && heap[left] > heap[root]) root = left;
    if (right < N && heap[right] > heap[root]) root = right;

    if (root != i) {
        std::swap(heap[i], heap[root]);
        SiftDown(heap, root, N);
    }
}