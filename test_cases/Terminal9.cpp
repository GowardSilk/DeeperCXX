#include "../DeepMain.hpp"
#include "../Tester.hpp"
#include <random>

bool terminal_function(triplet<int> tr_con) {
    int sum = tr_con._triplet_unit_1 + tr_con._triplet_unit_2 + tr_con._triplet_unit_3;
    if(sum <= 1)
        return false;
    for(int i = 2; i <= std::sqrt(sum); i++) {
        if(sum % i == 0)
            return false;
    }
    return true;
}

//rng
int getRND(int from, int to) {
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_int_distribution<int> dis(from, to);
    return dis(gen);
}

int main() {
    WriteIO writer("Terminal9.dat");
    for(unsigned short i = 0; i < 10; i++) {
        triplet<int> input = {
            ._triplet_unit_1 = getRND(1, 100),
            ._triplet_unit_2 = getRND(1, 100),
            ._triplet_unit_3 = getRND(1, 100),
        };
        writer.write_int(input._triplet_unit_1);
        writer.write_int(input._triplet_unit_2);
        writer.write_int(input._triplet_unit_3);
        bool expected = terminal_function(input);
        writer.write_bool(expected);
        if(!writer.good())
            std::cout << "error occcurred at reading!\n";
    }
    writer.close();
}