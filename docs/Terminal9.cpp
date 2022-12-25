#include <Terminal.hpp>

/**
    @defgroup g4_T_1 [wrd::___LOC___::D1___sector] wrd::___TYPE___::TERMINAL
    @ingroup  g4_T
    \brief
    create an algorithm (via function)
    that takes triplet as param and returns
    boolean if the triplet is prime
    @param tr consists of random number (1 <= n <= 100)
    @return expected boolean value
    \code{.cpp}
        tr = {1, 2, 3} => [is_prime(1 + 2 + 3)] => bool b = false
    \endcode
*/
bool terminal_function(triplet<int> tr) {
    int sum = tr._triplet_unit_1 + tr._triplet_unit_2 + tr._triplet_unit_3;
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