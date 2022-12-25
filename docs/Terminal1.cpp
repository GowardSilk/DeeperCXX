#include <Terminal.hpp>

/**
    @defgroup g1_T_1 [wrd::___LOC___::A1___sector] wrd::___TYPE___::TERMINAL
    @ingroup  g1_T
    \brief
    create an algorithm (via function)
    that takes triplet as param and returns
    triplet with 1st and 3rd value exchanged
    @param tr consists of 3 random numbers (1 <= n <= 100)
    @return expected triplet
    \code{.cpp}
        tr = {1, 2, 3} => [ALGORITHM] => expec_tr = {3, 2, 1}
    \endcode
*/
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