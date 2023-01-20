#include <Reactor.hpp>
#include <random>

const char ARR[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};

int reactor_function(wString str) {
    const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
    int final_count = 0;
    for(char ch : str) {
        for(unsigned short i = 0; i < 5; i++) {
            if(vowels[i] == ch) {
                final_count++;
                break;
            }
        }
    }
    return final_count;
}

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

int main() {
    WriteIO writer("Reactor6.dat");

    //for each test case...
    for(unsigned i = 0; i < 10; i++) {
        wString str = getRND(10);
        std::cout << str << std::endl;
        //wrtie input1
        writer.write_string(str);
        //write expected output
        int expected = reactor_function(str);
        writer.write_int(expected);
        std::cout << expected << std::endl;
        //wf.write((char*) expected, sizeof(int));
    }
    writer.flush();
    writer.close();
}
