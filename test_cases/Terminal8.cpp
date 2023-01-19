#include <Terminal.hpp>
#include <Tester.hpp>
#include <random>

int terminal_function(triplet<int> tr_con) {
    int sum = tr_con._triplet_unit_1 + tr_con._triplet_unit_2 + tr_con._triplet_unit_3;
    int count = 0;
    while(sum != 0) {
        if(sum % 2 == 1)
            count++;
        sum /= 2;
    }
    return count;
}

//rng
int getRND(int from, int to) {
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_int_distribution<int> dis(from, to);
    return dis(gen);
}

int main() {
    WriteIO writer("Terminal8.dat");
    for(unsigned short i = 0; i < 10; i++) {
        triplet<int> input = {
            ._triplet_unit_1 = getRND(1, 100),
            ._triplet_unit_2 = getRND(1, 100),
            ._triplet_unit_3 = getRND(1, 100),
        };
        writer.write_int(input._triplet_unit_1);
        writer.write_int(input._triplet_unit_2);
        writer.write_int(input._triplet_unit_3);
        int expected = terminal_function(input);
        writer.write_int(expected);
        if(!writer.good())
            std::cout << "error occcurred at reading!\n";
    }
    writer.close();
}