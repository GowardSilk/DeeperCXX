#include "../Terminal.hpp"

int terminal_function(triplet<int> tr_con) {
    int sum = tr_con._triplet_unit_1 + tr_con._triplet_unit_2 + tr_con._triplet_unit_3;
    std::string bin;
    while(sum != 0) {
        bin = (sum % 2 == 0 ? "0" : "1") + bin;
        sum /= 2;
    }
    return std::stoi(bin);
}

int main() {
    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::C_954);
    terminal.hijack(terminal_function);
    terminal.override();
}