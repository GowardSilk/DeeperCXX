#include "../Terminal.hpp"
#include <random>

TripletContainer<int> terminal_function(TripletContainer<int> tr_con) {
    std::sort(std::begin(tr_con), std::end(tr_con), [](triplet<int>& tr1, triplet<int>& tr2){
        return tr1 < tr2;
    });
    return tr_con;
}

//rng
int getRND(int from, int to) {
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_int_distribution<int> dis(from, to);
    return dis(gen);
}

int main() {

    std::ofstream wf("Terminal5.dat", std::ios::out | std::ios::binary);
    if(!wf) {
        std::cout << "cannot open file!\n";
        exit(EXIT_FAILURE);
    }

    TripletContainer<int> input;
    TripletContainer<int> expected;
    //write all test cases
    for(unsigned t = 0; t < 10; t++) {
        //one test case...
        for(unsigned n = 0; n < 15; n++) {
            triplet<int> tr = {
                ._triplet_unit_1 = getRND(1, 1000),
                ._triplet_unit_2 = getRND(1, 1000),
                ._triplet_unit_3 = getRND(1, 1000)
            };
            std::cout << tr << std::endl;
            input.push_back(tr);
            wf.write((char *) &tr, sizeof(triplet<int>));
        }
        expected = terminal_function(input);
        for(unsigned n = 0; n < 15; n++) {
            wf.write((char *) &expected.at(n), sizeof(triplet<int>));
        }
    }

    wf.close();

    if(!wf.good()) {
        std::cout << "error occurred at handling time!\n";
    }
}