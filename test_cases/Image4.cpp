#include <DEEP_EYE.hpp>
#include <Benchmark.hpp>

void image_function(wrd::Image& img) {
    Benchmark tester;
#define MT
#ifdef MT
    std::for_each(
        std::execution::par,
        img.begin(),
        img.end(),
        [&](std::vector<wrd::Pixel>& pxl_vec) {
            std::reverse(std::begin(pxl_vec), std::end(pxl_vec));
        }
    );
#else
    for(std::vector<wrd::Pixel>& pxl_vec : img) {
        std::reverse(std::begin(pxl_vec), std::end(pxl_vec));
    }
#endif
    for(unsigned y = 0; y < img.getResolution().y/2; y++) {
        for(unsigned x = 0; x < img.getResolution().x; x++) {
            if(x % 2 == 0) {
                //swap two (opposite) pixels
                wrd::Pixel pxl = img.getPixel(Vector2u(x, y));
                img.setPixel(Vector2u(x, y), img.getPixel(Vector2u(x, img.getResolution().y - y - 1)));
                img.setPixel(Vector2u(x, img.getResolution().y - y - 1), pxl);
            }
        }
    }
}

int main() {
    wrd::Image img;
    imgstream::read(img, "Image4_Original.bmp");
    image_function(img);
    imgstream::render(img, "Image4.bmp");
}