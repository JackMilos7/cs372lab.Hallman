//File: Vector.cpp
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include "Vector.h"
Vector Vector::operator+(const Vector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument("Vectors must be of the same size for addition");
    }
    Vector result;
    result.elements.resize(size());
    for (size_t i = 0; i < size(); ++i) {
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}

Vector Vector::operator-(const Vector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument("Vectors must be of the same size for subtraction");
    }
    Vector result;
    result.elements.resize(size());
    for (size_t i = 0; i < size(); ++i) {
        result.elements[i] = elements[i] - other.elements[i];
    }
    return result;
}

Vector Vector::operator*(double scalar) const {
    Vector result;
    result.elements.resize(size());
    for (size_t i = 0; i < size(); ++i) {
        result.elements[i] = elements[i] * scalar;
    }
    return result;
}

double Vector::dot(const Vector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument("Vectors must be of the same size for dot product");
    }
    double result = 0;
    for (size_t i = 0; i < size(); ++i) {
        result += elements[i] * other.elements[i];
    }
    return result;
}

double Vector::norm() const {
    return std::sqrt(this->dot(*this));
}