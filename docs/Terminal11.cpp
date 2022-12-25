#include <Terminal.hpp>

/**
    @defgroup g4_T_3 [wrd::___LOC___::D3___sector] wrd::___TYPE___::TERMINAL
    @ingroup  g4_T
    \brief
        create an algorithm (via function)
        that takes triplet as param and returns
        triplet with 1st and 3rd value exchanged
        @param tr consists of random number (1 <= n <= 100)
        @return expected triplet
*/
triplet<int> terminal_function(TripletContainer<int> tr_con) {
    std::unordered_map<triplet<int>, int> m;
    for(triplet<int> tr : tr_con) {
        m[tr]++;
    }
    int max = 0;
    triplet<int> max_elem = tr_con[max];
    for(const auto x : m) {
        if(max < x.second) {
            max = x.second;
            max_elem = x.first;
        }
    }
    return max_elem;
}

int main() {

    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::D_230);
    terminal.hijack(terminal_function);
    terminal.override();

    return DEEPER;
}