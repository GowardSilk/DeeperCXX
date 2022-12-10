#ifndef LOG_HPP
#define LOG_HPP

namespace wrd {

    enum class TXT {
        JNR_2_2049, FBR_20_2049, APRL_16_2049, APRL_25_2049
    };

    struct Message {
        private:
            //member data
            wString m_addressee;
            wString m_sender;
            wString m_date;
            wString m_text;
        public:
            //get functions
            wString getAddressee() {
                return this->m_addressee;
            }
            wString getSender() {
                return this->m_sender;
            }
            wString getDate() {
                return this->m_date;
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
            CodeMatrix m_letter_map;
            //!member data
        public:
            //constructors
            //  default
            Log() = default;
            //destructor
            ~Log() {}
            //get functions
            CodeMatrix getCodeMatrix() {
                return this->m_letter_map;   
            }
            Message& getMessage() {
                return this->m_msg;
            }
            //!get functions
    };
}

#endif //!LOG_HPP