#pragma once
#include <iostream>
#include <random>

template<typename T>
T rand(int min, int max)
{
    static std::default_random_engine generator{std::random_device{}()};
    std::uniform_int_distribution<T>  distribution{min, max};
    return distribution(generator);
}