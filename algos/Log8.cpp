#include <DEEP_EYE.hpp>

bool check(int number) {
    int m = number, s = 0, p = std::log10(number)+.9;
    while (m > 0) {
        s += pow(m % 10, p--);
        m /= 10;
    }
    return s == number;
} 

int main() {
    wrd::Log log;

    wrd::DeepEye::LOG_extract(log, wrd::TXT::M_23_2049);

    //BLACK BOX
    CodeMatrix letter_map = log.getCodeMatrix();

    wString text;

    log.setText(text);

    wrd::DeepEye::read(log);
}