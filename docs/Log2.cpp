#include <LogGen.hpp>
#include <cctype>

/*!
 * @defgroup L_g2 ?Simple positional
 * @ingroup E_g_LP 
 * @brief Simple positional encoding is the simplest of all.
 * In order to decode this message, you need 2 things:
 * <ul>
 *     <li>CodeMatrix</li>
 *     <li>Encoded text</li>
 * </ul>
 * CodeMatrix contains an array (see the documentation) of characters,
 * ocurring in DECODED text.
 * Encoded text contains POSITIONS of characters from CodeMatrix in a specific format:
 * every number in string is divided by ';' (e.g. "1;2;3")
 * @code {.cpp}
 * CodeMatrix cm = log.getCodeMatrix(); //{'e', 'H', 'o', ' ', 'w', 'd', 'r', 'l'}
 * wString text = log.getText(); //"1;0;7;7;2;3;4;3;6;7;5"
 * => [ALGORITHM] => expec_str = "Hello World"
 * @endcode
*/

bool encoding_algo(char c) {
    return isalpha(c);
}

int main() {

    std::string text = "Hey Mike! Why haven`t you responded to my last message? What is wrong with you? I`ve heard from your collegues, you have been acting weird lately... Is everything all right? I mean, you can tell me if you need something... You know where...";
    const std::string addressee = "Mike Smith D";
    const std::string writer = "Mark White D";
    LogGen lg(text);
    lg.gen_cm_arr_custom(text, encoding_algo);
    lg.encode();

    std::string num, expec;
    for(const auto& c : lg.m_encoded_text) {
        if(c != ';')
            num.push_back(c);
        else {
            expec.push_back(
                lg.m_cm_arr.at(std::stoi(num))
            );
            num.erase();
        }
    }

    lg.write("Log2.dat");
}