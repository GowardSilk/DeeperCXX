#include <DEEP_EYE.hpp>
#include <Benchmark.hpp>
#define MT

// void rotate(wrd::Image& img, Vector2u begin, Vector2u end) {
//     Benchmark tester;
//     //"rotate" image by 180 deg
//     for(unsigned y = begin.y; y < end.y; y++) {
//         for(unsigned x = begin.x; x < end.x; x++) {
//             wrd::Pixel pxl = img.getPixel(Vector2u(x, (end.y - 1) - y));
//             img.setPixel(Vector2u(x, (end.y - 1) - y), img.getPixel(Vector2u(x, y)));
//             img.setPixel(Vector2u(x, y), pxl);
//         }
//     }
// }

// void fill(wrd::Image &img, Vector2u begin, Vector2u end, wrd::Color clr) {
//     for(unsigned y = begin.y; y < end.y; y++) {
//         for(unsigned x = begin.x; x < end.x; x++) {
//             img.setPixel(Vector2u(x, y), wrd::Pixel(clr));
//         }
//     }
// }

void pxl_RGBtoHWB(wrd::Pixel& rgb) {
    int r = rgb.getRGB()._triplet_unit_1,
        g = rgb.getRGB()._triplet_unit_2,
        b = rgb.getRGB()._triplet_unit_3;
    int min = std::min({r, g, b});
    int max = std::max({r, g, b});

    int w = max - min;
    int h;

    if (w == 0)
        h = 0;
    else if (r == max)
        h = (g - b) * 60 / w % 360;
    else if (g == max)
        h = (b - r) * 60 / w + 120;
    else
        h = (r - g) * 60 / w + 240;

    rgb.setRGB(h, w, min);
    //return wrd::Pixel(h, w, b);
}

void img_RGBtoHWB(wrd::Image& img) {
    Benchmark tester;
    #ifdef MT
    std::for_each(
        std::execution::par,
        img.begin(),
        img.end(),
        [&](std::vector<wrd::Pixel>& pxl_vec) {
            std::for_each(
                std::execution::par,
                pxl_vec.begin(),
                pxl_vec.end(),
                [&](wrd::Pixel& pxl) {
                    pxl_RGBtoHWB(pxl);
                }
            );
        }
    );
    #else
    #endif
}

int main() {

    wrd::Image img;
    imgstream::read(img, "circle1.bmp");
    //split that image into 4 smaller images and rotate each of them
    //  check boundaries
    //      for height
    // if(img.getResolution().y % 2 != 0) {
    //     int count = (img.getResolution().y % 2);
    //     img.setResolution(Vector2sz(img.getResolution().x, img.getResolution().y + count));
    //     while(count > 0) {
    //         for(uint32_t i = 0; i < img.getResolution().x; i++) {
    //             img.setPixel(Vector2u(i, img.getResolution().y-count), wrd::Pixel(wrd::Color::BLACK));
    //         }
    //         count--;
    //     }
    // }
    //      for width
    // if(img.getResolution().x % 2 != 0) {
    //     int count = (img.getResolution().x % 2);
    //     img.setResolution(Vector2sz(img.getResolution().x + count, img.getResolution().y));
    //     while(count > 0) {
    //         for(uint32_t i = 0; i < img.getResolution().x; i++) {
    //             img.setPixel(Vector2u(i, img.getResolution().y-count), wrd::Pixel(wrd::Color::BLACK));
    //         }
    //         count--;
    //     }
    // }

    
    img_RGBtoHWB(img);
    imgstream::render(img, "Image4.bmp");
}