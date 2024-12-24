int Partition(int* a, int l, int r) { //Hoara
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

int Partition(int* a, int l, int r) { //Lomuto
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; ++j) {
        if (a[j] <= pivot) {
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[r]);
    return i + 1;
}

void QuickSort(int* a, int l, int r) {
    if (l < r) {
        int q = Partition(a, l, r);
        QuickSort(a, l, q); // q - 1 if u use Lomuto
        QuickSort(a, q + 1, r);
    }
}
