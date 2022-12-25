#include <Terminal.hpp>

/**
    @defgroup g2_T_2 [wrd::___LOC___::B2___sector] wrd::___TYPE___::TERMINAL
    @ingroup  g2_T
    \brief
    create an algorithm (via function)
    that takes TripletContainer as param and returns
    the highest triplet from given container
    @param tr_con consists of random triplets
    @return expected the highest triplet
    \code{.cpp}
        tr_con = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        } => [ALGORITHM] => expec_tr = {7, 8, 9}
    \endcode
*/
triplet<int> terminal_func(TripletContainer<int> tr_con) {
    triplet<int> tr = tr_con.at(0);
    for(unsigned i = 1; i < tr_con.size(); i++) {
        if(tr_con.at(i) > tr) {
            tr = tr_con.at(i);
        }
    }
    return tr;
}

int main() {

    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::B_301);
    terminal.hijack(terminal_func);
    terminal.override();

    return DEEPER;
}