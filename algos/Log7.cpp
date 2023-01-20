#include <DEEP_EYE.hpp>
#include <sstream>

void from_base64(std::string& input) {
    std::string output;
    std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::vector<int> base64_ints;

    for (char i : input)
        base64_ints.push_back(base64_chars.find(i));

    for (int i = 0; i < base64_ints.size(); i += 4) {
        int n = (base64_ints[i] << 18) + (base64_ints[i + 1] << 12) + (base64_ints[i + 2] << 6) + base64_ints[i + 3];
        std::ostringstream oss;
        oss << (char) (n >> 16) << (char) (n >> 8 & 0xFF) << (char) (n & 0xFF);
        output += oss.str();
    }

    input = output;
}

int main() {
    wrd::Log log;

    wrd::DeepEye::LOG_extract(log, wrd::TXT::FBR_26_2049_18);

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
    from_base64(final);
    log.setText(final);

    wrd::DeepEye::read(log);
}