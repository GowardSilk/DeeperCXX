#include <LogGen.hpp>

std::string to_base64(const std::string& ascii) {
    const char b64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    //Input string must be a multiple of 3 bytes
    if (ascii.length() % 3 != 0)
        return "";

    std::string b64;

    //for 3 bytes
    for (int i = 0; i < ascii.length(); i += 3) {
        // Convert 3 8-bit bytes into 4 6-bit bytes
        int b = (ascii[i] & 0xFC) >> 2;
        int c = ((ascii[i] & 0x03) << 4) + ((ascii[i+1] & 0xF0) >> 4);
        int d = ((ascii[i+1] & 0x0F) << 2) + ((ascii[i+2] & 0xC0) >> 6);
        int e = ascii[i+2] & 0x3F;
        
        //Add the base64 encoded bytes to the output string
        b64 += b64_table[b];
        b64 += b64_table[c];
        b64 += b64_table[d];
        b64 += b64_table[e];
    }

    //Return the encoded string
    return b64;
}

int main() {
    //FBR_26_2049_18
    std::string text = "I know what you did THEY know what you did Did you really think that you could just take whatever you want from THEM? Lets make a deal You will give us all the information we need: Where is Smith hiding Who are you working for Where is all the stolen equipment and you will be freed Otherwise you will end just like your pretty girlfriend in MORGUE";
    const std::string addressee = "Jacob Woods B";
    const std::string writer = "Denis Keen C";
    text = to_base64(text);
    std::cout << "text: " << text << std::endl;
    LogGen lg(text, addressee, writer);
    lg.gen_cm_arr(text);
    lg.encode();
    lg.write("Log7.dat");
    
}