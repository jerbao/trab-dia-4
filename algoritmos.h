#ifndef ALGORITMOS_H
#define ALGORITMOS_H

/**
 * @brief Ordena um array de inteiros usando o algoritmo Bubble Sort.
 * @param arr O array a ser ordenado.
 * @param n O número de elementos no array.
 * @param comparacoes Referência para uma variável que contará o número de comparações.
 * @param trocas Referência para uma variável que contará o número de trocas.
 */
void bubbleSort(int arr[], int n, long long& comparacoes, long long& trocas);

/**
 * @brief Ordena um array de inteiros usando o algoritmo Selection Sort.
 * @param arr O array a ser ordenado.
 * @param n O número de elementos no array.
 * @param comparacoes Referência para uma variável que contará o número de comparações.
 * @param trocas Referência para uma variável que contará o número de trocas.
 */
void selectionSort(int arr[], int n, long long& comparacoes, long long& trocas);

/**
 * @brief Ordena um array de inteiros usando o algoritmo Insertion Sort.
 * @param arr O array a ser ordenado.
 * @param n O número de elementos no array.
 * @param comparacoes Referência para uma variável que contará o número de comparações.
 * @param trocas Referência para uma variável que contará o número de deslocamentos (trocas).
 */
void insertionSort(int arr[], int n, long long& comparacoes, long long& trocas);

/**
 * @brief Função principal recursiva que ordena um array usando o Merge Sort.
 * @param arr O array a ser ordenado.
 * @param l O índice inicial do subarray.
 * @param r O índice final do subarray.
 * @param comparacoes Referência para uma variável que contará o número de comparações.
 * @param trocas Referência para uma variável que contará o número de trocas (movimentos).
 */
void mergeSort(int arr[], int l, int r, long long& comparacoes, long long& trocas);

/**
 * @brief Função principal recursiva que ordena um array usando o Quick Sort.
 * @param arr O array a ser ordenado.
 * @param low O índice inicial do subarray.
 * @param high O índice final do subarray.
 * @param comparacoes Referência para uma variável que contará o número de comparações.
 * @param trocas Referência para uma variável que contará o número de trocas.
 */
void quickSort(int arr[], int low, int high, long long& comparacoes, long long& trocas);

#endif