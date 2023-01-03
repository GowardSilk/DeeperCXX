#include <LogGen.hpp>

bool encoding_algo(int val) {
    return val % 2 == 0;
}

int next_valid(int val) {
    while(!encoding_algo(val))
        val++;
    return val;
}

int main() {
    //FBR_24_2049_10
    std::string text = "Good evening, Woods, I am sending you this message as a reaction to your delays in stocks that have occurred in past few weeks. I understand that there has been an emergency breakdown in B2... I granted you access to an elevator in B3 so you can bring down all the supplies we are short of. Be aware, that this privilege is only temporary and will last only until the damages will be repaired. Do NOT try to do anything besides your duties. There will be consequnces... Keen";
    const std::string addressee = "Jacob Woods B";
    const std::string writer = "Denis Keen C";
    LogGen lg(text, addressee, writer);
    lg.gen_cm_arr_custom(text, encoding_algo);
    lg.encode_custom(true, next_valid);

    wString num, final;
    for (int i = 0; i < lg.m_encoded_text.length(); i++) {
        if(lg.m_encoded_text[i] != ';')
            num += lg.m_encoded_text[i];
        else {
            int n = std::stoi(num);
            if(encoding_algo(n)) {
                final.push_back(lg.m_cm_arr.at(n));
            }
            num.erase();
        }
    }

    lg.write("Log3.dat");

}