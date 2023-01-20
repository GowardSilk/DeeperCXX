#include <Terminal.hpp>

triplet<int> terminal_function(triplet<int> tr) {
    return triplet<int>(tr._triplet_unit_3, tr._triplet_unit_1, tr._triplet_unit_2);
    // return (triplet<int>) {
    //     ._triplet_unit_1 = tr._triplet_unit_3,
    //     ._triplet_unit_2 = tr._triplet_unit_1,
    //     ._triplet_unit_3 = tr._triplet_unit_2
    // };
}

int main() {

    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::B_236);
    terminal.hijack(terminal_function);
    terminal.override();

    return DEEPER;
}