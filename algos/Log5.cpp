#include <DEEP_EYE.hpp>

void from_ROT_13(char& ch) {
    // if the character lies between A-Z
    if (ch >= 'A' && ch <= 'Z')
        // rotate the character
        ch = (char)((ch - 'A' + 13) % 26 + 'A');
    // if the character lies between a-z
    else if (ch >= 'a' && ch <= 'z')
        // rotate the character
        ch = (char)((ch - 'a' + 13) % 26 + 'a');
    // if the character is a space
    else if (ch == ' ')
        // add a space to the ch
        ch = ' ';
    else
        ch = ch;
}

int main() {
    wrd::Log log;

    wrd::DeepEye::LOG_extract(log, wrd::TXT::FBR_25_2049_23);

    //BLACK BOX
    CodeMatrix letter_map = log.getCodeMatrix();

    wString text = log.getText(), num, final;
    for(char& ch : letter_map)
        from_ROT_13(ch);
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
    log.setText(final);

    wrd::DeepEye::read(log);
}