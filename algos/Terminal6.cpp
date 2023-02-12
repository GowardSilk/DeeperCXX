#include <Terminal.hpp>

triplet<int> terminal_function(TripletContainer<int> tr_con) {
    std::unordered_set<triplet<int>, triplet_hasher> map;
    for(triplet<int> tr : tr_con) {
        if(map.find(tr) != std::end(map))
            return tr;
        map.insert(tr);
    }
}

int main() {
    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::C_246);
    terminal.hijack(terminal_function);
    terminal.override();
}