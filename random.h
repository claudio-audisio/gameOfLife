#pragma once

#include <random>


inline std::random_device rd;
inline std::mt19937 gen(rd());
inline std::uniform_int_distribution<> distrib(1, 100);