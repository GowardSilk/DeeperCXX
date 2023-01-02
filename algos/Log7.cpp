#include <DEEP_EYE.hpp>

int check(int num) {
    int t1 = 0, t2 = 0;
    while(num > 0) {
        int rem = num % 10;
        if(rem == 0) {
            t2 = t1;
            t1 = 0;
        }
        t1 += rem;
        num /= 10;
    }
    if(t1 == t2)
        return t1;
    else
        return 0;
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