#include "../Reactor.hpp"

const char ARR[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};

wString reactor_function(wString str) {
    wString ans;
    for(unsigned i = 0; i < str.length(); i++) {
        for(unsigned j = 0; j < 26; j++) {
            if(str.at(i) == ARR[j])
                ans += std::to_string(j+1);
        }
    }
    return ans;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::COLOSSUS_v0_5);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}