#include "DeepMain.hpp"
#include <random>
#include <time.h>

triplet<int> T_A (std::vector<triplet<int>> tr_con) {
    triplet<int> tr = tr_con.at(0);
    for(unsigned i = 1; i < tr_con.size(); i++) {
        if(tr_con.at(i) > tr) {
            tr = tr_con.at(i);
        }
    }
    return tr;
}

//rng
int getRND(int from, int to) {
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_real_distribution<float> dis(from, to);
    return dis(gen);
}

int main(void) {

    std::ofstream wf("Terminal.dat", std::ios::out | std::ios::binary);
    if(!wf) {
        std::cout << "cannot open file!\n";
        exit(EXIT_FAILURE);
    }

    TripletContainer<int> tr_con_input;
    triplet<int> tr_expected;
    //write all test cases
    for(unsigned t = 0; t < 10; t++) {
        //one test case...
        for(unsigned n = 0; n < 5; n++) {
            triplet<int> tr = {
                ._triplet_unit_1 = getRND(1, 1000),
                ._triplet_unit_2 = getRND(1, 1000),
                ._triplet_unit_3 = getRND(1, 1000)
            };
            tr_con_input.push_back(tr);
        }
    }

    //for each test case
    for(unsigned i = 0; i < 10; i++) {
        printf("------[%d]------\n", i);
        //write input
        for(unsigned j = 5*i; j < (5*i)+5; j++) {
            const auto& x = tr_con_input.at(j);
            printf("---{%d, %d, %d}---\n",
                        x._triplet_unit_1,
                        x._triplet_unit_2,
                        x._triplet_unit_3
                    );
            wf.write((char *) &x, sizeof(triplet<int>));
        }
        //write expected output
        std::vector<triplet<int>> temp(
            tr_con_input.begin()+5*i, tr_con_input.begin()+5*i+5
        );
        tr_expected = T_A(temp);
        printf("Expected output: {%d, %d, %d}\n",
                    tr_expected._triplet_unit_1,
                    tr_expected._triplet_unit_2,
                    tr_expected._triplet_unit_3
                );
        wf.write((char *) &tr_expected, sizeof(triplet<int>));  
    }

    wf.close();

    if(!wf.good()) {
        std::cout << "error occurred at handling time!\n";
    }

    // std::ifstream rf("Terminal.dat", std::ios::out | std::ios::binary);
    // if(!rf) {
    //     std::cout << "cannot read file!\n";
    // }

    // for(unsigned i = 0; i < 10; i++) {
    //     TripletContainer<int> tr_con_input;
    //     for(unsigned i = 0; i < 5; i++) {
    //         triplet<int> tr_temp;
    //         rf.read((char*) &tr_temp, sizeof(triplet<int>));
    //         printf("---{%d, %d, %d}---\n",
    //                     tr_temp._triplet_unit_1,
    //                     tr_temp._triplet_unit_2,
    //                     tr_temp._triplet_unit_3
    //                 );
    //         tr_con_input.push_back(tr_temp);
    //     }

    //     triplet<int> tr_expected;
    //     rf.read((char*) &tr_expected, sizeof(triplet<int>));
    //     std::cout << "tr_expected: " << tr_expected._triplet_unit_1 << "," 
    //     << tr_expected._triplet_unit_2 << "," << tr_expected._triplet_unit_3 << std::endl;

    //     if(!rf.good()) {
    //         std::cout << "error occurred at reading time!\n";
    //     }
    // }

    return DEEPER;
}