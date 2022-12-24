#include "Footage.hpp"

int main() {
    //create plain footage of 2x6 images
    wrd::Footage ftg(10, wrd::Image(Vector2sz(2, 6)));
    //iterate through footage
    //  set images to alternate
    //  ftg anatomy:
    //       0       1          0       1
    //  0    BLACK-WHITE ==> 0  WHITE-BLACK
    //  1    WHITE-BLACK ==> 1  BLACK-WHITE
    //  2    BLACK-WHITE ==> 2  WHITE-BLACK
    //  3    WHITE-BLACK ==> 3  BLACK-WHITE
    //  4    BLACK-WHITE ==> 4  WHITE-BLACK
    //  5    WHITE-BLACK ==> 5  BLACK-WHITE
    wrd::Image img1(Vector2sz(2, 6)), img2(Vector2sz(2, 6));
    wrd::Pixel pxl1, pxl2;
    for(unsigned y = 0; y < 6; y++) {
        if(y % 2 == 0) {
            pxl1 = wrd::Pixel(wrd::Color::BLACK);
            pxl2 = wrd::Pixel(wrd::Color::WHITE);
        }
        else {
            pxl1 = wrd::Pixel(wrd::Color::WHITE);
            pxl2 = wrd::Pixel(wrd::Color::BLACK);
        }
        for(unsigned x = 0; x < 2; x++) {
            if(x % 2 == 0) {
                img1.setPixel(Vector2u(x, y), pxl1);
            }
            else {
                img2.setPixel(Vector2u(x, y), pxl2);
            }
        }
    }
    for(unsigned t = 0; t < ftg.getTimeDuration(); t++) {
        if(t % 2 == 0)
            ftg.setImage(t, img1);
        else
            ftg.setImage(t, img2);
    }
    //
    for(unsigned t = 0; t < ftg.getTimeDuration(); t++) {
        std::cout << "second: " << t+1 << "\n";
        wrd::Image i_temp = ftg.getImage(t);
        for(unsigned y = 0; y < i_temp.getResolution().y; y++) {
            for(unsigned x = 0; x < i_temp.getResolution().x; x++) {
                printf("[%d][%d]", y, x);
                std::cout << i_temp.getPixel(Vector2u(x, y)).getRGB() << "\n";
            }
        }
    }
    return DEEPER;
}