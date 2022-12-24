#include <Reactor.hpp>

/// @defgroup [C1 sector] REACTOR
/// \brief create an algorithm (via function)
/// that takes string as param and returns
/// all string of all characters upper-cased
/// @param str consists of only lower-cased characters
/// @return expected return type consits of upper-cases characters
///
wString reactor_function(wString str, int shift) {
    wString ans;
    if(shift >= 26) { shift %= 26; }
    std::for_each(std::begin(str), std::end(str), [&](char c) {
        if(c - shift < 'a') {
            int i;
            for(i = shift; c >= 'a'; c--, i--);
            c = 'z' - i;
        }
        else { c -= shift; }
        ans.push_back(c);
    });
    return ans;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::MARSCHAL_v014);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}