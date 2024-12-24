void SiftDown(int* arr, int N, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int root = i;

    if (left < N && arr[left] > arr[root]) root = left;
    if (right < N && arr[right] > arr[root]) root = right;

    if (root != i) {
        std::swap(arr[root], arr[i]);
        SiftDown(arr, N, root);
    }
}

void HeapSort(int* arr, int& N) {
    for (int i = (N / 2) - 1; i >= 0; --i) {
        SiftDown(arr, N, i);
    }

    for (int i = (N - 1); i > 0; --i) {
        std::swap(arr[0], arr[i]);
        SiftDown(arr, i, 0);
    }
}