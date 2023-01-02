#include <LogGen.hpp>

/*!
 * @defgroup L_g4 Even positional
 * @ingroup E_g_LP 
 * @brief Even positional encoding.
 * In order to decode this message, you need 2 things:
 * <ul>
 *     <li>CodeMatrix</li>
 *     <li>Encoded text</li>
 * </ul>
 * CodeMatrix contains an array (see the documentation) of characters, but only on positions of primes!
 * Encoded text contains POSITIONS of characters from CodeMatrix in a specific format:
 * every number in string is divided by ';' (e.g. "1;2;3")
 * @code {.cpp}
 * CodeMatrix cm = log.getCodeMatrix(); //{'}', NULL, 'H', 'l', 'e', '@', 'o'}
 * wString text = log.getText(); //"0;4;2;2;6"
 * => [ALGORITHM] => expec_str = "Hello"
 * @endcode
*/

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

int next_valid(int val) {
    while(!encoding_algo(val))
        val++;
    return val;
}
 
int main() {

    std::string text = "WHAT DO YOU THINK YOU ARE DOING ?! ARE YOU COMPLETELY OUT OF YOUR MIND? WHAT HAVE YOU BEEN THINKING? I KNOW YOU ARE READING THIS MESSAGE. I KNOW WHERE YOU ARE. THEY KNOW... MIKE DONT MAKE THIS HARDER FOR YOURSELF...";
    const std::string addressee = "Mike Smith D";
    const std::string writer = "Mark White D";
    LogGen lg(text);
    lg.gen_cm_arr_custom(text, encoding_algo);
    lg.encode_custom(true, next_valid);

    wString num, final;
    for (int i = 0; i < lg.m_encoded_text.length(); i++) {
        if(lg.m_encoded_text[i] != ';')
            num += lg.m_encoded_text[i];
        else {
            int n = std::stoi(num);
            if(encoding_algo(n)) {
                final.push_back(
                    lg.m_cm_arr.at(
                        std::stoi(num)
                    )
                );
            }
            num.erase();
        }
    }

    lg.write("Log4.dat");
    
}