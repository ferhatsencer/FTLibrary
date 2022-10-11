////
//// Created by Ferhat Sencer on 9/28/22.
////
//
//#include "gtest/gtest.h"
//
//#include "Vector.h"
//#include "List.h"
//
//TEST(Vector, 0)
//{
//Vector<char> v;
//Vector<char> temp = v;
//
//v.push_back('a');
//v.push_back('x');
//v.push_back('z');
//
//EXPECT_EQ(v.getElement(0), temp.getElement(0));
//EXPECT_EQ(v.getElement(1), temp.getElement(1));
//EXPECT_EQ(v.getElement(2), temp.getElement(2));
//}
//
//TEST(Vector, 0)
//{
//    Vector<int> v;
//
//    v.push_back(1);
//    EXPECT_EQ(1, *v.begin());
//
//    v[0] = -1;
//    Vector<int>::iterator itr = v.begin();
//    EXPECT_EQ(-1, *itr);
//
//    ++itr;
//    EXPECT_EQ(2, *itr);
//
//    v.push_back(5);
//    ++itr;
//    EXPECT_EQ(5, *itr);
//}