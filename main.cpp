#include <iostream>
#include <vector>
#include <string_view>
#include <thread>
#include "lodepng.h"
#include "Green_filter.h"
#include "Red_filter.h"
#include "Blue_filter.h"


using namespace std;


int main(){
    unsigned int w;
    unsigned int h;
    auto image = decode("../in.png", w, h);

   auto t1 = thread([&image,&w,&h]{
        Green_filter(image,w,h);
    });


    auto t2 = thread([&image,&w,&h]{
        Red_filter(image,w,h);
    });


    auto t3 = thread ([&image,&w,&h]{
        Blue_filter(image,w,h);
    });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
