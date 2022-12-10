#ifndef FOOTAGE_HPP
#define FOOTAGE_HPP

#include "Image.hpp"

namespace wrd {
    class Footage {
        private:
            std::vector<Image> img_container;
            std::size_t time_duration;
        public:
            //constructors
            Footage() { //default
                setTimeDuration(0);
            }
            Footage(std::size_t time_duration) {
                setTimeDuration(time_duration);
            }
            Footage(std::size_t time_duration, wrd::Image img_data) {
                setTimeDuration(time_duration, img_data);
            }
            //set functions
            void setTimeDuration(std::size_t time) {
                this->time_duration = time;
                img_container.resize(time);
            }
            void setTimeDuration(std::size_t time, wrd::Image img) {
                this->time_duration = time;
                img_container.resize(time, img);
            }
            void setImage(unsigned position, wrd::Image img) {
                if(position >= this->time_duration) {
                    std::cout << "Footage::setImage(unsigned, wrd::Image): position invalid!\n";
                    exit(1);
                }
                else {
                    this->img_container.at(position) = img;
                }
            }
            //get functions
            std::size_t getTimeDuration() {
                return this->time_duration;
            }
            wrd::Image getImage(unsigned position) {
                return this->img_container.at(position);
            }
    }; //!class Footage
} //!namespace Warden

#endif //!FOOTAGE_HPP