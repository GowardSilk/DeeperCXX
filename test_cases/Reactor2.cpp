#include <Reactor.hpp>
#include <random>

const char ARR[52] = {
    'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D',
    'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H',
    'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L',
    'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P',
    'q', 'Q', 'r', 'R', 's', 'S', 't', 'T',
    'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X',
    'y', 'Y', 'z', 'Z'
};

wString reactor_function(wString str) {
    for(unsigned i = 0; i < str.length(); i++) {
        if(islower(str.at(i)))
            str.at(i) -= 32;
        else
            str.at(i) += 32;
    }
    return str;
}

//rng
std::string getRND() {
    std::string random_word;
    for(unsigned i = 0; i < 10; i++) {
        static std::random_device seeder;
        static std::mt19937 gen(seeder());
        std::uniform_real_distribution<float> dis(0, 51);
        int pos = dis(gen);
        random_word.push_back(ARR[pos]);
    }
    return random_word;
}

int main() {

    std::ofstream wf("Reactor2.dat", std::ios::out | std::ios::binary);
    if(!wf) {
        std::cout << "cannot open file!\n";
        exit(EXIT_FAILURE);
    }

    //for each test case...
    for(unsigned i = 0; i < 10; i++) {
        printf("------[%d]------\n", i);
        std::string input = getRND();
        int input_len = input.length();
        std::cout << "input: " << input << std::endl;
        //wrtie input
        wf.write(reinterpret_cast<char *>(&input_len), sizeof(int));
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

    std::ifstream rf("Reactor2.dat", std::ios::out | std::ios::binary);
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