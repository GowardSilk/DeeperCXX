#include "../DeepMain.hpp"
#include "../Reactor.hpp"

wString reactor_A_func(wString input) {
    wString ans;
    for(unsigned i = 0; i < input.length(); i++) {
        char a = input.at(i), b = input.at(i-1);
        if(b == 45 || b == 95) {
            a = toupper(a);
        }
        if(a != '_' && a != '-') {
            ans += a;
        }
    }
    return ans;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::IMPACT_v1_2A);
    reactor.hijack(reactor_A_func);
    reactor.override();

    return DEEPER;
}