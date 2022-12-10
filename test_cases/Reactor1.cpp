#include "../Reactor.hpp"
#include <random>

const char ARR[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};

wString reactor_function(wString str) {
    for(unsigned i = 0; i < str.length(); i++) {
        str.at(i) -= 32;
    }
    return str;
}

//rng
std::string getRND() {
    std::string random_word;
    for(unsigned i = 0; i < 10; i++) {
        static std::random_device seeder;
        static std::mt19937 gen(seeder());
        std::uniform_int_distribution<int> dis(0, 25);
        random_word.push_back(ARR[dis(gen)]);
    }
    return random_word;
}

int main() {
    
    std::ofstream wf("Reactor1.dat", std::ios::out | std::ios::binary);
    if(!wf) {
        std::cout << "cannot open file!\n";
        exit(EXIT_FAILURE);
    }

    //for each test case...
    for(unsigned i = 0; i < 10; i++) {
        //printf("------[%d]------\n", i);
        std::string input = getRND();
        std::cout << "input: " << input << std::endl;
        //wrtie input
        //first you need to write input length
        int input_len = input.length();
        wf.write(reinterpret_cast<char *>(&input_len), sizeof(int));
        //and than actual string
        wf.write(input.c_str(), input_len);

        std::string expected = reactor_function(input);
        int expected_len = expected.length();
        //write expected output
        wf.write(reinterpret_cast<char *>(&expected_len), sizeof(int));
        wf.write(expected.c_str(), expected_len);
        std::cout << "expected: " << expected << std::endl;
    }

    wf.flush();
    wf.close();
    if(!wf.good()) {
        std::cout << "error occurred at handling time!\n";
    }

    std::ifstream rf("Reactor1.dat", std::ios::out | std::ios::binary);
    if(!rf) {
        std::cout << "cannot read file!\n";
    }

    //TEST_CASES
    for(unsigned i = 0; i < 10; i++) {
        wString input;
        int input_len;
        rf.read(reinterpret_cast<char *>(&input_len), sizeof(int));
        char* buf = new char[input_len+1];
        rf.read(buf, input_len);
        buf[input_len] = '\0';
        input = buf;
        delete [] buf;

        wString expected;
        int expected_len;
        rf.read(reinterpret_cast<char *>(&expected_len), sizeof(int));
        buf = new char[expected_len+1];
        rf.read(buf, expected_len);
        buf[expected_len] = '\0';
        expected = buf;
        delete [] buf;

        std::cout << input << std::endl;
        std::cout << expected << std::endl;
        std::cout << "--------------\n";

        if(!rf.good()) {
            std::cout << "error occurred at reading time!\n";
        }
    }
    //!TEST_CASES

    rf.close();

    return DEEPER;
}