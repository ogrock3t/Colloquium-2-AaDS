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

void heapify(int* arr, int n, int i) {
    int temp = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[temp])
        temp = left;

    if (right < n && arr[right] > arr[temp])
        temp = right;

    if (temp != i) {
        std::swap(arr[i], arr[temp]);

        heapify(arr, n, temp);
    }
}

void buildHeap(int* arr, int N) {
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(arr, N, i);
    }
}