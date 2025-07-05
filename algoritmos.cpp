#include "algoritmos.h"
#include <utility> // Para std::swap

// Função auxiliar para o Merge Sort
void merge(int arr[], int l, int m, int r, long long& comparacoes, long long& trocas) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        comparacoes++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        trocas++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        trocas++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        trocas++;
    }
}

// Função auxiliar para o Quick Sort
int partition(int arr[], int low, int high, long long& comparacoes, long long& trocas) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparacoes++;
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            trocas++;
        }
    }
    std::swap(arr[i + 1], arr[high]);
    trocas++;
    return (i + 1);
}

// Bubble Sort
void bubbleSort(int arr[], int n, long long& comparacoes, long long& trocas) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                trocas++;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n, long long& comparacoes, long long& trocas) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[min_idx], arr[i]);
            trocas++;
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n, long long& comparacoes, long long& trocas) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && (comparacoes++, arr[j] > key)) {
            arr[j + 1] = arr[j];
            trocas++;
            j = j - 1;
        }
        arr[j + 1] = key;
        trocas++; 
    }
}

// Merge Sort
void mergeSort(int arr[], int l, int r, long long& comparacoes, long long& trocas) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparacoes, trocas);
        mergeSort(arr, m + 1, r, comparacoes, trocas);
        merge(arr, l, m, r, comparacoes, trocas);
    }
}

// Quick Sort
void quickSort(int arr[], int low, int high, long long& comparacoes, long long& trocas) {
    if (low < high) {
        int pi = partition(arr, low, high, comparacoes, trocas);
        quickSort(arr, low, pi - 1, comparacoes, trocas);
        quickSort(arr, pi + 1, high, comparacoes, trocas);
    }
}
