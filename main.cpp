#include <iostream>
#include <algorithm>

#include "FList.h"
#include "FVector.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    FVector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(6);
    v1.push_back(5);
    v1.show();
    v1.replace(4, 0);
    v1.show();
    //std::sort(v1.begin(), v1.end());

    FVector<char> v2;
    v2.push_back('A');
    v2.push_back('b');
    v2.show();

    FVector<char>::iterator it = v2.begin();
    while (!(it == v2.end())) {
        std::cout << *it << std::endl;
        ++it;
    }

    FList<int> a;
    a.push_back(44);

    FList<int> b(a);
    b.show();
//
//    FList<int>::iterator it2 = b.begin();
//    while (it2 == b.end()) {
//        cout << *it2 << endl;
//        ++it2;
//    }

    return 0;
}
