#include <LogGen.hpp>
#include <cctype>

<<<<<<< HEAD
bool encoding_algo(int val) {
    return val % 2 == 0;
}

int next_valid(int val) {
    while(!encoding_algo(val))
        val++;
    return val;
}


=======
>>>>>>> 1a8f3e6d25b472bd670fc33d75c533dd134b1134
int main() {
    //FBR_20_2049
    std::string text = "Hey Mike! Why havent you responded to my last message? What is wrong with you? I`ve heard from your collegues, you have been acting weird lately... Is everything all right? I mean, you can tell me if you need something... You know where...";
    const std::string addressee = "Mike Smith D";
    const std::string writer = "Mark White D";
    LogGen lg(text, addressee, writer);
<<<<<<< HEAD
    lg.gen_cm_arr_custom(text, encoding_algo);
    lg.encode_custom(true, next_valid);
=======
    lg.gen_cm_arr(text);
    lg.encode();

    std::string num, expec;
    for(const auto& c : lg.m_encoded_text) {
        if(c != ';')
            num.push_back(c);
        else {
            if(isalpha(c)) {

            }
            expec.push_back(
                lg.m_cm_arr.at(std::stoi(num))
            );
            num.erase();
        }
    }

>>>>>>> 1a8f3e6d25b472bd670fc33d75c533dd134b1134
    lg.write("Log2.dat");
}