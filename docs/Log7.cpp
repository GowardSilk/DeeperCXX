#include <LogGen.hpp>

/*!
 * @defgroup L_g7 Base64 positional
 * @ingroup E_g_HP
 * @brief Base64 positional encoding.
 * In order to decode this message, you need 2 things:
 * <ul>
 *     <li>CodeMatrix</li>
 *     <li>Encoded text</li>
 * </ul>
 * CodeMatrix contains an array (see the documentation) of characters ocurring in DECODED text.
 * Those characters are encoded using Base64 encoding (https://en.wikipedia.org/wiki/Base64)
 * Encoded text contains POSITIONS of characters from CodeMatrix in a specific format:
 * every number in string is divided by ';' (e.g. "1;2;3")
 * @code {.cpp}
 * CodeMatrix cm = log.getCodeMatrix(); //{'S', 'G', 'V', 's', 'b', 'G', '8', '='}
 * wString text = log.getText(); //"0;1;2;3;4;5;6;7" => SGVsbG8=
 * => [ALGORITHM] => expec_str = "Hello"
 * @endcode
*/

std::string to_base64(const std::string& ascii) {
    // Initialize base64 encoding table
    const char b64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    // Input string must be a multiple of 3 bytes
    if (ascii.length() % 3 != 0)
        return "";

    // Initialize output string
    std::string b64;

    // Loop through the input string, 3 bytes at a time
    for (int i = 0; i < ascii.length(); i += 3) {
        // Convert 3 8-bit bytes into 4 6-bit bytes
        int b = (ascii[i] & 0xFC) >> 2;
        int c = ((ascii[i] & 0x03) << 4) + ((ascii[i+1] & 0xF0) >> 4);
        int d = ((ascii[i+1] & 0x0F) << 2) + ((ascii[i+2] & 0xC0) >> 6);
        int e = ascii[i+2] & 0x3F;
        
        // Add the base64 encoded bytes to the output string
        b64 += b64_table[b];
        b64 += b64_table[c];
        b64 += b64_table[d];
        b64 += b64_table[e];
    }

    // Return the encoded string
    return b64;
}

int main() {

    std::string text = "";
    const std::string addressee = "";
    const std::string writer = "";
    std::cout << to_base64(text) << std::endl;
    LogGen lg(text);
    lg.gen_cm_arr(text);
    lg.encode();
    
}