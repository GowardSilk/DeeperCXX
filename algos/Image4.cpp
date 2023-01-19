#include <DEEP_EYE.hpp>

void pxl_from_HWB_to_RGB(wrd::Pixel& hwb) {
    int h = hwb.getRGB()._triplet_unit_1 % 360;
    int w = hwb.getRGB()._triplet_unit_2;
    int b = hwb.getRGB()._triplet_unit_3;

    int r, g, bl;
    if (h < 120) {
        r = b + (h * w / 60);
        g = b + (w * (120 - h) / 60);
        bl = b;
    } 
    else if (h < 240) {
        r = b + (w * (240 - h) / 60);
        g = b + (h * w / 60);
        bl = b;
    } 
    else {
        r = b;
        g = b + (w * (360 - h) / 60);
        bl = b + (h * w / 60);
    }

    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    bl = std::clamp(bl, 0, 255);

    hwb.setRGB(r, g, bl);
}


int main() {

    wrd::Image img;

    wrd::DeepEye::IMG_download(img, wrd::JPEG::SP_19_2049);

    Benchmark tester;
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
                    pxl_from_HWB_to_RGB(pxl);
                }
            );
        }
    );

    wrd::DeepEye::render(img);

}