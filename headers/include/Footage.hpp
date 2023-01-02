#ifndef FOOTAGE_HPP
#define FOOTAGE_HPP

#include "Image.hpp"

namespace wrd {

    enum class FTG {
        DEC_14_2049
    };

    class Footage {
        private:
            //member_data
            std::vector<Image> img_container;
            std::size_t time_duration;
            //!member data
        public:
        #pragma region ITERATOR
            //member data
            struct Iterator
            {
                //iterator tags
                using iterator_category = std::forward_iterator_tag;
                using difference_type   = std::ptrdiff_t;

                //PIXEL VECTOR height pointer
                using value_type     = Image;
                using pointer        = value_type*; //Image*
                using reference      = value_type&; //Image&

                //constructor
                Iterator(pointer _ptr) 
                    : m_ptr(_ptr) {}
                //!constructor

                //supporting all necessary operations
                //for forward iterator
                //operators
                reference operator*() const { return *m_ptr; }
                pointer operator->() { return m_ptr; }
                Iterator& operator++() { m_ptr++; return *this; }
                Iterator operator++(int) { 
                    Iterator tmp = *this;
                    ++(*this);
                    return tmp;
                }
                bool operator==(const Iterator& it) {
                    return m_ptr == it.m_ptr;
                }
                bool operator!=(const Iterator& it) {
                    return m_ptr != it.m_ptr;
                }
                //!operators

                private:
                    pointer m_ptr;
            };
            //!member data
            Iterator begin() { return Iterator(&img_container[0]); }
            Iterator end() { return Iterator(&img_container[img_container.size()-1]); }
        #pragma endregion //!ITERATOR
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