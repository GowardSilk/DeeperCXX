#include <DEEP_EYE.hpp>

int main() {

    //create blank image
    wrd::Image img;
    
    //retrieve image from Deep Eye
    wrd::DeepEye::IMG_download(img, wrd::JPEG::MRCH_2_2049);

    //"BLACK BOX"
    for(std::size_t y = 0; y < img.getResolution().y; y++) {
        for(std::size_t x = 0; x < img.getResolution().x; x++) {
            wrd::Pixel pxl = img.getPixel(Vector2u(x, y));
            img.setPixel(Vector2u(x, y), pxl);
        }
    }

    //test
    wrd::DeepEye::render(img);

    return DEEPER;
}