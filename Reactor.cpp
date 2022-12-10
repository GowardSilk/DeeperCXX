#include "DeepMain.hpp"
#include <random>
#include <time.h>

wString reactor_A_func(wString input) {
    wString ans;
    for(unsigned i = 0; i < input.length(); i++) {
        char a = input.at(i), b = input.at(i-1);
        if(b == 45 || b == 95) {
            a = toupper(a);
        }
        if(a != '_' && a != '-') {
            ans += a;
        }
    }
    return ans;
}

//rng
wString getRND(int from, int to) {
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_int_distribution<int> dis(from, to);
    wString input;
    //string of random length
    for(unsigned i = 0; i < dis(gen); i++) {
        char cch = 'a' + rand()%26;
        input += cch;
    }
    return input;
}

int main(void) {

    std::ofstream wf("Reactor.dat", std::ios::out | std::ios::binary);
    if(!wf) {
        std::cout << "cannot open file!\n";
        exit(EXIT_FAILURE);
    }

    //TERMINAL_A
    std::vector<wString> input;
    wString expected;
    //write all test cases
    for(unsigned t = 0; t < 10; t++) {
        //one test case...
        input.at(t) = getRND(1, 1);
    }

    //for each test case
    for(unsigned i = 0; i < 10; i++) {
        printf_s("------[%d]------\n", i);
        //write input
        printf_s("%s", input.at(i));
        //wf.write((char *) &input.at(i), sizeof(wString));
        //write expected output
        expected = reactor_A_func(input.at(i));
        printf_s("Expected output: %s", expected);
        //wf.write((char *) &expected, sizeof(wString));
    }

    wf.close();

    if(!wf.good()) {
        std::cout << "error occurred at handling time!\n";
    }
    //!TERMINAL_A

    return DEEPER;
}