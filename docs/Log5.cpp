#include <DEEP_EYE.hpp>

int check_factorial(unsigned long long fact) {
    unsigned long long incr = 1;
    while(fact > incr) {
        fact /= incr;
        incr++;
    }
    return incr;
}

int main() {
    wrd::Log log;

    wrd::DeepEye::LOG_extract(log, wrd::TXT::M_1_2049);

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