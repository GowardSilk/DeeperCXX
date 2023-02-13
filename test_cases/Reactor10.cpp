#include <regex>
#include <DeepMain.hpp>
#include <random>
#include <sstream>
#include <Tester.hpp>

const char ARR[52] = {
    'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D',
    'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H',
    'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L',
    'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P',
    'q', 'Q', 'r', 'R', 's', 'S', 't', 'T',
    'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X',
    'y', 'Y', 'z', 'Z'
};

static std::random_device seeder;
static std::mt19937 gen(seeder());
char getRND(int to) {
    std::uniform_int_distribution dis(0, to);
    return ARR[dis(gen)];
}
int getRND(int from, int to) {
    std::uniform_int_distribution dis(from, to);
    return dis(gen);
}

wString reactor_function(sString str) {
    wString key = str.key;
    std::regex pattern("([a-zA-Z])-([a-zA-Z]);");
    std::unordered_map<char, char> map;

    for(std::sregex_iterator i = std::sregex_iterator(key.begin(), key.end(), pattern);
        i != std::sregex_iterator();
        ++i) {
        std::smatch match = *i;
        map.insert(std::make_pair(match[1].str()[0], match[2].str()[0]));
    }

    wString final;
    for(const auto& ch : str.value)
        final.push_back(map[ch]);
    std::cout << final << std::endl;
    return final;
}

auto main() -> int {
    WriteIO writer("Reactor10.dat");
    for(uint_fast8_t i = 0; i < 10; i++) {
        printf_s("TEST #%i\n", (int)i);
        std::ostringstream oss;
        wString key;
        wString value;
        std::vector<std::pair<char, char>> v;

        for(uint_fast8_t j = 0; j < 10; j++) {
            v.push_back(std::make_pair(getRND(51), getRND(51)));
            oss << v[j].first << "-" << v[j].second << ";";
        }
        for(uint_fast8_t j = 0; j < 10; j++)
            value += v[getRND(0, v.size())].first;
        key = oss.str();

        // std::cout << "key:" << key << std::endl;
        writer.write_string(key);
        // std::cout << "val:" << value << std::endl;
        writer.write_string(value);

        sString str = { .key = oss.str(), .value = value };
        wString expec = reactor_function(str);
        writer.write_string(expec);
    }
    writer.close();
    ReadIO reader("Reactor10.dat");
    for(uint_fast8_t i = 0; i < 10; i++) {
        wString key, value, expec;
        reader.read_string(key);
        reader.read_string(value);
        reader.read_string(expec);
        std::cout << "key   = "   << key << "\n"
                  << "value = " << value << "\n"
                  << "expec = " << expec << "\n";
    }
    reader.close();
}