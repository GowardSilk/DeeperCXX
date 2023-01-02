#include <DEEP_EYE.hpp>

int main() {
    
    //create blank image
    wrd::Image img;

    //download image from DeepEye
    wrd::DeepEye::IMG_download(img, wrd::JPEG::M_5_2049);

    //"BLACK BOX"
    for(std::size_t y = 0; y < img.getResolution().y; y++) {
        for(std::size_t x = 0; x < img.getResolution().x; x++) {
            if(x % 2 == 0) 
                img.setPixel(Vector2u(x, y), wrd::Pixel(0, 0, 0));
            else
                img.setPixel(Vector2u(x, y), wrd::Pixel(255, 255, 255));
        }
    }

    //upload image to DeepEye
    wrd::DeepEye::render(img);

    return DEEPER;
}