#include <Terminal.hpp>


/**
    @defgroup g2_T_1 [wrd::___LOC___::B1___sector] wrd::___TYPE___::TERMINAL
    @ingroup  g2_T
    \brief
    create an algorithm (via function)
    that takes triplet as param and returns
    triplet with all values shifted (from left to right)
    @param tr consists of random number (1 <= n <= 100)
    @return expected triplet
    \code{.cpp}
        tr = {1, 2, 3} => [ALGORITHM] => expec_tr = {3, 1, 2}
    \endcode
*/
triplet<int> terminal_function(triplet<int> tr) {
    return triplet<int> (
        /*._triplet_unit_1*/ tr._triplet_unit_3,
        /*._triplet_unit_2*/ tr._triplet_unit_1,
        /*._triplet_unit_3*/ tr._triplet_unit_2
    );
}

int main() {

    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::B_236);
    terminal.hijack(terminal_function);
    terminal.override();

    return DEEPER;
}