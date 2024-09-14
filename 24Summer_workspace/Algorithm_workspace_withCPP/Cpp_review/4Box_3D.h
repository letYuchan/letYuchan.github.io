#pragma once
#include <iostream>
using namespace std;

namespace three_dim {
class Box_ {
   public:
    void print() { cout << height << " " << width << " " << length << endl; }
    double height, width, length;
};
}  // namespace three_dim