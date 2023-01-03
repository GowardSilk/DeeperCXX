#include <LogGen.hpp>
#include <cctype>

bool encoding_algo(char c) {
    return isalpha(c);
}

int main() {
    //FBR_20_2049
    std::string text = "Hey Mike! Why haven`t you responded to my last message? What is wrong with you? I`ve heard from your collegues, you have been acting weird lately... Is everything all right? I mean, you can tell me if you need something... You know where...";
    const std::string addressee = "Mike Smith D";
    const std::string writer = "Mark White D";
    LogGen lg(text, addressee, writer);
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