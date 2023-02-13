#include <DeepMain.hpp>
#include <Tester.hpp>
#include <random>

triplet<int> terminal_function(TripletContainer<int> tr_con) {
    std::unordered_map<triplet<int>, int, triplet_hasher> m;
    for(triplet<int> tr : tr_con) {
        if(m.find(tr) != std::end(m)) { m[tr]++; }
        else { m.insert({tr, 0}); }
    }
    int max = 0;
    triplet<int> max_elem = tr_con[max];
    for(const auto& x : m) {
        if(max < x.second) {
            max = x.second;
            max_elem = x.first;
        }
        std::cout << "{" << x.first._triplet_unit_1 + x.first._triplet_unit_2 + x.first._triplet_unit_3 << "," << x.second << "}" << std::endl;
    }
    return max_elem;
}

static std::random_device seeder;
static std::mt19937 gen(seeder());

//rng
int getRND(int from, int to) {
    std::uniform_int_distribution<int> dis(from, to);
    return dis(gen);
}

int main() {
    WriteIO writer("Terminal11.dat");
    TripletContainer<int> input; input.reserve(15);
    for(uint_fast8_t i = 0; i < 10; i++) {
        std::cout << "TEST #" << (int)i << std::endl;
        int rand_sz = getRND(5, 10);
        for(uint_fast8_t n = 0; n < rand_sz; n++) {
            input.push_back(
                triplet<int>(getRND(0, 100), getRND(0, 100), getRND(0, 100))
            );
            writer.write_int(input.at(n)._triplet_unit_1);
            writer.write_int(input.at(n)._triplet_unit_2);
            writer.write_int(input.at(n)._triplet_unit_3);
            std::cout << input.sum_at(0, std::begin(input) + n) << ",";
        }
        for(uint_fast8_t n = rand_sz; n < 15; n++) {
            input.push_back(
                input.at(getRND(0, rand_sz))
            );
            writer.write_int(input.at(n)._triplet_unit_1);
            writer.write_int(input.at(n)._triplet_unit_2);
            writer.write_int(input.at(n)._triplet_unit_3);
            std::cout << input.sum_at(0, std::begin(input) + n) << ",";
        }
        std::cout << std::endl;
        triplet<int> expec = terminal_function(input);
        writer.write_int(expec._triplet_unit_1);
        writer.write_int(expec._triplet_unit_2);
        writer.write_int(expec._triplet_unit_3);
        std::cout << expec._triplet_unit_1 + expec._triplet_unit_2 + expec._triplet_unit_3 << std::endl;
        input.clear();
    }
    writer.close();
}