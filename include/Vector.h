//File: Vector.h
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <stdexcept>
#include <cmath>

class Vector
{
public:
    Vector() = default;
    Vector(const std::vector<double>& elements) : elements(elements) {}

    size_t size() const { return elements.size(); }
    double& operator[](size_t index) { return elements.at(index); }
    const double& operator[](size_t index) const { return elements.at(index); }

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;
    double dot(const Vector& other) const;
    double norm() const;

private:
    std::vector<double> elements;
};

#endif