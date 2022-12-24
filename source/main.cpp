#include <Terminal.hpp>
#include <Shadow.hpp>

/// @defgroup // [A1 sector] TERMINAL
/// @brief create an algorithm (via function) that takes string as param and returns all string of all characters upper-cased
/// @param tr consists of random triplet value
/// @return expected to return triplet with 1st and 3rd value switched
triplet<int> terminal_function(triplet<int> tr) {
    return triplet<int>(
        tr._triplet_unit_3,
        tr._triplet_unit_2,
        tr._triplet_unit_1
    );
}

int main() {

    wrd::Terminal_prcl terminal;    
    terminal.connect(wrd::_TERMINAL_::A_220);
    terminal.hijack(terminal_function);
    terminal.override();

    std::cin.get();
}