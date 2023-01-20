#include <LogGen.hpp>

int main() {
    //FBR_26_2049_5
    std::string text = "";
    const std::string addressee = "";
    const std::string writer = "";
    LogGen lg(text, addressee, writer);
    lg.gen_cm_arr(text);
    lg.encode();
    lg.write("Log10.dat");
}