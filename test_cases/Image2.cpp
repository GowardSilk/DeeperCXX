#include "../DEEP_EYE.hpp"
#include "../Image.hpp"
#include <random>

wrd::Image image_function(wrd::Image& img) {
    //"BLACK BOX"
    for(std::size_t y = 0; y < img.getResolution().y; y++) {
        for(std::size_t x = 0; x < img.getResolution().x; x++) {
            if(x % 2 == 0) 
                img.setPixel(Vector2u(x, y), wrd::Pixel(0, 0, 0));
            else
                img.setPixel(Vector2u(x, y), wrd::Pixel(255, 255, 255));
        }
    }
    return img;
}

wrd::Image getRND() {
    //get random resolution
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_int_distribution<int> dis(4, 500);
    Vector2sz resolution(dis(gen), dis(gen));

    //create plain image
    wrd::Image img(resolution);
    
    for(std::size_t y = 0; y < img.getResolution().y; y++) {
        for(std::size_t x = 0; x < img.getResolution().x; x++) {
            if(x % 2 != 0)
                img.setPixel(Vector2u(x, y), wrd::Pixel(0, 0, 0));
            else
                img.setPixel(Vector2u(x, y), wrd::Pixel(wrd::Color::WHITE));
        }
    }

    return img;
}

int main() {

    std::ofstream wf("Image2.dat", std::ios::out | std::ios::binary);
    if(!wf) {
        std::cout << "cannot open file!\n";
        exit(EXIT_FAILURE);
    }

    //for each test case...
    for(unsigned i = 0; i < 10; i++) {
        //generate input
        wrd::Image input = getRND();
        //wrtie input
        wf.write(reinterpret_cast<char *>(&input), sizeof(wrd::Image));
        //generate expected output
        wrd::Image expected = image_function(input);
        //write expected output
        wf.write(reinterpret_cast<char *>(&expected), sizeof(wrd::Image));
    }

    wf.flush();
    wf.close();
    if(!wf.good()) {
        std::cout << "error occurred at handling time!\n";
    }

    std::ifstream rf("Image2.dat", std::ios::in | std::ios::binary);
    if(!rf) {
        std::cout << "cannot open file!\n";
        exit(EXIT_FAILURE);
    }

    //for each test case...
    for(unsigned i = 0; i < 10; i++) {
        //generate input
        wrd::Image input;
        //wrtie input
        rf.read(reinterpret_cast<char *>(&input), sizeof(wrd::Image));
        for(std::size_t y = 0; y < input.getResolution().y; y++) {
            for(std::size_t x = 0; x < input.getResolution().x; x++) {
                std::cout << input.getPixel(Vector2u(x, y)).getRGB() << std::endl;
            }
        }
        //generate expected output
        wrd::Image expected;
        //write expected output
        rf.read(reinterpret_cast<char *>(&expected), sizeof(wrd::Image));
        for(std::size_t y = 0; y < expected.getResolution().y; y++) {
            for(std::size_t x = 0; x < expected.getResolution().x; x++) {
                std::cout << expected.getPixel(Vector2u(x, y)).getRGB() << std::endl;
            }
        }
    }

    rf.close();
    if(!rf.good()) {
        std::cout << "error occurred at handling time!\n";
    }

    return DEEPER;
}