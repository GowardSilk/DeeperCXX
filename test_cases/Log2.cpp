#include <LogGen.hpp>
#include <cctype>

bool encoding_algo(int val) {
    return val % 2 == 0;
}

int next_valid(int val) {
    while(!encoding_algo(val))
        val++;
    return val;
}


int main() {
    //FBR_20_2049
    std::string text = "Hey Mike! Why haven`t you responded to my last message? What is wrong with you? I`ve heard from your collegues, you have been acting weird lately... Is everything all right? I mean, you can tell me if you need something... You know where...";
    const std::string addressee = "Mike Smith D";
    const std::string writer = "Mark White D";
    LogGen lg(text, addressee, writer);
    lg.gen_cm_arr_custom(text, encoding_algo);
    lg.encode_custom(true, next_valid);
    lg.write("Log2.dat");
}