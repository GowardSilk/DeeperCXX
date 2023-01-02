#include <LogGen.hpp>

std::string to_ROT_13(std::string& str) {
    std::string output = "";
    for (uint16_t i = 0; i < str.length(); i++) {
        // if the character lies between A-Z
        if (str[i] >= 'A' && str[i] <= 'Z')
            // rotate the character
            output += (char)((str[i] - 'A' + 13) % 26 + 'A');
        // if the character lies between a-z
        else if (str[i] >= 'a' && str[i] <= 'z')
            // rotate the character
            output += (char)((str[i] - 'a' + 13) % 26 + 'a');
        // if the character is a space
        else if (str[i] == ' ')
            // add a space to the output
            output += ' ';
        else
            output += str[i];
    }
    return output;
}

int main() {

    std::string text = "Hey Bella! I see you have got down here pretty fast heh ; ) Recently I have earned a special privilege and now I can go basically anywhere... Do you want to remember the old times ? <3";
    const std::string addressee = "Isabella Kaltenbach A";
    const std::string writer = "Jacob Woods B";
    text = to_ROT_13(text);
    LogGen lg(text, addressee, writer);
    lg.gen_cm_arr(text);
    lg.encode();

    wString num, final;
    for (int i = 0; i < lg.m_encoded_text.length(); i++)
    {
        if(lg.m_encoded_text[i] != ';') {
            num += lg.m_encoded_text[i];
        }
        else {
            final.push_back(
                lg.m_cm_arr.at(
                    std::stoi(num)
                )
            );
            num.erase();
        }
    }

    lg.write("Log5.dat");
    
}