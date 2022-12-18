#include "../Reactor.hpp"
#include <random>

const char ARR[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};

bool reactor_function(wString str) {
    for(unsigned i = 0; i < str.length()/2; i++) {
        if(str[i] != str[str.length()-1-i])
            return false;
    }
    return true;
}

wString getRND(int length) {
    std::string value;
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_int_distribution<int> dis(0, 1);
    if(dis(gen)) {
        for(unsigned i = 0; i < length/2; i++) {
            dis = std::uniform_int_distribution<int>(0, 25);
            int pos = dis(gen);
            value.push_back(ARR[pos]);
        }
        wString rotated = value;
        std::reverse(std::begin(rotated), std::end(rotated));
        return value.append(rotated);
    }
    else {
        for(unsigned i = 0; i < length; i++) {
            dis = std::uniform_int_distribution<int>(0, 25);
            int pos = dis(gen);
            value.push_back(ARR[pos]);
        }
        return value;
    }
}

int main() {
    WriteIO writer("Reactor7.dat");
    for(unsigned short i = 0; i < 10; i++) {
        wString input = getRND(10);
        writer.write_string(input);
        std::cout << input << std::endl;
        bool expected = reactor_function(input);
        std::cout << expected << std::endl;
        writer.write_bool(expected);
        if(!writer.good())
            std::cout << "help\n";
    }
    writer.close();
}
