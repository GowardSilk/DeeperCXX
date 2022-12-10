#include "Terminal.hpp"
#include "Reactor.hpp"

wString R_B2(wString ws, int shift) {
    //abc 1 -> bcd
    for(unsigned i = 0; i < ws.size(); i++) {
        symbol s = ws[i];
        if(s + shift > 122) {
            
        } 
    }
}

sString R_B1(wString w1, wString w2) {
    return (sString) {.wString_key = w1, .wString_value = w2};
}

wString R_A1(sString s) {
    return s.wString_key > s.wString_value ? s.wString_key : s.wString_value;
}

TripletContainter<int> T_B3(TripletContainter<int> tr_con) {
    for(unsigned i = 0; i < tr_con.size(); i++) {
        for(unsigned j = 0; j < tr_con.size(); j++) {
            if(tr_con.at(j) > tr_con.at(i)) {
                triplet<int> temp = tr_con.at(j);
                tr_con.at(j) = tr_con.at(i);
                tr_con.at(i) = temp;
            }
        }
    }
    return tr_con;
}

int T_B2_additive(symbol ws) {
    wString alphbt = "abcdefghijklmnopqrstuvwxyz";
    for(unsigned j = 0; j < alphbt.size(); j++) {
        if(alphbt.at(j) == ws) {
            return j+1;
        }
    }
    return alphbt.size();
}

TripletContainter<int> T_B2(TripletContainter<symbol> tr_con) {
    TripletContainter<int> tr_con_final;
    for(unsigned i = 0; i < tr_con.size(); i++) {
        triplet<symbol> tr_temp;
        triplet<int> tr_final;
        tr_final._triplet_unit_1 = T_B2_additive(tr_temp._triplet_unit_1);
        tr_final._triplet_unit_2 = T_B2_additive(tr_temp._triplet_unit_2);
        tr_final._triplet_unit_3 = T_B2_additive(tr_temp._triplet_unit_3);
        tr_con_final.push_back(tr_final);
    }
    return tr_con_final;
}

TripletContainter<int> T_B1(TripletContainter<wString> tr_con) {
    TripletContainter<int> tr_con_final;
    for(unsigned i = 0; i < tr_con.size(); i++) {
        tr_con_final.push_back(to_int(tr_con.at(i)));
    }
    return tr_con_final;
}

triplet<int> T_A (TripletContainter<int> tr_con) {
    triplet<int> tr = tr_con.at(0);
    for(unsigned i = 1; i < tr_con.size(); i++) {
        if(tr_con.at(i) > tr) {
            tr = tr_con.at(i);
        }
    }
    return tr;
}

int main() {
    wrd::Terminal_prcl Terminal;
    Terminal.connect(wrd::_TERMINAL_::A);
    Terminal.hijack(T_A);
    Terminal.override();
    return DEEPER;
}