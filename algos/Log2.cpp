#include <DEEP_EYE.hpp>

int main() {

    //create plain log
    wrd::Log log;

    //get log from DeepEye
    wrd::DeepEye::LOG_extract(log, wrd::TXT::FBR_20_2049);

    //"BLACK BOX"
    CodeMatrix letter_map = log.getCodeMatrix();
    wrd::Message msg = log.getMessage();

    wString text;
    for(unsigned y = letter_map.height; y > 0; y--) {
        if(y % 2 != 0) {
            for(unsigned x = 0; x < letter_map.width; x++) {
                if(x % 2 == 0)
                    text.push_back(letter_map.get_symbol(Vector2u(x, y)));
            }
        }
    }

    msg.setText(text);

    //test
    wrd::DeepEye::read(log);

    return DEEPER;
}