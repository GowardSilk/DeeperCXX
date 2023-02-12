#include <Reactor.hpp>
#include <random>

const char ARR[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};

wString reactor_function(sString strong_str) {
    wString ans;
    for(unsigned i = 0; i < strong_str.value.length(); i++) {
        char x = strong_str.value.at(i);
        for(unsigned j = 0; j < strong_str.key.length(); j++) {
            if(x == strong_str.key.at(j)) {
                ans.push_back(x);
                break;
            }
        }
    }
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

wString read(std::ifstream& rf) {
    wString s;
    int len;
    rf.read(reinterpret_cast<char *>(&len), sizeof(int));
    char *buf = new char[len+1];
    rf.read(buf, len);
    buf[len] = '\0';
    s = buf;
    delete [] buf;
    return s;
}

int main() {

    std::ofstream wf("Reactor3.dat", std::ios::out | std::ios::binary);
    if(!wf) {
        std::cout << "cannot open file!\n";
        exit(EXIT_FAILURE);
    }

    //for each test case...
    for(unsigned i = 0; i < 10; i++) {
        printf("------[%d]------\n", i);
        sString input;
        input.value = getRND(20);
        int val_len = input.value.length();
        input.key = getRND(5);
        int key_len = input.key.length();
        std::cout << "input: {" << input.value << "," << input.key << "}" << std::endl;
        //wrtie input
        //  first key...
        wf.write(reinterpret_cast<char*>(&key_len), sizeof(int));
        wf.write(input.key.c_str(), key_len);
        //  2nd value
        wf.write(reinterpret_cast<char*>(&val_len), sizeof(int));
        wf.write(input.value.c_str(), val_len);
        //write expected output
        std::string expected = reactor_function(input);
        int expected_len = expected.length();
        wf.write(reinterpret_cast<char*>(&expected_len), sizeof(int));
        wf.write(expected.c_str(), expected_len);
        std::cout << "expected: " << expected << std::endl;
    }

    wf.flush();
    wf.close();
    if(!wf.good())
        std::cout << "error occurred at handling time!\n";
    
    std::ifstream rf("Reactor3.dat", std::ios::out | std::ios::binary);
    if(!rf) {
        std::cout << "cannot read file!\n";
    }

    //TEST_CASES
    for(unsigned i = 0; i < 10; i++) {
        sString input;
        input.key = read(rf);
        input.value = read(rf);

        wString expected = read(rf);

        std::cout << input.key << ":" << input.value << std::endl;
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