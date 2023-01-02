#include <DEEP_EYE.hpp>

int main() {

    wrd::Image img;
    wrd::DeepEye::IMG_download(img, wrd::JPEG::MRCH_2_2049);
    for(auto& vec : img) {
        for(wrd::Pixel& pxl : vec) {
            pxl.setRGB(wrd::Color::GREEN);
        }
    }
    wrd::DeepEye::render(img);

    wrd::Footage ftg;
    wrd::DeepEye::FTG_retrieve(ftg, wrd::FTG::DEC_14_2049);
    wrd::DeepEye::play(ftg);

    std::cin.get();
}