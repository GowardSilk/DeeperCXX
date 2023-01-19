#include <DEEP_EYE.hpp>

void image_function(wrd::Image& img, Vector2u begin, Vector2u end) {
    Benchmark tester;
    for(unsigned y = begin.y; y < end.y/2; y++) {
        for(unsigned x = begin.x; x < end.x; x++) {
            if(x % 2 == 0) {
                //swap two (opposite) pixels
                wrd::Pixel pxl = img.getPixel(Vector2u(x, y));
                img.setPixel(Vector2u(x, y), img.getPixel(Vector2u(x, end.y - y - 1)));
                img.setPixel(Vector2u(x, end.y - y - 1), pxl);
            }
        }
    }
}

void fill(wrd::Image &img, Vector2u begin, Vector2u end, wrd::Color clr) {
    for(unsigned y = begin.y; y < end.y; y++) {
        for(unsigned x = begin.x; x < end.x; x++) {
            img.setPixel(Vector2u(x, y), wrd::Pixel(clr));
        }
    }
}

int main() {
    wrd::Image img;
    imgstream::read(img, "Image3_Original.bmp");
    image_function(img, Vector2u(0, 0), Vector2u(img.getResolution().x, img.getResolution().y));
    imgstream::render(img, "Image3.bmp");
}