#include "../Terminal.hpp"

triplet<int> terminal_function(triplet<int> tr) {
    int temp = tr._triplet_unit_1;
    tr._triplet_unit_1 = tr._triplet_unit_3;
    tr._triplet_unit_3 = temp;
    return tr;
}

int main() {

    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::A_220);
    terminal.hijack(terminal_function);
    terminal.override();

    return DEEPER;
}