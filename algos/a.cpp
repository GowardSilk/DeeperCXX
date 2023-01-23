#include <ImageStream.hpp>

int main() {

    // wrd::Image img = wrd::Image({
    //     {wrd::Color::BLACK, wrd::Color::WHITE},
    //     {wrd::Color::BLACK, wrd::Color::RED},
    //     {wrd::Color::WHITE, wrd::Color::WHITE},
    //     {wrd::Color::BLACK, wrd::Color::WHITE},
    //     {wrd::Color::BLACK, wrd::Color::WHITE},
    //     {wrd::Color::BLACK, wrd::Color::WHITE},
    //     {wrd::Color::BLACK, wrd::Color::YELLOW},
    //     {wrd::Color::BLACK, wrd::Color::WHITE},
    //     {wrd::Color::BLACK, wrd::Color::WHITE},
    //     {wrd::Color::WHITE, wrd::Color::WHITE},
    //     {wrd::Color::BLACK, wrd::Color::WHITE},
    //     {wrd::Color::BLACK, wrd::Color::WHITE},
    //     {wrd::Color::BLACK, wrd::Color::WHITE},
    //     {wrd::Color::WHITE, wrd::Color::BLUE},
    // });
    // imgstream::render(img, "ImageSkuska.bmp");
    wrd::Image img2;
    imgstream::read(img2, "ImageSkuska.bmp");
    imgstream::render(img2, "ImageSkuskaAfter.bmp");
    return 0;
}