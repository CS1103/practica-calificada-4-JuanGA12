//
// Created by Juan Galvez on 2019-12-01.
//

#ifndef PC4_RED_FILTER_H
#define PC4_RED_FILTER_H

#include <iostream>
#include <vector>
#include <thread>
using namespace std;

void encode2(string_view filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
    unsigned error = lodepng::encode(filename.data(), image, width, height);
    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}
template <typename T>
void Red_filter(T image, unsigned int w, unsigned int h){

    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
            image[i * w * 4 + j + 1] = 0; // Green component
            image[i * w * 4 + j + 2] = 0; // Blue component
        }
    }
    encode2("../Red_Filter.png", image, w, h);
}
#endif //PC4_RED_FILTER_H
