#include <LogGen.hpp>

/*!
 * @defgroup L_g5 ROT-13 positional
 * @ingroup E_g_HP 
 * @brief ROT-13 positional encoding.
 * In order to decode this message, you need 2 things:
 * <ul>
 *     <li>CodeMatrix</li>
 *     <li>Encoded text</li>
 * </ul>
 * CodeMatrix contains an array (see the documentation) of characters ocurring in DECODED text.
 * Those characters are encoded using ROT_13 encoding (https://en.wikipedia.org/wiki/ROT13)
 * Encoded text contains POSITIONS of characters from CodeMatrix in a specific format:
 * every number in string is divided by ';' (e.g. "1;2;3")
 * @code {.cpp}
 * CodeMatrix cm = log.getCodeMatrix(); //{'U', 'y', 'r', 'b'}
 * wString text = log.getText(); //"0;2;1;1;3"
 * => [ALGORITHM] => expec_str = "Hello"
 * @endcode
*/

std::string to_ROT_13(std::string& str) {
    std::string output = "";
    for (uint16_t i = 0; i < str.length(); i++) {
        // if the character lies between A-Z
        if (str[i] >= 'A' && str[i] <= 'Z')
            // rotate the character
            output += static_cast<char>((str[i] - 'A' + 13) % 26 + 'A');
        // if the character lies between a-z
        else if (str[i] >= 'a' && str[i] <= 'z')
            // rotate the character
            output += static_cast<char>((str[i] - 'a' + 13) % 26 + 'a');
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
    LogGen lg(text);
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