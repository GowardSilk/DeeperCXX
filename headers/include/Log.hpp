#ifndef LOG_HPP
#define LOG_HPP

#include "DeepMain.hpp"

namespace wrd {

    enum class TXT {
        JNR_2_2049,
        FBR_20_2049,
        APRL_16_2049,
        APRL_25_2049,
        M_1_2049,
        M_17_2049,
        M_23_2049,
    };

    struct Message {
        private:
            //member data
            wString m_addressee;
            wString m_sender;
            wString m_text;
        public:
            //get functions
            wString getAddressee() {
                return this->m_addressee;
            }
            wString getSender() {
                return this->m_sender;
            }
            wString getText() {
                return this->m_text;
            }
            //!get functions
            //set functions
            void setText(wString& text) {
                this->m_text = text;
            }
            //!set functions
    };

    class Log {
        private:
            //member data
            Message m_msg;
            std::vector<symbol> m_letter_map;
            //!member data
        public:
            //constructors
            //  default
            Log() = default;
            //destructor
            ~Log() {}
            //get functions
            std::vector<symbol> getCodeMatrix() {
                return this->m_letter_map;   
            }
            Message& getMessage() {
                return this->m_msg;
            }
            //!get functions
            void setLetterMap(std::vector<symbol>& lm) {
                m_letter_map = lm;
            }
    };
}

#endif //!LOG_HPP