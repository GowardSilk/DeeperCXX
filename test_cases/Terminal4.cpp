#include "../Terminal.hpp"
#include <random>

int calc_diff(TripletContainer<int>& tr_con, int pos) {
    return abs(tr_con.sum_at(0, std::begin(tr_con)+pos) - tr_con.sum_at(0, std::begin(tr_con)+1+pos));
}

int terminal_function(TripletContainer<int>& tr_con) {
    int max_diff = calc_diff(tr_con, 0);
    for(unsigned i = 1; i < tr_con.size()-1; i++) {
        if(max_diff < calc_diff(tr_con, i))
            max_diff = calc_diff(tr_con, i);
    }
    return max_diff;
}

//rng
int getRND(int from, int to) {
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_real_distribution<float> dis(from, to);
    return dis(gen);
}

int main() {

    std::ofstream wf("Terminal4.dat", std::ios::out | std::ios::binary);
    if(!wf) {
        std::cout << "cannot open file!\n";
        exit(EXIT_FAILURE);
    }

    TripletContainer<int> tr_con_input;
    int expected;
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
        std::vector<triplet<int>> v(
            tr_con_input.begin()+5*i, tr_con_input.begin()+5*i+5
        );
        TripletContainer<int> temp(v);
        expected = terminal_function(temp);
        std::cout << expected << std::endl;
        wf.write((char *) &expected, sizeof(int));
    }

    wf.close();

    if(!wf.good()) {
        std::cout << "error occurred at handling time!\n";
    }

    return DEEPER;
}