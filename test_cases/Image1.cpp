#include <DEEP_EYE.hpp>

void image_function(wrd::Image& img) {
    
}

int main() {

    wrd::Image img;
    imgstream::read(img, "circle1.bmp");
    imgstream::render(img, "Image1.bmp");

}