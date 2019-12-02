//
// Created by Juan Galvez on 2019-12-01.
//

#ifndef PC4_ROTATE_H
#define PC4_ROTATE_H

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template <typename T, typename T1>
void Rotate( T image, T1 w, T1 h){
    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
            int r = image[((sin(45)*j + cos(45)*i)) * w * 4 + (cos(45)*j - sin(45)*i) + 0]; // Red component
            int g = image[((sin(45)*j + cos(45)*i)) * w * 4 + (cos(45)*j - sin(45)*i) + 1]; // Green component
            int b = image[((sin(45)*j + cos(45)*i)) * w * 4 + (cos(45)*j - sin(45)*i) + 2]; // Blue component
            int a = image[((sin(45)*j + cos(45)*i)) * w * 4 + (cos(45)*j - sin(45)*i) + 3]; // Alpha component

            image[(i * w * 4 + j + 0)] = r;
            image[(i * w * 4 + j + 1)] = g;
            image[(i * w * 4 + j + 2)] = b;
            image[(i * w * 4 + j + 3)] = a;


        }
    }


    encode("../Rotated.png", image, w, h);

}
#endif //PC4_ROTATE_H
