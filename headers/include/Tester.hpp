#ifndef TESTER_HPP
#define TESTER_HPP

#include <fstream>
#include <ostream>

class ReadIO {
    private:
        std::ifstream rf;
    public:
        ReadIO(const char* fileDest) {
            this->rf = std::ifstream(fileDest, std::ios::out | std::ios::binary);
			if(!rf) {
				std::cout << "cannot read file!\n";
			}
        }
        void read_string(wString& s) {
            int len;
            rf.read(reinterpret_cast<char *>(&len), sizeof(int));
            char *buf = new char[len+1];
            rf.read(buf, len);
            buf[len] = '\0';
            s = buf;
            delete [] buf;
            check_file_validity();
        }
        void read_char(char& value_to_read) {
            rf.read(reinterpret_cast<char *>(&value_to_read), sizeof(char));
            check_file_validity();
        }
        void read_int(int& value_to_read) {
            rf.read(reinterpret_cast<char *>(&value_to_read), sizeof(int));
            check_file_validity();
        }
        void read_bool(bool& value_to_read) {
            rf.read(reinterpret_cast<char *>(&value_to_read), sizeof(bool));
            check_file_validity();
        }
        void close() {
            rf.close();
        }
        void check_file_validity() {
            if(!rf.good())
                std::cout << "Error occurred at reading time!\n";
        }
};

class WriteIO {
    private:
        std::ofstream wf;
    public:
        WriteIO(const char* fileDest) {
            this->wf = std::ofstream(fileDest, std::ios::out | std::ios::binary);
            if(!wf) {
                std::cout << "cannot open file!\n";
                exit(EXIT_FAILURE);
            }
        }
        void write_char(char value_to_write) {
            wf.write(reinterpret_cast<char*>(&value_to_write), sizeof(char));
        }
        void write_string(wString value_to_write) {
            int len = value_to_write.length();
            wf.write(reinterpret_cast<char*>(&len), sizeof(int));
            wf.write(value_to_write.c_str(), len);
        }
        void write_int(int value_to_write) {
            wf.write(reinterpret_cast<char*>(&value_to_write), sizeof(int));
        }
        void write_bool(bool value_to_write) {
            wf.write(reinterpret_cast<char*>(&value_to_write), sizeof(bool));
        }
        void flush() {
            wf.flush();
        }
        void close() {
            wf.close();
        }
        bool good() {
            return wf.good();
        }
};

#endif