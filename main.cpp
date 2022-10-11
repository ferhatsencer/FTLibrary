#include <iostream>
#include <algorithm>

#include "List.h"
#include "Vector.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

//    FerhatLib::Vector<int> *v1;
//    v1->push_back(1);
//    v1->push_back(2);
//    v1->push_back(6);
//    v1->push_back(5);
//    v1->show();
//    v1->replace(4, 0);
//    v1->show();
//    //std::sort(v1->begin(), v1->end(), v1);
//
//    FerhatLib::Vector<char> v2;
//    v2.push_back('A');
//    v2.push_back('b');
//    v2.show();

    FerhatLib::List<int> l = {0, 2, 5};
    l.show();

//    FerhatLib::Vector<char>::iterator it = v2.begin();
//    while (!(it == v2.end())) {
//        std::cout << *it << std::endl;
//        ++it;
//    }
//
//    FerhatLib::List<int> a;
//    a.push_back(44);
//
//    FerhatLib::List<int> b(a);
//    b.show();
//
//    List<int>::iterator it2 = b.begin();
//    while (it2 == b.end()) {
//        cout << *it2 << endl;
//        ++it2;
//    }

    return 0;
}
