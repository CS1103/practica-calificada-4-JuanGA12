//
// Created by Juan Galvez on 2019-12-01.
//

#ifndef PC4_BLUE_FILTER_H
#define PC4_BLUE_FILTER_H

#include <iostream>
#include <vector>
#include <thread>
#include <string_view>
#include "lodepng.h"
#include "Decode_Encode.h"

using namespace std;

template <typename T, typename T1>
void Blue_filter(T image, T1 w, T1 h) {

    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
            image[i * w * 4 + j + 0] = 0; // Red component
            image[i * w * 4 + j + 1] = 0; // Green component
        }
    }
    encode("../Blue_Filter.png", image, w, h);
}
#endif //PC4_BLUE_FILTER_H
