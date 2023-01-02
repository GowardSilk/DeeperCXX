#include <LogGen.hpp>
#include <sstream>

/*!
 * @defgroup L_g6 HEX positional
 * @ingroup E_g_HP
 * @brief HEX positional encoding.
 * In order to decode this message, you need 2 things:
 * <ul>
 *     <li>CodeMatrix</li>
 *     <li>Encoded text</li>
 * </ul>
 * CodeMatrix contains an array (see the documentation) of characters ocurring in DECODED text.
 * Those characters are encoded using HEX encoding (https://string-functions.com/string-hex.aspx)
 * Encoded text contains POSITIONS of characters from CodeMatrix in a specific format:
 * every number in string is divided by ';' (e.g. "1;2;3")
 * @code {.cpp}
 * CodeMatrix cm = log.getCodeMatrix(); //{'4', '8', '6', '5', 'c', 'f', ' '}
 * wString text = log.getText(); //"0;1;6;2;3;6;2;4;6;2;4;2;5" => "48 65 6c 6c 6f"
 * => [ALGORITHM] => expec_str = "Hello"
 * @endcode
*/

std::string to_hex(std::string s) {
    std::string hexString;
    std::stringstream ss;
    for (int16_t i = 0; i < s.length(); i++) {
        int asciiCode = int(s.at(i));
        ss << std::hex << asciiCode;
        hexString.append(ss.str());
        ss.str("");
    }
    return hexString;
}

int main() {

    std::string text = "That idiot wrote me again... I can not believe I ended up in this hellhole with him again! This is nonsense! And now to last, I cant go with to the party we had planned because I am stuck in this quarantine again! AGAIN! Oh my god, i am starting to get tired of this place. Working my ass off and for this?? This is the life worth living? I cant wait till we meet up. I dont know how I will survive those days without your positivness... Bye Vee <333";
    const std::string addressee = "Violet Woods A";
    const std::string writer = "Isabella Kaltenbach A";
    std::cout << to_hex(text) << std::endl;
    LogGen lg(text);
    lg.gen_cm_arr(text);
    lg.encode();

}