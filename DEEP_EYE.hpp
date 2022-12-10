#ifndef DEEP_EYE_HPP
#define DEEP_EYE_HPP

#include "Image.hpp"
#include "Log.hpp"
#include "Footage.hpp"

namespace wrd {
    class DeepEye {
        private:
        public:
            //download functions
            //  used to "download" image preset
            static void IMG_download(wrd::Image& img, wrd::JPEG img_name) {
                switch (img_name)
                {
                case wrd::JPEG::MRCH_2_2049:
                //
                    break;
                case wrd::JPEG::M_5_2049:
                //
                    img = wrd::Image(Vector2sz(2, 2));
                    for(std::size_t y = 0; y < img.getResolution().y; y++) {
                        for(std::size_t x = 0; x < img.getResolution().x; x++) {
                            if(x % 2 == 0)
                                img.setPixel(Vector2u(x, y), wrd::Pixel(255, 255, 255));
                            else
                                img.setPixel(Vector2u(x, y), wrd::Pixel(0, 0, 0));
                        }
                    }
                    break;
                case wrd::JPEG::JL_1_2049:
                //
                    img = wrd::Image({
                        {wrd::Pixel(wrd::Color::BLACK), wrd::Pixel(wrd::Color::WHITE), wrd::Pixel(wrd::Color::BLACK)},
                        {wrd::Pixel(wrd::Color::WHITE), wrd::Pixel(wrd::Color::BLACK), wrd::Pixel(wrd::Color::WHITE)},
                        {wrd::Pixel(wrd::Color::BLACK), wrd::Pixel(wrd::Color::WHITE), wrd::Pixel(wrd::Color::WHITE)}
                    });
                    
                    break;
                case wrd::JPEG::SP_19_2049:
                //
                    break;
                default:
                    std::cout << "JPEG does not exist!\n";
                    break;
                }
                return;
            }
            //  used to "extract" log
            static void LOG_extract(wrd::Log& log, wrd::TXT log_name) {
                switch (log_name)
                {
                case wrd::TXT::JNR_2_2049:
                    break;
                
                default:
                    break;
                }
            }
            //!download functions

            //upload functions
            //  used to send image to the website
            static void render(wrd::Image& img) {
                return;
            }
            //  used to send log to the website
            static void read(wrd::Log& log) {
                return;
            }
    };
} //!namespace Warden

#endif