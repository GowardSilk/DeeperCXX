#include "../DEEP_EYE.hpp"

int main() {

    wrd::Image img;

    wrd::DeepEye::IMG_download(img, wrd::JPEG::JL_1_2049);

    //"rotate" image by 180 deg
    for(auto y = 0; y < img.getResolution().y/2+1; y++) {
        for(auto x = 0; x < img.getResolution().x; x++) {
            wrd::Pixel pxl1 = img.getPixel(Vector2u(x, y));
            wrd::Pixel pxl2 = img.getPixel(Vector2u(x, img.getResolution().y-y-1));
            img.setPixel(Vector2u(x, y), pxl2);
            img.setPixel(Vector2u(x, img.getResolution().y-y-1), pxl1);
        }
    }

    for(auto y = 0; y < img.getResolution().y; y++) {
        for(auto x = 0; x < img.getResolution().x; x++) {
            std::cout << img.getPixel(Vector2u(x, y)).getRGB();
        }
        std::cout << std::endl;
    }

    //wrd::DeepEye::render(img);

}