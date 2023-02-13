#include <Terminal.hpp>

triplet<int> terminal_function(TripletContainer<int> tr_con) {
    std::unordered_map<triplet<int>, int, triplet_hasher> m;
    for(triplet<int> tr : tr_con) {
        if(m.find(tr) != std::end(m)) { m[tr]++; }
        else { m.insert({tr, 0}); }
    }
    int max = 0;
    triplet<int> max_elem = tr_con[max];
    for(const auto& x : m) {
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