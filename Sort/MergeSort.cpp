void Sort(int* a, int left, int mid, int right) {
    int t1 = 0;
    int t2 = 0;
    int* res = new int[right - left];

    while ((left + t1 < mid) and (mid + t2 < right)) {
        if (a[left + t1] < a[mid + t2]) {
            res[t1 + t2] = a[left + t1];
            t1++;
        } else {
            res[t1 + t2] = a[mid + t2];
            t2++;
        }
    }

    while (left + t1 < mid) {
        res[t1 + t2] = a[left + t1];
        t1++;
    }

    while (mid + t2 < right) {
        res[t1 + t2] = a[mid + t2];
        t2++;
    }

    for (int i = 0; i < (t1 + t2); ++i) {
        a[left + i] = res[i];
    }

    delete[] res;
}

void MergeSortRecursive(int* a, int left, int right) {
    if ((left + 1) >= right) {
        return;
    }

    int mid = (left + right) / 2;
    MergeSortRecursive(a, left, mid);
    MergeSortRecursive(a, mid, right);
    Sort(a, left, mid, right);
}