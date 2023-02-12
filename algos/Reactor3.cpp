#include <Reactor.hpp>

/// @ingroup [B2 sector] REACTOR
/// \brief create an algorithm (via function)
/// that takes string as param and returns
/// all string of all characters upper-cased
/// @param str consists of only lower-cased characters
/// @return expected return type consits of upper-cases characters
///
wString reactor_function(sString strong_str) {
    wString ans;
    for(unsigned i = 0; i < strong_str.value.length(); i++) {
        char x = strong_str.value.at(i);
        for(unsigned j = 0; j < strong_str.key.length(); j++) {
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