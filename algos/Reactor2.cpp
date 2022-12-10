#include "../Reactor.hpp"

wString reactor_function(wString str) {
    for(unsigned i = 0; i < str.length(); i++) {
        if(islower(str.at(i)))
            str.at(i) -= 32;
        else
            str.at(i) += 32;
    }
    return str;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::IMPACT_v0_9);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}