#include <Terminal.hpp>
#include <Tester.hpp>
#include <random>

bool find(unsigned& index, TripletContainer<int>& tr_con) {
    for(unsigned j = 0; j < tr_con.size(); j++) {
        if(index != j && tr_con.at(index) == tr_con.at(j)) {
            return true;
        }
    }
    return false;
}

TripletContainer<int> terminal_function(TripletContainer<int> tr_con) {
    TripletContainer<int> new_tr_con(tr_con.size());
    for(unsigned i = 0; tr_con.size(); i++) {
        if(!find(i, tr_con))
            new_tr_con.push_back(tr_con.at(i));
    }
    return new_tr_con;
}

//rng
int getRND(int from, int to) {
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_int_distribution<int> dis(from, to);
    return dis(gen);
}

int main() {
    WriteIO writer("Terminal10.dat");
    for(unsigned short i = 0; i < 10; i++) {
        TripletContainer<int> input(15);
        for(unsigned short j = 0; j < 15; j++) {
            triplet<int> tr = {
                ._triplet_unit_1 = getRND(1, 100),
                ._triplet_unit_2 = getRND(1, 100),
                ._triplet_unit_3 = getRND(1, 100),
            };
            writer.write_int(tr._triplet_unit_1);
            writer.write_int(tr._triplet_unit_2);
            writer.write_int(tr._triplet_unit_3);
            input.push_back(tr);
        }
        TripletContainer<int> expected = terminal_function(input);
        for(unsigned j = 0; j < expected.size(); j++) {
            writer.write_int(expected.at(i)._triplet_unit_1);
            writer.write_int(expected.at(i)._triplet_unit_2);
            writer.write_int(expected.at(i)._triplet_unit_3);
        }
        if(!writer.good())
            std::cout << "error occcurred at reading!\n";
    }
    writer.close();
}