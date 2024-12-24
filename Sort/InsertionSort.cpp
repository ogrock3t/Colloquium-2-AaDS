void InsertionSort(int* arr, int N) {
    for (size_t j = 1; j < N; ++j) {
        int key = arr[j];
        size_t i = j - 1;

        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = key;
    }
}