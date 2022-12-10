#include "../DEEP_EYE.hpp"

int main() {

    wrd::Image img;

    wrd::DeepEye::IMG_download(img, wrd::JPEG::SP_19_2049);

    //rotate by 90 deg
    for(auto y = 0; y < img.getResolution().y; y++) {
        for(auto x = 0; x < img.getResolution().x; x++) {
            
        }
    }

    //wrd::DeepEye::render(img);

}