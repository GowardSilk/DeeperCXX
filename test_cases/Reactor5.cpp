#include "../Reactor.hpp"
#include <random>

const char ARR[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};

wString reactor_function(wString str, int shift) {
    wString ans;
    if(shift >= 26) { shift %= 26; }
    std::for_each(std::begin(str), std::end(str), [&](char c) {
        if(c - shift < 'a') {
            int i;
            for(i = shift; c >= 'a'; c--, i--);
            c = 'z' - i;
        }
        else { c -= shift; }
        ans.push_back(c);
    });
    return ans;
}

//rng
wString getRND(int length) {
    std::string value;
    for(unsigned i = 0; i < length; i++) {
        static std::random_device seeder;
        static std::mt19937 gen(seeder());
        std::uniform_real_distribution<float> dis(0, 25);
        int pos = dis(gen);
        value.push_back(ARR[pos]);
    }
    return value;
}
int getRND() {
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_int_distribution<int> dis(0, 25);
    return dis(gen);
}

int main() {

    std::ofstream wf("Reactor5.dat", std::ios::out | std::ios::binary);
    if(!wf) {
        std::cout << "cannot open file!\n";
        exit(EXIT_FAILURE);
    }

    //for each test case...
    for(unsigned i = 0; i < 10; i++) {
        wString input1 = getRND(20);
        int input2 = getRND();
        //wrtie input1
        int len = input1.length();
        wf.write(reinterpret_cast<char*>(&len), sizeof(int));
        wf.write(input1.c_str(), len);
        //write input2
        wf.write((char *) &input2, sizeof(int));
        //write expected output
        wString expected = reactor_function(input1, input2);
        int expected_len = expected.length();
        wf.write(reinterpret_cast<char*>(&expected_len), sizeof(int));
        wf.write(expected.c_str(), expected_len);
    }
}