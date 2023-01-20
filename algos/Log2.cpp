#include <DEEP_EYE.hpp>

int main() {

    //create plain log
    wrd::Log log;

    //get log from DeepEye
    wrd::DeepEye::LOG_extract(log, wrd::TXT::FBR_20_2049);

    //"BLACK BOX"
    CodeMatrix letter_map = log.getCodeMatrix();

    wString text = log.getText(), final, num;
    for(unsigned i = 0; i < text.length(); i++) {
        if(text[i] != ';') {
            num += text[i];
        }
        else {
            int pos = std::stoi(num);
            if(pos % 2 == 0) {
                final.push_back(
                    letter_map.get_symbol(
                        std::stoi(num)
                    )
                );
            }
            num.erase();
        }
    }
    log.setText(final);

    //test
    wrd::DeepEye::read(log);

    return DEEPER;
}