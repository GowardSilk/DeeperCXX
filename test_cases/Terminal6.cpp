#include <Terminal.hpp>
#include <Tester.hpp> //WriteIO
#include <random>

triplet<int> terminal_function(TripletContainer<int> tr_con) {
    std::unordered_set<triplet<int>, triplet_hasher> map;
    for(uint_fast8_t i = 0; i < tr_con.size(); i++) {
        if(map.find(tr_con[i]) != std::end(map))
            return tr_con[i];
        map.insert(tr_con[i]);
    }
    return tr_con[tr_con.size()-1];
}

static std::random_device seeder;
static std::mt19937 gen(seeder());

//rng
int getRND(int from, int to) {
    std::uniform_int_distribution<int> dis(from, to);
    return dis(gen);
}

int main() {

    WriteIO writer("Terminal6.dat");

    TripletContainer<int> input; input.reserve(15);

    for(uint8_t i = 0; i < 10; i++) {

        for(uint8_t n = 0; n < 14; n++)
            input.push_back(triplet<int>(getRND(0, 100), getRND(0, 100), getRND(0, 100)));

        input.push_back(input[input.size()-1]);
        std::shuffle(std::begin(input), std::end(input), gen);

        for(const triplet<int>& tr : input) {
            writer.write_int(tr._triplet_unit_1);
            writer.write_int(tr._triplet_unit_2);
            writer.write_int(tr._triplet_unit_3);
        }

        triplet<int> expected = terminal_function(input);
        writer.write_int(expected._triplet_unit_1);
        writer.write_int(expected._triplet_unit_2);
        writer.write_int(expected._triplet_unit_3);

        if(!writer.good())
            std::cout << "error occcurred at writing!\n";

        input.clear();
    }
    writer.close();
}