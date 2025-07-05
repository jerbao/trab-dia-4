#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <string>
#include "algoritmos.h"

// Função para gerar um vetor com números aleatórios
std::vector<int> gerarVetorAleatorio(int tamanho) {
    std::vector<int> arr(tamanho);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, tamanho * 10);
    for (int i = 0; i < tamanho; ++i) {
        arr[i] = distrib(gen);
    }
    return arr;
}

// Função para gerar um vetor quase ordenado
std::vector<int> gerarVetorQuaseOrdenado(int tamanho) {
    std::vector<int> arr(tamanho);
    for (int i = 0; i < tamanho; ++i) {
        arr[i] = i + 1;
    }
    // Troca 10% dos elementos para criar desordem
    int trocas = tamanho / 10;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, tamanho - 1);
    for (int i = 0; i < trocas; ++i) {
        std::swap(arr[distrib(gen)], arr[distrib(gen)]);
    }
    return arr;
}

// Função para gerar um vetor inversamente ordenado
std::vector<int> gerarVetorInversamenteOrdenado(int tamanho) {
    std::vector<int> arr(tamanho);
    for (int i = 0; i < tamanho; ++i) {
        arr[i] = tamanho - i;
    }
    return arr;
}

// Função para imprimir os resultados
void imprimirResultados(const std::string& nomeAlgoritmo, const std::string& tipoVetor, int tamanho, double tempo, long long comparacoes, long long trocas) {
    std::cout << nomeAlgoritmo << "," << tipoVetor << "," << tamanho << "," << tempo << "," << comparacoes << "," << trocas << std::endl;
}

int main() {
    std::vector<int> tamanhos = {1000, 5000, 10000};
    std::vector<std::string> tiposVetor = {"Aleatorio", "Quase Ordenado", "Inversamente Ordenado"};
    std::vector<std::string> nomesAlgoritmos = {"BubbleSort", "SelectionSort", "InsertionSort", "MergeSort", "QuickSort"};

    // Imprime o cabeçalho da tabela CSV
    std::cout << "Algoritmo,TipoVetor,Tamanho,Tempo(ms),Comparacoes,Trocas" << std::endl;

    for (const auto& tipo : tiposVetor) {
        for (int tamanho : tamanhos) {
            std::vector<int> vetorOriginal;
            if (tipo == "Aleatorio") {
                vetorOriginal = gerarVetorAleatorio(tamanho);
            }
            else if (tipo == "Quase Ordenado") {
                vetorOriginal = gerarVetorQuaseOrdenado(tamanho);
            }
            else {
                vetorOriginal = gerarVetorInversamenteOrdenado(tamanho);
            }

            for (const auto& algo : nomesAlgoritmos) {
                std::vector<int> vetorCopia = vetorOriginal;
                long long comparacoes = 0;
                long long trocas = 0;

                auto start = std::chrono::high_resolution_clock::now();

                if (algo == "BubbleSort") {
                    bubbleSort(vetorCopia.data(), tamanho, comparacoes, trocas);
                }
                else if (algo == "SelectionSort") {
                    selectionSort(vetorCopia.data(), tamanho, comparacoes, trocas);
                }
                else if (algo == "InsertionSort") {
                    insertionSort(vetorCopia.data(), tamanho, comparacoes, trocas);
                }
                else if (algo == "MergeSort") {
                    mergeSort(vetorCopia.data(), 0, tamanho - 1, comparacoes, trocas);
                }
                else if (algo == "QuickSort") {
                    quickSort(vetorCopia.data(), 0, tamanho - 1, comparacoes, trocas);
                }

                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> tempo = end - start;

                imprimirResultados(algo, tipo, tamanho, tempo.count(), comparacoes, trocas);
            }
        }
    }

    return 0;
}
