#pragma once
#include "Organism.h"
struct Comparison
{
public:
    bool operator()(const Organism* left, const Organism* right) const {
        return *left > *right;
    }
};