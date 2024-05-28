//File: Array.h
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <stdexcept>
#include <array>
#include <cmath>

template <typename T, std::size_t N>
class Array {
public:
    Array() = default;
    Array(const std::array<T, N>& elements) : elements(elements) {}

    std::size_t size() const { return N; }
    T& operator[](std::size_t index) { return elements.at(index); }
    const T& operator[](std::size_t index) const { return elements.at(index); }

    Array<T, N> operator+(const Array<T, N>& other) const;
    Array<T, N> operator-(const Array<T, N>& other) const;
    Array<T, N> operator*(T scalar) const;
    T dot(const Array<T, N>& other) const;
    double norm() const;

private:
    std::array<T, N> elements = {};
};

template <typename T, std::size_t N>
Array<T, N> Array<T, N>::operator+(const Array<T, N>& other) const {
    Array<T, N> result;
    for (std::size_t i = 0; i < N; ++i) {
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}

template <typename T, std::size_t N>
Array<T, N> Array<T, N>::operator-(const Array<T, N>& other) const {
    Array<T, N> result;
    for (std::size_t i = 0; i < N; ++i) {
        result.elements[i] = elements[i] - other.elements[i];
    }
    return result;
}

template <typename T, std::size_t N>
Array<T, N> Array<T, N>::operator*(T scalar) const {
    Array<T, N> result;
    for (std::size_t i = 0; i < N; ++i) {
        result.elements[i] = elements[i] * scalar;
    }
    return result;
}

template <typename T, std::size_t N>
T Array<T, N>::dot(const Array<T, N>& other) const {
    T result = 0;
    for (std::size_t i = 0; i < N; ++i) {
        result += elements[i] * other.elements[i];
    }
    return result;
}

template <typename T, std::size_t N>
double Array<T, N>::norm() const {
    return std::sqrt(this->dot(*this));
}

#endif