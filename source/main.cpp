#include <DEEP_EYE.hpp>

int main() {
    
    wrd::Log log;
    wrd::DeepEye::LOG_extract(log, wrd::TXT::JNR_2_2049);
    wrd::Message msg = log.getMessage();
    std::string num, expec, encoded = msg.getText();
    for(unsigned i = 0; i < encoded.length(); i++) {
        if(encoded.at(i) != ';')
            num.push_back(encoded.at(i));
        else {
            expec.push_back(
                log.getCodeMatrix().at(std::stoi(num))
            );
            num.erase();
        }
    }
    std::cout << "[EXPEC]:" << expec << std::endl;

    std::cin.get();
}