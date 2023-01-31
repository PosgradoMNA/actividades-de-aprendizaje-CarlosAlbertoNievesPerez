// Proyecto que sume en apralelo 2 arreglos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <array>
#include <numeric>
#include <omp.h>
#include <random>

int main()
{
    std::array<int, 10> arr1;
    std::array<int, 10> arr2;
    std::array<int, 10> arr3{ 0 };

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(1, 100);

    // Asignar valores aleatorios a arr1 y arr2
    for (int i = 0; i < arr1.size(); ++i) {
        arr1[i] = distribution(generator);
        arr2[i] = distribution(generator);
    }

#pragma omp parallel for
    for (int i = 0; i < arr1.size(); ++i) {
        arr3[i] = arr1[i] + arr2[i];
    }

    std::cout << "Arreglo resultante: [ ";
    for (const auto& elem : arr3) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}

