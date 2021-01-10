#pragma once
#include "Organism.h"
//SOURCE - RÓD£O
//http://neutrofoton.github.io/blog/2016/12/30/c-plus-plus-set-with-custom-comparator/

struct Comparison
{
public:
    bool operator()(const Organism* left, const Organism* right) const {
        return *left > *right;
    }
};