#include <DEEP_EYE.hpp>

void rotate(wrd::Image& img) {
    Vector2u begin(0,0), end(img.getResolution().x, img.getResolution().y);
    for(auto y = begin.y; y < end.y; y++) {
        for(auto x = begin.x; x < end.x; x++) {
            wrd::Pixel pxl1 = img.getPixel(Vector2u(x, y));
            wrd::Pixel pxl2 = img.getPixel(Vector2u(end.x - x, end.y - y));
            img.setPixel(Vector2u(x, y), pxl2);
            img.setPixel(Vector2u(end.x - x, end.y - y), pxl1);
        }
    }
}

void rotate(wrd::Image& img, Vector2u begin, Vector2u end) {
    //"rotate" image by 180 deg
    for(unsigned y = begin.y; y < end.y; y++) {
        for(unsigned x = begin.x; x < end.x; x++) {
            wrd::Pixel temp = img.getPixel(Vector2u(end.x - x, end.y - y));
            img.setPixel(Vector2u(end.x - x, end.y - y), img.getPixel(Vector2u(x, y)));
            img.setPixel(Vector2u(x, y), temp);
        }
    }
}

void fill(wrd::Image &img, Vector2u begin, Vector2u end, wrd::Color clr) {
    for(unsigned y = begin.y; y < end.y; y++) {
        for(unsigned x = begin.x; x < end.x; x++) {
            img.setPixel(Vector2u(x, y), wrd::Pixel(clr));
        }
    }
}

int main() {

    wrd::Image img;

    imgstream::read(img, "circle1.bmp");

    //split that image into 4 smaller images and rotate each of them
    //  check boundaries
    //      for height
    if(img.getResolution().y % 2 != 0) {
        int count = (img.getResolution().y % 2);
        img.setResolution(Vector2sz(img.getResolution().x, img.getResolution().y + count));
        while(count > 0) {
            for(uint32_t i = 0; i < img.getResolution().x; i++) {
                img.setPixel(Vector2u(i, img.getResolution().y-count), wrd::Pixel(wrd::Color::BLACK));
            }
            count--;
        }
    }
    //      for width
    if(img.getResolution().x % 2 != 0) {
        int count = (img.getResolution().x % 2);
        img.setResolution(Vector2sz(img.getResolution().x + count, img.getResolution().y));
        while(count > 0) {
            for(uint32_t i = 0; i < img.getResolution().x; i++) {
                img.setPixel(Vector2u(i, img.getResolution().y-count), wrd::Pixel(wrd::Color::BLACK));
            }
            count--;
        }
    }
    //rotate 4 parts
    //  left upper corner
    rotate(img,  Vector2u(0, img.getResolution().y/2), Vector2u(img.getResolution().x/2, img.getResolution().y));
    //fill(img,  Vector2u(0, img.getResolution().y/2), Vector2u(img.getResolution().x/2, img.getResolution().y), wrd::Color::BLUE);
    //  right upper corner
    rotate(img, Vector2u(img.getResolution().x/2, img.getResolution().y/2), Vector2u(img.getResolution().x, img.getResolution().y));
    //fill(img, Vector2u(img.getResolution().x/2, img.getResolution().y/2), Vector2u(img.getResolution().x, img.getResolution().y), wrd::Color::GREEN);
    //  left bottom corner
    rotate(img, Vector2u(0, 0), Vector2u(img.getResolution().x/2, img.getResolution().y/2));
    //fill(img, Vector2u(0, 0), Vector2u(img.getResolution().x/2, img.getResolution().y/2), wrd::Color::BLACK);
    //  right bottom corner
    rotate(img, Vector2u(img.getResolution().x/2, 0), Vector2u(img.getResolution().x, img.getResolution().y/2));
    //fill(img, Vector2u(img.getResolution().x/2, 0), Vector2u(img.getResolution().x, img.getResolution().y/2), wrd::Color::YELLOW);
    imgstream::render(img, "Image3.bmp");
}