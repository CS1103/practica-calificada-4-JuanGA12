//
// Created by Juan Galvez on 2019-12-01.
//

#ifndef PC4_DECODE_ENCODE_H
#define PC4_DECODE_ENCODE_H

#include <iostream>
#include <vector>
#include "lodepng.h"

using namespace std;

template <typename T>

std::vector<unsigned char> decode(string_view filename, T & width, T & height) {

    std::vector<unsigned char> result;
    unsigned error = lodepng::decode(result, width, height, filename.data());
    if (error) {
        std::cerr << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
    return result;
}

template <typename T>
void encode(string_view filename, T& image, unsigned width, unsigned height) {
    unsigned error = lodepng::encode(filename.data(), image, width, height);
    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}

#endif //PC4_DECODE_ENCODE_H
