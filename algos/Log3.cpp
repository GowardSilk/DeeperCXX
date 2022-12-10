#include "../DEEP_EYE.hpp"

bool is_prime(int val) {
    //corner cases
    if(val <= 1)
        return false;
    if(val <= 3)
        return true;
    if(val % 2 == 0 || val % 3 == 0)
        return false;

    //6k +- 1
    for(int i = 5; i*i <= val; i += 6) {
        if(val % i == 0 || val % (i+2) == 0)
            return false;
    }
    return true;
}

int main() {

    //create plain log
    wrd::Log log;

    //get log from DeepEye
    wrd::DeepEye::LOG_extract(log, wrd::TXT::APRL_16_2049);

    //"BLACK BOX"
    CodeMatrix letter_map = log.getCodeMatrix();
    wrd::Message msg = log.getMessage();

    wString text;
    for(unsigned y = 0; y < letter_map.height; y++) {
        for(unsigned x = 0; x < letter_map.width; x++) {
            if(is_prime(x))
                text.push_back(letter_map.get_symbol(Vector2u(x, y)));
        }
    }

    msg.setText(text);

    //test
    wrd::DeepEye::read(log);

    return DEEPER;
}