#include <Terminal.hpp>

int terminal_function(triplet<int> tr_con) {
    int sum = tr_con._triplet_unit_1 + tr_con._triplet_unit_2 + tr_con._triplet_unit_3;
    int count = 0;
    while(sum != 0) {
        if(sum % 2 == 1)
            count++;
        sum /= 2;
    }
    return count;
}

int main() {
    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::C_282);
    terminal.hijack(terminal_function);
    terminal.override();
}