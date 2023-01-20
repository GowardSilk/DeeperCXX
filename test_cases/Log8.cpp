#include <LogGen.hpp>
#include <bitset>
#include <string_view>
#include <sstream>

/*
'C' = 01000011
'a' = 01100001
't' = 01110100
's' = 01110011

01000011 01100001 01110100 01110011

6-bit Byte:   1      2       3       4       5       6 
Binary:    010000  110110  000101  110100  011100  110000
Decimal:      16     54      5       52      28      48  
Add 32        +32    +32    +32      +32     +32     +32 
New Dec.      48     86      37      84      60      80 
UUE char:     0      V       %       T       <       P
*/
std::string to_uu_encoding(std::string str) {
    //convert decimal to binary
    std::string bin, ans;
    for(const char& c : str)
        bin += std::bitset<8>(c).to_string();

    if(bin.length() % 6 != 0)
        bin += std::string(6 - (bin.length() % 6), '0');

    for(unsigned i = 0; i < bin.length(); i += 6) 
        ans.push_back(std::bitset<8>(bin.substr(i, 6)).to_ulong() + 32); 

    return ans;
}

int main() {
    //FBR_26_2049_4
    std::string text = "[wrd::___LOC___::A___sector]; [THREAT LVL 4 DETECTED]; [INIT RG_829_PRCL]; [STATUS INFO]: receiving...; [STATUS INFO]: AIR_VALS: <TEMP: 24.5C> <COMP: 77% N, 21% O, 2% UNKNOWN>; [STATUS INFO]: refreshing...; [STATUS INFO]: AIR_VALS: <TEMP: 25.1C> <COMP: 76.5% N, 20.5% O, 3% UNKNOWN>; [STATUS INFO]: refreshing...";
    const std::string addressee = "//::HQ";
    const std::string writer = "//::DEEP_EYE";
    text = to_uu_encoding(text);
    LogGen lg(text, addressee, writer);
    lg.gen_cm_arr(text);
    lg.encode();
    lg.write("Log8.dat");

}