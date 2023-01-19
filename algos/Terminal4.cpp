#include <Terminal.hpp>

int calc_diff(TripletContainer<int>& tr_con, int pos) {
    return abs(tr_con.sum_at(0, std::begin(tr_con)+pos) - tr_con.sum_at(0, std::begin(tr_con)+1+pos));
}

int terminal_function(TripletContainer<int> tr_con) {
    int max_diff = calc_diff(tr_con, 0);
    for(unsigned i = 1; i < tr_con.size()-1; i++) {
        if(max_diff < calc_diff(tr_con, i))
            max_diff = calc_diff(tr_con, i);
    }
    return max_diff;
}

int main() {

    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::B_524);
    terminal.hijack(terminal_function);
    terminal.override();

    return DEEPER;
}