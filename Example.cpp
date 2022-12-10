#include "DeepMain.hpp"

int main() {

    TripletContainer<int> tr_con;
    tr_con.push_back(1, 2, 3);
    tr_con.push_back(4, 5, 6);
    tr_con.push_back(7, 8, 9);

    std::cout << "tr_con has size of: " << tr_con.size() << "\n";

    return DEEPER;
}
