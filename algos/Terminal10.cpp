#include <Terminal.hpp>

bool find(TripletContainer<int>& tr_con, triplet<int>& tr) {
    for(const auto& x : tr_con) {
        if(x == tr) { return true; }
    }
    return false;
}

TripletContainer<int> terminal_function(TripletContainer<int> tr_con) {
    TripletContainer<int> new_tr_con(5);
    for(uint_fast8_t i = 0; i < tr_con.size(); i++) {
        if(!find(new_tr_con, tr_con[i]))
            new_tr_con.push_back(tr_con[i]);
    }
    return new_tr_con;
}

int main() {
    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::D_443);
    terminal.hijack(terminal_function);
    terminal.override();
}