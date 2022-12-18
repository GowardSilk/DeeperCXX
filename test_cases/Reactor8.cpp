#include "../Reactor.hpp"
#include <random>

const char ARR[50] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z', '!', '(', ')', '-', '[', ']',
    '{', '}', ';', ':', '<', '>',
    '.', '/', '?', '?', '@', '#', '$', '%',
    '^', '*', '_', '~'
};

bool contains(char& ch) {
    const char* punctuation = "!()-[]{};:'\",<>./?@#$%^&*_~";
    for(unsigned short i = 0; i < 28; i++) {
        if(punctuation[i] == ch) { 
            return true;
        }
    }
    return false;
}

wString reactor_function(wString str) {
    wString new_str;
    for(char ch : str) {
        if(!contains(ch)) {
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
        std::uniform_real_distribution<float> dis(0, 50);
        int pos = dis(gen);
        value.push_back(ARR[pos]);
    }
    return value;
}

int main() {
    WriteIO writer("Reactor8.dat");
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
