#include <DEEP_EYE.hpp>

int main() {

    //create blank image
    wrd::Image img;
    wrd::DeepEye::IMG_download(img, wrd::JPEG::MRCH_2_2049);
    wrd::DeepEye::render(img);

    return DEEPER;
}