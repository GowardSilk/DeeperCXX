#include "../Reactor.hpp"

wString reactor_function(sString strong_str) {
    wString ans;
    for(unsigned i = 0; i < strong_str.value.length(); i++) {
        const char x = strong_str.value.at(i);
        for(unsigned j = 0; j < strong_str.key.length(); i++) {
            if(x == strong_str.key.at(j)) {
                ans.push_back(x);
                break;
            }
        }
    }
    return ans;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::TWINX_B);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}