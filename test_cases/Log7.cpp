#include <LogGen.hpp>

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