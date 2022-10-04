//
//  main.cpp
//  Binary Tree ADT
//
//  Created by blane on 9/28/22.
//

#include <iostream>
using namespace std;
#include <sstream>
#include <string>
#include "btree.h"

int main() {
    string input;
    getline(cin, input);
    
    int num;
    stringstream ss(input);
    
    btree tree;
    
    while(ss>>num) {
        tree.insert(num);
    }
 

    tree.print();

    cout << endl;
    
    return 0;
}
