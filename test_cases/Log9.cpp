#include <LogGen.hpp>

int main() {
    //FBR_26_2049_5
    std::string text = "HQ: ready: _QUARANTINE_INIT = YES; HQ: ready: ___LOC___ = wrd::___LOC___::A1___sector";
    const std::string addressee = "//::DEEP_EYE";
    const std::string writer = "//::HQ";
    LogGen lg(text, addressee, writer);
    lg.gen_cm_arr(text);
    lg.encode();
    std::cout << text << std::endl;
    //lg.write("Log9.dat");
}