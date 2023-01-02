#include <DEEP_EYE.hpp>

bool encoding_algo(int val) {
    return val % 2 == 0;
}

int main() {

    //create plain log
    wrd::Log log;

    //get log from DeepEye
    wrd::DeepEye::LOG_extract(log, wrd::TXT::APRL_16_2049);

    //"BLACK BOX"
    CodeMatrix letter_map = log.getCodeMatrix();
    wString text = log.getText(), final, num;
    for (int i = 0; i < text.length(); i++)
    {
        if(text[i] != ';') {
            num += text[i];
        }
        else {
            int n = std::stoi(num);
            if(encoding_algo(n)) {
                final.push_back(letter_map.get_symbol(n));
            }
            num.erase();
        }
    }
    log.setText(final);

    //test
    wrd::DeepEye::read(log);

    return DEEPER;
}