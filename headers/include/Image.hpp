#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "DeepMain.hpp"

#define PIXEL_VECTOR std::vector<std::vector<wrd::Pixel>>

namespace wrd {

    struct RGBA {
        triplet<int> rgb;
        int alpha;
    };

    enum class Color {
        BLACK, WHITE, RED, GREEN, BLUE
    };

    enum class JPEG {
        MRCH_2_2049, M_5_2049, JL_1_2049, SP_19_2049
    };

    class Pixel {
        private:
            //member data
            triplet<int> rgb;
            int alpha;
        public:
            //default constructor
            Pixel() {
                this->rgb = triplet<int>(
                    /*._triplet_unit_1*/ 0,
                    /*._triplet_unit_1*/ 0,
                    /*._triplet_unit_1*/ 0
                );
                this->alpha = 255;
            }
            //constructor
            //  with r,g,b as integer parameters and
            //  opaque as default value
            Pixel(int r, int g, int b, int alpha = 255) {
                setRGBA(r, g, b, alpha);
            }
            Pixel(Color clr) {
                switch (clr)
                {
                case Color::BLACK:
                    setRGBA(0, 0, 0);
                    break;
                case Color::WHITE:
                    setRGBA(255, 255, 255);
                    break;
                case Color::RED:
                    setRGBA(255, 0, 0);
                    break;
                case Color::GREEN:
                    setRGBA(0, 255, 0);
                    break;
                case Color::BLUE:
                    setRGBA(0, 0, 255);
                    break;
                }
            } 
            //constructor
            //  with r,g,b as triplet parameter and
            //  opaque as default value
            Pixel(triplet<int> rgb, int alpha = 255) {
                setRGBA(rgb, alpha);
            }
            //constructor
            //  with RGBA container parameter
            Pixel(RGBA rgba_container) {
                setRGBA(rgba_container.rgb, rgba_container.alpha);
            }
            //set functions
            void setOpaque(int alpha = 255) {
                this->alpha = alpha;
            }
            void setRGB(int r, int g, int b) {
                this->rgb = triplet<int>(
                    /*._triplet_unit_1*/ r,
                    /*._triplet_unit_1*/ g,
                    /*._triplet_unit_1*/ b
                );
            }
            void setRGB(triplet<int> rgb) {
                this->rgb = rgb;
            }
            void setRGBA(int r, int g, int b, int alpha = 255) {
                setRGB(r, g, b);
                this->alpha = alpha;
            }
            void setRGBA(triplet<int> rgb, int alpha = 255) {
                setRGB(rgb);
                this->alpha = alpha;
            }
            //get functions
            int getOpaque() {
                return this->alpha;
            }
            triplet<int> getRGB() {
                return this->rgb;
            }
            RGBA getRGBA() {
                struct RGBA con = {
                    .rgb = this->rgb,
                    .alpha = this->alpha
                };
                return con;
            }
    }; //!Pixel
    class Image {
        private:
            //member data
            Vector2sz resolution;
            PIXEL_VECTOR pixel_container;
        public:
            //default constructor -> blank image
            Image() {
                resolution = Vector2sz(0, 0);
                pixel_container = PIXEL_VECTOR(0, std::vector<Pixel>(0));
            }
            //constructor
            //  width & height as parameters
            Image(std::size_t width, std::size_t height) {
                setResolution(width, height); 
            }
            //constructor
            //  Vector2 as parameter (x->width, y->height)
            Image(Vector2sz resolution) {
                setResolution(resolution);
            }
            //constructor
            //  
            Image(std::initializer_list<std::vector<Pixel>> l) 
                : pixel_container(l),
                  resolution(l.begin()->size(), l.size()) {}
            //destructor
            ~Image() = default;
            //set functions
            void setResolution(std::size_t width, std::size_t height) {
                this->resolution = Vector2sz(width, height);
                //resize existing vector
                pixel_container.resize(height, std::vector<Pixel>(width));
            }
            void setResolution(Vector2sz resolution) {
                this->resolution = resolution;
                //create new PIXEL_VECTOR of size:
                //  resolution.y = ROW_COUNT
                //  resolution.x = COL_COUNT
                pixel_container.resize(resolution.y, std::vector<Pixel>(resolution.x));
                //std::cout << "width = " << pixel_container.at(0).size() << " height = " << pixel_container.size() << std::endl;
            }
            void setPixel(unsigned int x, unsigned int y, Pixel pxl) {
                if(y > pixel_container.size() || x > pixel_container.at(0).size()) {
                    std::cout << "Image::setPixel(int, int, Pixel): invalid size!\n";
                    exit(1);
                }
                else {
                    pixel_container[y][x] = pxl;
                }
            }
            void setPixel(Vector2u position, Pixel pxl) {
                //std::cout << pxl.getRGB()._triplet_unit_1 << "," << pxl.getRGB()._triplet_unit_2 << "," << pxl.getRGB()._triplet_unit_3 << std::endl;
                if(position.y >= pixel_container.size() || position.x >= pixel_container.at(0).size()) {
                    std::cout << "Image::setPixel(Vector2u, Pixel): invalid size!\n";
                    std::cout << "Vector2u = {" << position.x << "," << position.y << "}\n";
                    std::cout << "size of Image = {" <<  pixel_container[0].size() << "," << pixel_container.size() << "}\n";
                    exit(1);
                }
                pixel_container[position.y][position.x] = pxl;
            }
            //get functions
            Vector2sz getResolution() {
                return this->resolution;
            }
            Pixel getPixel(Vector2u position) {
                //printf("[%d][%d]", position.y, position.x);
                return pixel_container[position.y][position.x];
            }
            Pixel getPixel(unsigned int x, unsigned int y) {
                //printf("[%d][%d]", y, x);
                return pixel_container[y][x];
            }
    }; //!Image
} //namespace Warden

#endif //!IMAGE_HPP