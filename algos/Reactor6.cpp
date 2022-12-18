#include "../Reactor.hpp"

int reactor_function(wString str) {
    const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
    int final_count = 0;
    for(char ch : str)
    {
        // if(vowels.contains(Char.ToLower(ch)))
        //     final_count++;
        for(unsigned short i = 0; i < 5; i++) {
            if(vowels[i] == ch) {
                final_count++;
                break;
            }
        }
    }
    return final_count;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::MARSCHAL_v014);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}