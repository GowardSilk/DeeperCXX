#include <Terminal.hpp>

/**
    @defgroup g3_T_2 [wrd::___LOC___::B2___sector] wrd::___TYPE___::TERMINAL
    @ingroup  g3_T
    \brief
    create an algorithm (via function)
    that takes TripletContainer as param and returns
    (THE ONLY) triplet that occurred twice in the array
    @param tr_con consists of random triplets (1 <= n <= 100)
    @return expected triplet
    \code{.cpp}
        tr_con = {
            {1, 2, 3},
            {4, 5, 6},
            {1, 2, 3},
            {7, 8, 9}
        } => [ALGORITHM] => expected_tr = {1, 2, 3}
    \endcode
*/
triplet<int> terminal_function(TripletContainer<int> tr_con) {
    std::unordered_map<triplet<int>, int> map;
    for(triplet<int> tr : tr_con) {
        if(map[tr] != 0) {
            return tr;
        }
    }
}

int main() {
    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::C_246);
    terminal.hijack(terminal_function);
    terminal.override();
}