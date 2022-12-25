#include <Reactor.hpp>

/**
    @defgroup g3 [wrd::___LOC___::C___sector]
*/

/**
 * @defgroup g3_T wrd::___TYPE___::TERMINAL
 * @ingroup g3
*/

/**
 * @defgroup g3_R wrd::___TYPE___::REACTOR
 * @ingroup g3
*/

/**
    @defgroup g3_R_1 [wrd::___LOC___::C1___sector] wrd::___TYPE___::REACTOR
    @ingroup g3_R
    @{
        \brief create an algorithm (via function)
        that takes string, int as param and returns
        string that has all letters shifted (by that int val)
        @param str consists of only lower-cased characters
        @param shift indicates how many times letters have to be shifted
        @return expected return type consits of upper-cases characters
        \code{.cpp}
           str = "bcde"
           shift = 1
           ....[ALGORITHM]....
           expec_str = "abcd"
        \endcode
    @}
*/
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