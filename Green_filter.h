//
// Created by Juan Galvez on 2019-12-01.
//

#ifndef PC4_GREEN_FILTER_H
#define PC4_GREEN_FILTER_H

#include <iostream>
#include <vector>
#include <thread>
#include <string_view>
#include "lodepng.h"
#include "Decode_Encode.h"

using namespace std;

template <typename  T, typename T1 >
void Green_filter(T image, T1 w, T1 h) {


    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
            image[i * w * 4 + j + 0] = 0; // Red component
            image[i * w * 4 + j + 2] = 0; // Blue component
        }

        encode("../Green_filter.png", image, w, h);
    }
}
#endif //PC4_GREEN_FILTER_H
