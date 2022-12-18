#ifndef DEEP_EYE_HPP
#define DEEP_EYE_HPP

#include "Image.hpp"
#include "Log.hpp"
#include "Footage.hpp"

typedef unsigned char uchar_t;
typedef unsigned int uint32_t;
typedef unsigned short int uint16_t;
typedef signed int int32_t;
typedef signed short int int16_t;

const int MIN_RGB=0;
const int MAX_RGB=255;
const int BMP_MAGIC_ID=2;

namespace wrd {

    struct bmpfile_magic
    {
        uchar_t magic[BMP_MAGIC_ID];
    };

    struct bmpfile_header
    {
        uint32_t file_size;
        uint16_t creator1;
        uint16_t creator2;
        uint32_t bmp_offset;
    };

    struct bmpfile_dib_info
    {
        uint32_t header_size;
        int32_t width;
        int32_t height;
        uint16_t num_planes;
        uint16_t bits_per_pixel;
        uint32_t compression;
        uint32_t bmp_byte_size;
        int32_t hres;
        int32_t vres;
        uint32_t num_colors;
        uint32_t num_important_colors;
    };

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
                std::ofstream file("test.bmp", std::ios::out | std::ios::binary);

                if(file.is_open()) {
                    wrd::bmpfile_magic magic;
                    magic.magic[0] = 'B';
                    magic.magic[1] = 'M';
                    file.write((char*)(&magic), sizeof(magic));

                    wrd::bmpfile_header header = { 0 };
                    header.bmp_offset = sizeof(bmpfile_magic) + sizeof(bmpfile_header) + sizeof(bmpfile_dib_info);
                    header.file_size = header.bmp_offset + (img.getResolution().y * 3 + img.getResolution().x % 4) * img.getResolution().y;
                    file.write((char*)(&header), sizeof(header));

                    wrd::bmpfile_dib_info dib_info = { 0 };
                    dib_info.header_size = sizeof(bmpfile_dib_info);
                    dib_info.width = img.getResolution().x;
                    dib_info.height = img.getResolution().y;
                    dib_info.num_planes = 1;
                    dib_info.bits_per_pixel = 24;
                    dib_info.compression = 0;
                    dib_info.bmp_byte_size = 0;
                    dib_info.hres = 2835;
                    dib_info.vres = 2835;
                    dib_info.num_colors = 0;
                    dib_info.num_important_colors = 0;
                    file.write((char*)(&dib_info), sizeof(dib_info));

                    for(std::size_t y = 0; y < img.getResolution().y; y++) {
                        for(std::size_t x = 0; x < img.getResolution().x; x++) {
                            wrd::Pixel pixel = img.getPixel(Vector2u(x, y));
                            // fwrite(&image[j][i][2], 1, 1, fp);
                            // fwrite(&image[j][i][1], 1, 1, fp);
                            // fwrite(&image[j][i][0], 1, 1, fp);
                            //BGR
                            file.put((uchar_t)pixel.getRGB()._triplet_unit_3);
                            file.put((uchar_t)pixel.getRGB()._triplet_unit_2);
                            file.put((uchar_t)pixel.getRGB()._triplet_unit_1);
                        }
                        for (int i = 0; i < img.getResolution().x % 4; i++)
                        {
                            file.put(0);
                        }
                    }
                    file.close();
                }
                return;
            }
            //  used to send log to the website
            static void read(wrd::Log& log) {
                return;
            }
    };
} //!namespace Warden

#endif