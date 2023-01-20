#include <DEEP_EYE.hpp>

void from_HEX(std::string& str) {
    std::string output;
    for (int i = 0; i < str.length(); i+=2) {
        std::string charStr = str.substr(i, 2);
        int ch = std::stoi(charStr, 0, 16);
        output.push_back(static_cast<char>(ch));
    }
    str = output;
}

int main() {
    wrd::Log log;

    wrd::DeepEye::LOG_extract(log, wrd::TXT::FBR_26_2049_10);

    //BLACK BOX
    CodeMatrix letter_map = log.getCodeMatrix();

    wString text = log.getText(), num, final;
    for(char& ch : text) {
        if(ch != ';') {
            num += ch;
        }
        else {
            final.push_back(
                letter_map.get_symbol(std::stoi(num))
            );
            num.clear();
        }
    }
    from_HEX(final);
    log.setText(final);

    wrd::DeepEye::read(log);
}