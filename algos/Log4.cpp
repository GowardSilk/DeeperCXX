#include <DEEP_EYE.hpp>

bool encoding_algo(int val) {
    //corner cases
    if(val <= 1)
        return false;
    if(val <= 3)
        return true;
    if(val % 2 == 0 || val % 3 == 0)
        return false;
    //6k +- 1
    for(int i = 5; i*i <= val; i += 6) {
        if(val % i == 0 || val % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {

    //create plain log
    wrd::Log log;

    //get log from DeepEye
    wrd::DeepEye::LOG_extract(log, wrd::TXT::FBR_26_2049_11);

    //"BLACK BOX"
    CodeMatrix letter_map = log.getCodeMatrix();

    wString text = log.getText();
    wString num, final;
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