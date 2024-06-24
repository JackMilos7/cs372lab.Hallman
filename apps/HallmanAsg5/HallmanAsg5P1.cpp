//File: HallmanAsg5P1.cpp
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

class Sorter {
public:
    static void quicksort(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int pivotIndex = partition(arr, left, right);
            quicksort(arr, left, pivotIndex - 1);
            quicksort(arr, pivotIndex + 1, right);
        }
    }

private:
    static int partition(std::vector<int>& arr, int left, int right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[right]);
        return i + 1;
    }
};

void printTimingResults(const std::vector<int>& sizes, const std::vector<long long>& quicksortTimes, const std::vector<long long>& stlSortTimes) {
    std::cout << "Vector Size\tQuicksort Time (ms)\tstd::sort() Time (ms)\n";
    for (size_t i = 0; i < sizes.size(); ++i) {
        std::cout << sizes[i] << "\t\t" << quicksortTimes[i] << "\t\t\t" << stlSortTimes[i] << "\n";
    }
}

int main() {
    std::vector<int> sizes = { 100, 500, 1000, 5000, 10000, 100000 };
    std::vector<long long> quicksortTimes, stlSortTimes;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100000);

    for (int size : sizes) {
        std::vector<int> vec(size);
        for (int& element : vec) {
            element = dis(gen);
        }

        std::vector<int> vecCopy = vec;

        
        auto start = std::chrono::high_resolution_clock::now();
        Sorter::quicksort(vec, 0, vec.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        quicksortTimes.push_back(duration.count());

        
        start = std::chrono::high_resolution_clock::now();
        std::sort(vecCopy.begin(), vecCopy.end());
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        stlSortTimes.push_back(duration.count());
    }

    printTimingResults(sizes, quicksortTimes, stlSortTimes);

    return 0;
}