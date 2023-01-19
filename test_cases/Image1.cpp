#include <DEEP_EYE.hpp>
#include <Benchmark.hpp>
#define MT

void image_function(wrd::Image& img) {
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
                    [](wrd::Pixel& pxl) {
                        pxl.setRGB(
                                pxl.getRGB()._triplet_unit_3,
                                pxl.getRGB()._triplet_unit_2,
                                pxl.getRGB()._triplet_unit_1
                            );
                    }
                );
            }
        );
    #else
        for(unsigned y = 0; y < img.getResolution().y; y++) {
            for(unsigned x = 0; x < img.getResolution().x; x++) {
                wrd::Pixel pxl = img.getPixel(Vector2u(x, y));
                pxl.setRGB(pxl.getRGB()._triplet_unit_3, pxl.getRGB()._triplet_unit_2, pxl.getRGB()._triplet_unit_1);
                img.setPixel(Vector2u(x, y), pxl);
            }
        }
    #endif
}

int main() {

    wrd::Image img;
    imgstream::read(img, "Image1_Original.bmp");
    image_function(img);
    imgstream::render(img, "Image1.bmp");

}