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

    wString text;

    log.setText(text);

    wrd::DeepEye::read(log);
}