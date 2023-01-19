#include <DEEP_EYE.hpp>
#include <Benchmark.hpp>
#define MT

void image_function(wrd::Image& img, Vector2u begin, Vector2u end) {
    Benchmark timer;
    //"BLACK BOX"
    #ifndef MT
    for(std::vector<wrd::Pixel>& pxl_vec : img) {
        std::reverse(std::begin(pxl_vec), std::end(pxl_vec));
    }
    #else
    std::for_each(
        std::execution::par,
        img.begin(),
        img.end(),
        [&](std::vector<wrd::Pixel>& pxl_vec) {
            std::reverse(std::begin(pxl_vec), std::end(pxl_vec));
        }
    );
    #endif
}


int main() {
    wrd::Image img;
    imgstream::read(img, "Image2_Original.bmp");
    image_function(img, Vector2u(0, 0), Vector2u(img.getResolution().x, img.getResolution().y));
    imgstream::render(img, "Image2.bmp");
}