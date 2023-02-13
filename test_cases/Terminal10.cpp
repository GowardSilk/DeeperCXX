#include <Terminal.hpp>
#include <Tester.hpp>
#include <random>

static WriteIO writer("Terminal10.dat");
static std::random_device seeder;
static std::mt19937 gen(seeder());

bool find(TripletContainer<int>& tr_con, triplet<int>& tr) {
    for(const auto& x : tr_con) {
        if(x == tr) { return true; }
    }
    return false;
}

void terminal_function(TripletContainer<int> tr_con) {
    TripletContainer<int> new_tr_con(5);
    for(uint_fast8_t i = 0; i < tr_con.size(); i++) {
        if(!find(new_tr_con, tr_con[i]))
            new_tr_con.push_back(tr_con[i]);
    }
    for(const auto& tr : new_tr_con) {
        writer.write_int(tr._triplet_unit_1);
        writer.write_int(tr._triplet_unit_2);
        writer.write_int(tr._triplet_unit_3);
        if(!writer.good())
            std::cout << "ggs\n";
    }
}

//rng
int getRND(int from, int to) {
    std::uniform_int_distribution<int> dis(from, to);
    return dis(gen);
}

int main() {
    TripletContainer<int> input(15);
    TripletContainer<int> expected(15);
    for(unsigned short i = 0; i < 10; i++) {
        printf_s("TEST #%i", i);
        for(uint8_t j = 0; j < 5; j++)
            input.push_back(triplet<int>(getRND(0, 100), getRND(0, 100), getRND(0, 100)));
        for(uint8_t j = 0; j < 10; j++)
            input.push_back(input.at(getRND(0, 5)));
        std::shuffle(std::begin(input), std::end(input), gen);
        for(const auto& tr : input) {
            writer.write_int(tr._triplet_unit_1);
            writer.write_int(tr._triplet_unit_2);
            writer.write_int(tr._triplet_unit_3);
        }
        terminal_function(input);
        input.clear();
    }
    writer.close();
}