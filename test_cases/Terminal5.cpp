#include <Terminal.hpp>
#include <random>

TripletContainer<int> terminal_function(TripletContainer<int> tr_con) {
    for(int i = 0; i < tr_con.size() ; i++) {		
		for(int j = i + 1; j < tr_con.size(); j++) {
			if(tr_con[i] > tr_con[j]) {
				auto temp = tr_con[i];
				tr_con[i] = tr_con[j];
				tr_con[j] = temp;
			}
		}
	}
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

    TripletContainer<int> input; input.reserve(15);
    TripletContainer<int> expected; expected.reserve(15);
    //write all test cases
    for(unsigned t = 0; t < 10; t++) {
        //one test case...
        printf_s("TEST_CASE #%i\n", t);
        std::cout << "BEFORE\n";
        for(unsigned n = 0; n < 15; n++) {
            triplet<int> tr(getRND(1, 1000), getRND(1, 1000), getRND(1, 1000));
            input.push_back(tr);
            std::cout << input.sum_at(0, std::begin(input)+n) << std::endl;
            wf.write((char *) &tr, sizeof(triplet<int>));
        }
        std::cout << "AFTER\n";
        expected = terminal_function(input);
        for(unsigned n = 0; n < 15; n++) {
            std::cout << expected.sum_at(0, std::begin(expected)+n) << std::endl;
            wf.write((char *) &expected.at(n), sizeof(triplet<int>));
        }
        std::cout << "----------------\n";
        input.clear();
        expected.clear();
    }

    wf.close();

    if(!wf.good()) {
        std::cout << "error occurred at handling time!\n";
    }
}