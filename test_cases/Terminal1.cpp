#include <Terminal.hpp>
#include <random>

triplet<int> terminal_function(triplet<int>& tr) {
    int temp = tr._triplet_unit_1;
    tr._triplet_unit_1 = tr._triplet_unit_3;
    tr._triplet_unit_3 = temp;
    return tr;
}

//rng
int getRND(int from, int to) {
    static std::random_device seeder;
    static std::mt19937 gen(seeder());
    std::uniform_real_distribution<float> dis(from, to);
    return dis(gen);
}

int main() {

    std::ofstream wf("Terminal1.dat", std::ios::out | std::ios::binary);
    if(!wf) {
        std::cout << "cannot open file!\n";
        exit(EXIT_FAILURE);
    }

    TripletContainer<int> INPUT;
    //for each test case...
    for(unsigned i = 0; i < 10; i++) {
        //every test case 
        //need 1 triplet
        triplet<int> tr;
        tr._triplet_unit_1 = getRND(1, 100);
        tr._triplet_unit_2 = getRND(1, 100);
        tr._triplet_unit_3 = getRND(1, 100);
        INPUT.push_back(tr);
    }

    //write test cases
    for(unsigned i = 0; i < 10; i++) {
        printf("------[%d]------\n", i);
        //write input
        wf.write((char *) &INPUT[i], sizeof(triplet<int>));
        printf("input: {[%d],[%d],[%d]}\n",
                    INPUT[i]._triplet_unit_1,
                    INPUT[i]._triplet_unit_2,
                    INPUT[i]._triplet_unit_3);
        //write expected output
        triplet<int> expected = terminal_function(INPUT[i]);
        printf("expected output: {[%d],[%d],[%d]}\n",
                    expected._triplet_unit_1,
                    expected._triplet_unit_2,
                    expected._triplet_unit_3);
        wf.write((char *) &expected, sizeof(triplet<int>));
    }

    wf.close();

    if(!wf.good()) {
        std::cout << "error occurred at handling time!\n";
    }

    return DEEPER;
}