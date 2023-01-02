#include <DEEP_EYE.hpp>

void image_function(wrd::Image& img) {
    //"BLACK BOX"
    for(std::size_t y = 0; y < img.getResolution().y; y++) {
        for(std::size_t x = 0; x < img.getResolution().x; x++) {
            //swap the R and B vals
            wrd::Pixel pxl = img.getPixel(Vector2u(x, y));
            if(x % 2 == 0) {
                pxl.setRGB(
                    pxl.getRGB()._triplet_unit_3,
                    pxl.getRGB()._triplet_unit_2,
                    pxl.getRGB()._triplet_unit_1
                );
                img.setPixel(Vector2u(x, y), pxl);
            }
        }
    }
}

int main() {
    wrd::Image img;
    imgstream::read(img, "circle1.bmp");
    image_function(img);
    imgstream::render(img, "Image2.bmp");
}