#ifndef DEEP_EYE_HPP
#define DEEP_EYE_HPP

#include "Footage.hpp"
#include "LogGen.hpp"
#include "ImageStream.hpp"

static std::string fileDest;

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
                    fileDest = "img_before/img1.bmp";
                    imgstream::read(img, "img_before/img1.bmp");
                    break;
                case wrd::JPEG::M_5_2049:
                //
                    //fileDest = "";
                    imgstream::read(img, "");
                    break;
                case wrd::JPEG::JL_1_2049:
                //
                    //fileDest = "";
                    imgstream::read(img, "");
                    break;
                case wrd::JPEG::SP_19_2049:
                //
                    //fileDest = "";
                    imgstream::read(img, "");
                    break;
                default:
                    std::cout << "JPEG does not exist!\n";
                    break;
                }
                return;
            }
            //  used to "extract" log
            static void LOG_extract(wrd::Log& log, wrd::TXT log_name) {
                LogGen lg;
                switch (log_name)
                {
                case wrd::TXT::JNR_2_2049:
                    lg.read("Log1.dat", log);
                    break;
                case wrd::TXT::FBR_20_2049:
                    lg.read("Log2.dat", log);
                    break;
                case wrd::TXT::FBR_24_2049_10:
                    lg.read("Log3.dat", log);
                    break;
                case wrd::TXT::FBR_26_2049_11:
                    lg.read("Log4.dat", log);
                    break;
                case wrd::TXT::FBR_25_2049_23:
                    lg.read("Log5.dat", log);
                    break;
                case wrd::TXT::FBR_26_2049_10:
                    lg.read("Log6.dat", log);
                    break;
                case wrd::TXT::FBR_26_2049_18:
                    lg.read("Log7.dat", log);
                    break;
                case wrd::TXT::FBR_26_2049_4:
                    lg.read("Log8.dat", log);
                    break;
                case wrd::TXT::FBR_26_2049_5:
                    lg.read("Log9.dat", log);
                default:
                    throw new std::exception("No such file exists!");
                }
            }
            //  used to "retrieve" footage
            static void FTG_retrieve(wrd::Footage& ftg, wrd::FTG ftg_name) {
                ftg.setTimeDuration(3);
                for(int i = 1; i <= ftg.getTimeDuration(); i++) {
                    wrd::Image img;
                    fileDest = "ftg_before/img" + std::to_string(i) + ".bmp";
                    imgstream::read(img, fileDest.c_str());
                    ftg.setImage(i-1, img);
                }
            }
            //!download functions

            //upload functions
            //  used to send image to the website
            static void render(wrd::Image& img) {
                fileDest = "img_after/img1.bmp";
                imgstream::render(img, fileDest.c_str());
                JSON_stream.write("image", fileDest.c_str());
            }
            //  used to send log to the website
            static void read(wrd::Log& log) {
                JSON_stream.write("log", log.getText());
                std::cout << log.getText();
            }
            //  used to send a footage
            static void play(wrd::Footage& ftg) {
                int i = 1;
                for(wrd::Footage::Iterator it = ftg.begin(); it != ftg.end(); it++) {
                    fileDest = "ftg_after/img" + std::to_string(i) + ".bmp";
                    imgstream::render(*it, fileDest.c_str());
                    i++;
                }
                JSON_stream.write("ftg_after", fileDest.c_str());
            }
            //!upload functions
    };
} //!namespace Warden

#endif