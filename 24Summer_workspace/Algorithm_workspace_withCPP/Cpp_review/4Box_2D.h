#pragma once
#include <iostream>
using namespace std;

namespace two_dim {
class Box_ {
   public:
    void print() { cout << length << " " << width << endl; }
    double length, width;
};
}  // namespace two_dim