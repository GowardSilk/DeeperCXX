#include <DEEP_EYE.hpp>

bool check_if_palindrome(int num) {
    int r = 0, dup = num;
    while(num > 0) {
        int rem = num % 10;
        r = (r*10)+rem;
        num /= 10;
    }
    if(dup == num)
        return true;
    return false;
}

int main() {
    wrd::Log log;

    wrd::DeepEye::LOG_extract(log, wrd::TXT::M_17_2049);

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