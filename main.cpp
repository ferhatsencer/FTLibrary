#include <iostream>
#include <algorithm>

#include "List.h"
#include "Vector.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    auto *v1 = new FerhatLib::Vector<int>();

    v1->push_back(1);
    v1->push_back(2);
    v1->push_back(6);
    v1->push_back(5);
    v1->show();
    v1->replace(4, 0);
    v1->show();
    //std::sort(v1->begin(), v1->end(), v1);
//    if (!std::binary_search(v1->begin(), v1->end(), 5))
//        std::cout << "Removed!" << std::endl;


    FerhatLib::Vector<char> v2;
    v2.push_back('A');
    v2.push_back('b');
    v2.show();

    FerhatLib::Vector<char>::iterator it = v2.begin();
    while (!(it == v2.end())) {
        std::cout << *it << std::endl;
        ++it;
    }

    FerhatLib::List<int> a;
    a.push_back(44);
    a.push_back(45);
    a.show();

    FerhatLib::List<int> b(a);
    b.show();

    FerhatLib::List<int> l1 = {0, 2, 5};
    l1.show();

    FerhatLib::List<int> l2;
    l2.push_back(32);
    l2.push_back(33);
    l2.show();
    

    return 0;
}
