#ifndef _BOX_
#define _BOX_

#include <iostream>
using namespace std;

class Box {
   public:
    void print() { cout << height << " " << width << " " << length; }
    double height, width, length;
};
#endif
