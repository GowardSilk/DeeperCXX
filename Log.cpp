#include "DEEP_EYE.hpp"
#include "Log.hpp"

int main() {
    //create access_key element --> problby from terminal
    access_key key = "BUCKLAND";
    //get specific log based on that key
    wrd::Log log = DeepEye::get_access(key);
    //ALGORITHM
    //  gather information about the log such as CodeMatrix
    //  CodeMatrix layout example:
    //  {
    //    'a', 'b', 'c', 'd',
    //    'e', 'f', 'g', 'h',
    //    'i', 'j', 'k', 'l',
    //    'm', 'n', 'o', 'p',
    //    'q', 'r', 's', 't',
    //    'u', 'v', 'w', 'x',
    //    'y', 'z'
    //  }
    //
    CodeMatrix letter_map = log.getCodeMatrix();
    //  every challenge will be different but
    //  the core concepts lies in the workings with the CodeMatrix
    //1.  get the corrupted message
    wrd::Message msg = log.getMessage();
    for(unsigned i = 0; i < mgs.length(); i++) {
        Vector2u pos = msg.at(i);
        log.insert_at(letter_map.get_symbol(pos));
    }
    DeepEye::read(log);
    return DEEPER;
}