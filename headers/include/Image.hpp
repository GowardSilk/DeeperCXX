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
        BLACK, WHITE, RED, GREEN, BLUE, YELLOW
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
                case Color::YELLOW:
                    setRGB(255, 255, 0);
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
            void setRGB(wrd::Color clr) {
                switch (clr)
                {
                case Color::BLACK:
                    setRGB(0, 0, 0);
                    break;
                case Color::WHITE:
                    setRGB(255, 255, 255);
                    break;
                case Color::RED:
                    setRGB(255, 0, 0);
                    break;
                case Color::GREEN:
                    setRGB(0, 255, 0);
                    break;
                case Color::BLUE:
                    setRGB(0, 0, 255);
                    break;
                case Color::YELLOW:
                    setRGB(255, 255, 0);
                    break;
                }
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
            triplet<int> getRGB() const {
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
            //!member data
            void check_bounds(Vector2u pos) {
                if(pos.y >= pixel_container.size() || pos.x >= pixel_container[0].size()) {
                    std::cout << "Image::check_bounds(Vector2u, Pixel): invalid size!\n";
                    std::cout << "[x, y] = {" << pos.x << "," << pos.y << "}\n";
                    std::cout << "size of Image = {" <<  pixel_container[0].size() << "," << pixel_container.size() << "}\n";
                    exit(1);
                }
            }
            void check_bounds(unsigned x, unsigned y) {
                if(y >= pixel_container.size() || x >= pixel_container[0].size()) {
                    std::cout << "Image::check_bounds(unsigned x, unsigned y, Pixel): invalid size!\n";
                    std::cout << "[x, y] = {" << x << "," << y << "}\n";
                    std::cout << "size of Image = {" <<  pixel_container[0].size() << "," << pixel_container.size() << "}\n";
                    exit(1);
                }
            }
        public:
            //member data
            struct Iterator 
                : public std::iterator<std::forward_iterator_tag, std::vector<Pixel>, std::vector<Pixel>> 
            {               
                public:
                    //iterator tags
                    typedef std::forward_iterator_tag   iterator_category;
                    typedef std::ptrdiff_t              difference_type;

                    //PIXEL VECTOR height pointer
                    typedef std::vector<wrd::Pixel>     _H_value_type;
                    typedef _H_value_type*              _H_pointer;   //std::vector<Pixel>*
                    typedef _H_value_type&              _H_reference; //std::vector<Pixel>&

                    //PIXEL VECTOR width pointer
                    // using _W_value_type     = Pixel;
                    // using _W_pointer        = _W_value_type*; //Pixel*
                    // using _W_reference      = _W_value_type&; //Pixel&
                    //!iterator tags

                    //constructor
                    Iterator() = default;
                    Iterator(_H_pointer h_ptr /*_W_pointer w_ptr*/) 
                        : m_H_ptr(h_ptr) {}
                        /*m_W_ptr(w_ptr)*/
                    //!constructor

                    //supporting all necessary operations
                    //for forward iterator
                    //operators
                    _H_reference operator*() const { return *m_H_ptr; }
                    _H_pointer operator->() { return m_H_ptr; }
                    Iterator& operator++() { m_H_ptr++; return *this; }
                    Iterator operator++(int) { 
                        Iterator tmp = *this;
                        ++(*this);
                        return tmp;
                    }
                    Iterator operator+(unsigned i) {
                        return m_H_ptr + i;
                    }
                    //const _H_value_type operator+(const Iterator& lhs) const { return m_H_ptr + lhs.m_H_ptr; }
                    //_H_value_type operator-(const Iterator& lhs) const { return m_H_ptr - lhs.m_H_ptr; }
                    //  equality
                    bool operator==(const Iterator& it) {
                        return m_H_ptr == it.m_H_ptr;
                    }
                    bool operator!=(const Iterator& it) {
                        return m_H_ptr != it.m_H_ptr;
                    }
                    //  !equality
                    //!operators

                private:
                    //_W_pointer m_W_ptr;
                    _H_pointer m_H_ptr;
            };
            //!member data
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
                : resolution(l.begin()->size(), l.size()),
                  pixel_container(l) {}
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
                check_bounds(x, y);
                pixel_container[y][x] = pxl;
            }
            void setPixel(Vector2u position, Pixel pxl) {
                check_bounds(position);
                pixel_container[position.y][position.x] = pxl;
            }
            //get functions
            Vector2sz getResolution() {
                return this->resolution;
            }
            Pixel getPixel(Vector2u position) {
                //printf("[%d][%d]", position.y, position.x);
                check_bounds(position);
                return pixel_container[position.y][position.x];
            }
            Pixel getPixel(unsigned int x, unsigned int y) {
                //printf("[%d][%d]", y, x);
                check_bounds(x, y);
                return pixel_container[y][x];
            }
            Iterator begin() {
                return Iterator(
                    //for height pointer, point to the first vector
                    &pixel_container[0]
                    //point to the first element of the first vector
                    //&pixel_container[0][0]
                );
            }
            std::vector<wrd::Pixel>::iterator obegin(unsigned pos = 0) {
                return this->pixel_container[pos].begin();
            }
            Iterator end() {
                int last = pixel_container.size()-1;
                return Iterator(
                    //for height pointer, point to the last vector
                    &pixel_container[last]
                    //point to the last element of the last vector
                    //&pixel_container[last][pixel_container.at(last).size()-1]
                );
            }
            typedef std::vector<uint8_t>::iterator vec_uc_it;
            typedef std::vector<wrd::Pixel>::iterator vec_pxl_it;
            void append(vec_uc_it beg, vec_uc_it end,  vec_pxl_it dest) {
                std::vector<wrd::Pixel> vec_pxl;
                for(vec_uc_it it = beg; it < end; it = std::next(it, 3)) {
                      vec_pxl.push_back(
                        wrd::Pixel(*it, *(it+1), *(it+2))
                      );
                }
                std::move(vec_pxl.begin(), vec_pxl.end(), dest);
            }
    }; //!Image

} //!namespace Warden

#endif //!IMAGE_HPP