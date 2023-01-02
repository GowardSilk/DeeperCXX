#include <LogGen.hpp>

/**
 * @defgroup E_g Character Encodings
 */

/**
 * @defgroup E_g_LP Lower Positional Encodings
 * @ingroup E_g
 */

/**
 * @defgroup E_g_HP Higher Positional Encodings
 * @ingroup E_g
 */

/*!
 * @defgroup L_g1 Simple positional
 * @ingroup E_g_LP 
 * @brief Simple positional encoding is the simplest of all.
 * In order to decode this message, you need 2 things:
 * <ul>
 *     <li>CodeMatrix</li>
 *     <li>Encoded text</li>
 * </ul>
 * CodeMatrix contains an array (see the documentation) of characters
 * ocurring in DECODED text.
 * Encoded text contains POSITIONS of characters from CodeMatrix in a specific format:
 * every number in string is divided by ';' (e.g. "1;2;3")
 * @code {.cpp}
 * CodeMatrix cm = log.getCodeMatrix(); //{'e', 'H', 'o', ' ', 'w', 'd', 'r', 'l'}
 * wString text = log.getText(); //"1;0;7;7;2;3;4;3;6;7;5"
 * => [ALGORITHM] => expec_str = "Hello World"
 * @endcode
*/

int main() {

    std::string text = "Hello Carl! I see you have successfully finished all the tests and made it here! Hopefully you will learn fast. Just do what they tell you to do and everythinh will be okay!! I know this may sound silly, but dont ask too many questions, they dont like it. I cannot wait until you come down here... I mean DEEPER right?";
    const std::string addressee = "Carl Anderson A";
    const std::string writer = "Mark White D";
    LogGen lg(text);
    lg.gen_cm_arr(text);
    lg.encode();
    
    wString num, final;
    for (int i = 0; i < lg.m_encoded_text.length(); i++) {
        if(lg.m_encoded_text[i] != ';')
            num += lg.m_encoded_text[i];
        else {
            final.push_back(
                lg.m_cm_arr.at(
                    std::stoi(num)
                )
            );
            num.erase();
        }
    }
    //std::cout << "[FINAL]: " << final << std::endl;

    lg.write("Log1.dat");
}