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
    wrd::Message msg = log.getMessage();

    wString text;
    for(unsigned y = 0; y < letter_map.height; y++) {
        for(unsigned x = 0; x < letter_map.width; x++) {
            text.push_back (
                letter_map.get_symbol(Vector2u(x, y))
            );
        }
    }

    msg.setText(text);

    wrd::DeepEye::read(log);
}