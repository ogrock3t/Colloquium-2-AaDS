int Partition(int* a, int l, int r) {
    int pivot = a[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j--;
    }
    return j;
}

void QuickSort(int* a, int l, int r) {
    if (l < r) {
        int q = Partition(a, l, r);
        QuickSort(a, l, q);
        QuickSort(a, q + 1, r);
    }
}
