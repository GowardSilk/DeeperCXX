#include <Terminal.hpp>
#include <Shadow.hpp>

triplet<int> terminal_function(triplet<int> tr) {
    return triplet<int>(
        tr._triplet_unit_3,
        tr._triplet_unit_2,
        tr._triplet_unit_1
    );
}

int main() {

    wrd::Terminal_prcl terminal;
    wrd::Shadow_prcl<triplet<int>, triplet<int>> shadow;
    shadow.disconnect(terminal);
    
    terminal.connect(wrd::_TERMINAL_::A_220);
    terminal.hijack(terminal_function);
    terminal.override();

    std::cin.get();
}