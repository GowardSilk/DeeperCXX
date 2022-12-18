#include "../Terminal.hpp"

bool terminal_function(triplet<int> tr_con) {
    int sum = tr_con._triplet_unit_1 + tr_con._triplet_unit_2 + tr_con._triplet_unit_3;
    if(sum <= 1)
        return false;
    for(int i = 2; i <= std::sqrt(sum); i++) {
        if(sum % i == 0)
            return false;
    }
    return true;
}

int main() {
    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::D_702);
    terminal.hijack(terminal_function);
    terminal.override();
}