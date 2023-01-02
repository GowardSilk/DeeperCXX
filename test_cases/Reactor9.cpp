#include <Reactor.hpp>
#include <random>

const char ARR[36] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z', '1', '2', '3', '4', '5', '6',
    '7', '8', '9', '0'
};

wString reactor_function(wString str) {
    wString new_str;
    for(const char& ch : str) {
        if(ch < 48 || ch > 57) {
            std::cout << ch;
            new_str.push_back(ch);
        }
    }
    return new_str;
}

wString getRND(int length) {
    std::string value;
    for(unsigned i = 0; i < length; i++) {
        static std::random_device seeder;
        static std::mt19937 gen(seeder());
        std::uniform_real_distribution<float> dis(0, 36);
        int pos = dis(gen);
        value.push_back(ARR[pos]);
    }
    return value;
}

int main() {
    WriteIO writer("Reactor9.dat");
    for(unsigned short i = 0; i < 10; i++) {
        wString input = getRND(10);
        writer.write_string(input);
        std::cout << input << std::endl;
        wString expected = reactor_function(input);
        writer.write_string(expected);
        std::cout << expected << std::endl;
        if(!writer.good())
            std::cout << "help\n";
    }
    writer.close();
}
