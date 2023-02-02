#ifndef IMAGE_STREAM_HPP
#define IMAGE_STREAM_HPP

#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include "Image.hpp"
#include "Benchmark.hpp"

#include <thread>

const int MIN_RGB=0;
const int MAX_RGB=255;
const int BMP_MAGIC_ID=2;

namespace imgstream {
    
    struct bmpfile_magic
    {
        unsigned char magic[BMP_MAGIC_ID];
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

    static void render(wrd::Image& img, const char* fileDest) {
        std::ofstream file(fileDest, std::ios::out | std::ios::binary);
        if(file.is_open()) {
            bmpfile_magic magic;
            magic.magic[0] = 'B';
            magic.magic[1] = 'M';
            file.write(reinterpret_cast<char*>(&magic), sizeof(magic));

            bmpfile_header header = { 0 };
            header.bmp_offset = sizeof(bmpfile_magic) + sizeof(bmpfile_header) + sizeof(bmpfile_dib_info);
            header.file_size = header.bmp_offset + (img.getResolution().y * 3 + img.getResolution().x % 4) * img.getResolution().y;
            file.write(reinterpret_cast<char*>(&header), sizeof(header));

            bmpfile_dib_info dib_info = { 0 };
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
            file.write(reinterpret_cast<char*>(&dib_info), sizeof(dib_info));

            for(std::size_t y = 0; y < img.getResolution().y; y++) {
                for(std::size_t x = 0; x < img.getResolution().x; x++) {
                    wrd::Pixel pixel = img.getPixel(Vector2u(x, y));
                    //BGR
                    file.put((unsigned char)pixel.getRGB()._triplet_unit_3);
                    file.put((unsigned char)pixel.getRGB()._triplet_unit_2);
                    file.put((unsigned char)pixel.getRGB()._triplet_unit_1);
                }
                for (int i = 0; i < img.getResolution().x % 4; i++)
                    file.put(0);
            }
            file.close();
        }
    }

    static void read(wrd::Image& img, const char* fileDest) {
        Benchmark test;
        std::ifstream file = std::ifstream(fileDest, std::ios::in | std::ios::binary);

        if(!file.is_open()) {
            std::cout << "Bitmap file does not exist or is already opened by another program!\n";
            exit(1);
        }

        //check 'B', 'M' identifier
        bmpfile_magic magic;
        file.read(reinterpret_cast<char*>(&magic), sizeof(magic));
        if(magic.magic[0] != 'B' || magic.magic[1] != 'M') {
            std::cout << "bitmap is corrupted!";
            exit(EXIT_FAILURE);
        }

        std::ios::sync_with_stdio(false);

        bmpfile_header header;
        file.read(reinterpret_cast<char*>(&header), sizeof(header));
        std::cout << "bmpfile_header---- \n"
                << "file_size : " << header.file_size << "\n"
                << "creator1 : " << header.creator1 << "\n"
                << "creator2 : " << header.creator2 << "\n"
                << "offset : " << header.bmp_offset  << "\n"
                << "offset expected : " << sizeof(bmpfile_dib_info) + sizeof(bmpfile_header) + sizeof(bmpfile_magic) << '\n';

        bmpfile_dib_info dib_info;
        file.read(reinterpret_cast<char*>(&dib_info), sizeof(dib_info));
        std::cout << "bmpfile_dib_info---- \n" <<
            "header_size: " << dib_info.header_size << "\n" <<
            "width: " << dib_info.width << "\n" <<
            "height: " << dib_info.height << "\n" <<
            "num_planes: " << dib_info.num_planes << "\n" <<
            "bits_per_pixel: " << dib_info.bits_per_pixel << "\n" <<
            "compression: " << dib_info.compression << "\n" <<
            "bmp_byte_size: " << dib_info.bmp_byte_size << "\n" <<
            "hres: " << dib_info.hres << "\n" <<
            "vres: " << dib_info.vres  << "\n" <<
            "num_colors: " << dib_info.num_colors << "\n" <<
            "num_important_colors: " << dib_info.num_important_colors << "\n";
        if(dib_info.compression != 0) {
            std::cout << "Cannot read compressed img!";
            exit(1);
        }

//#define MT //--> not very efficient in the end -> not recommended to use
#ifdef MT
        std::streampos filepos = file.tellg();
        std::basic_filebuf<char>* filebuf = file.rdbuf();
        std::vector<uint8_t> buffer(dib_info.width*dib_info.height*3); // size -> width*height*RGB vals
        filebuf->pubseekpos(filepos);

        const auto read_block = [&](std::basic_filebuf<char>& filebuf, std::vector<unsigned char>& buffer, int start, int end) {
            filebuf.pubseekpos(start+filepos);
            filebuf.sgetn(reinterpret_cast<char*>(buffer.data()) + start, end - start);
        };

        //create a vector of threads
        std::vector<std::thread> threads;
        int num_threads = std::thread::hardware_concurrency();
        int block_size = buffer.size() / num_threads;

        for (int i = 0; i < num_threads; i++) {
            int start = (i * block_size);
            int end = ((i + 1) * block_size);
            if (i == num_threads - 1) {
                end = buffer.size();
            }
            threads.emplace_back(std::thread(read_block, std::ref(*filebuf), std::ref(buffer), start, end));
        }

        //wait for all threads to finish
        for (std::thread& thread : threads)
            thread.join();
        
        img = wrd::Image(dib_info.width, dib_info.height);
        unsigned width = dib_info.width*3;
        for(const uint8_t& ch : buffer) {
            std::cout << (int)ch;
        }
        std::cout << std::endl;
        for (int y = 0; y < dib_info.height; ++y) {

            std::vector<uint8_t>::iterator start_it, end_it;
            if(y == dib_info.height - 1) {
                start_it = buffer.begin() + y*dib_info.width*3; /*std::next(buffer.cbegin(), y*dib_info.width*3);*/
                end_it = start_it;
            }
            else {
                start_it = buffer.begin() + y*dib_info.width*3;
                end_it = buffer.begin() + (y+1)*dib_info.width*3;
            }

            img.append(start_it, end_it, img.obegin(y));

            for(unsigned x = 0; x < dib_info.width; x++) {
                std::cout << img.getPixel(x, y).getRGB() << ",";
            }
            std::cout << std::endl;
        }

        filebuf->close();
#else
        //initialize image for specific width/height
        img = wrd::Image(Vector2sz(dib_info.width, dib_info.height));
        for(int32_t y = 0; y < dib_info.height; y++) {
            for(int32_t x = 0; x < dib_info.width; x++) {
                img.setPixel(
                    Vector2u(x, y),
                    wrd::Pixel(file.get(), file.get(), file.get()) //BGR
                );
            }
            //ignore padding
            file.seekg(dib_info.width % 4, std::ios::cur);
        }
#endif //!MT
        if(file.good())
            std::cout << "[imgstream::read] img was successfully read!\n";
        else
            std::cout << "[imgstream::read] something wrong during reading!\n";
        file.close();
    }
}

#endif //!IMAGE_STREAM_HPP