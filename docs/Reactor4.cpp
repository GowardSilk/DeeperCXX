#include <Reactor.hpp>

const char ARR[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};

/**
    @defgroup g2_R_3 [wrd::___LOC___::B3___sector] wrd::___TYPE___::REACTOR
    @ingroup g2_R
    \brief create an algorithm (via function)
    that takes string as param and returns
    string that contains numbers as position
    in alphabet (starting from index 0)
    @param str consists of only lower-cased characters
    @return expected string that contains numbers as position in alphabet
    \code{.cpp} 
        str = "abcde" => [ALGORITHM] => expec_str = "01234"
    \endcode
*/
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