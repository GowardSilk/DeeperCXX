#include <LogGen.hpp>

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