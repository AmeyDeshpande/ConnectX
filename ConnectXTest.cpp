/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(ConnectXTest, TestConstructorOnWidth)
{
  ConnectX temp(-12,12,3);
	ASSERT_EQ(0, temp.at(3,3) );
}
TEST(ConnectXTest, TestConstructorOnHeight)
{
  ConnectX temp(12,-3,3);
	ASSERT_EQ(0, temp.at(3,3 ));
}
TEST(ConnectXTest, TestConstructorOnToWin)
{
  ConnectX temp(12,0,-2);
	ASSERT_EQ(0, temp.at(3,3) );
}
TEST(ConnectXTest, checkWidth)
{
  ConnectX temp(12,12,3);
	ASSERT_EQ(-1, temp.at(-12,12) );
}
TEST(ConnectXTest, checkHeight)
{
  ConnectX temp(12,12,3);
	ASSERT_EQ(-1, temp.at(12,-12) );
}
TEST(ConnectXTest, checkAtWidth)
{
  ConnectX temp(12,12,3);
  ASSERT_EQ(-1, temp.at(20,11) );
}
TEST(ConnectXTest, checkAtHeight)
{
  ConnectX temp(12,12,3);
	ASSERT_EQ(-1, temp.at(11,20) );
}
TEST(ConnectXTest, checkEmpty)
{
  ConnectX temp(12,12,3);
	ASSERT_EQ(0, temp.at(11,11) );
}
TEST(ConnectXTest, placePiece)
{
  ConnectX temp(12,12,3);
  temp.placePiece(3);
	ASSERT_EQ(2, temp.at(3,11) );
}
TEST(ConnectXTest, placePieceToCheckAt)
{
  ConnectX temp(12,12,3);
  temp.placePiece(3);
  temp.placePiece(3);
  ASSERT_EQ(2, temp.at(3,11) );
  ASSERT_EQ(1, temp.at(3,10) );
}
TEST(ConnectXTest, placeToCheckOutBoundWidth)
{
  ConnectX temp(12,12,3);
  temp.placePiece(20);
	ASSERT_EQ(0, temp.at(3,0) );
  ASSERT_EQ(2, temp.at(3,0) );
}
TEST(ConnectXTest, placeToCheckOutBoundColumn)
{
  ConnectX temp(3,3,3);
  temp.placePiece(2);
  temp.placePiece(2);
  temp.placePiece(2);
  temp.placePiece(2);
  ASSERT_EQ(2, temp.at(2,0) );
  ASSERT_EQ(1, temp.at(2,1) );
  ASSERT_EQ(2, temp.at(2,2) );
}
TEST(ConnectXTest, placeOutOfBoundsLower)
{
  ConnectX c;
  c.placePiece(-6);  
  bool check = true;
  for(int i=0;i<7;++i)
    for(int j=0;j<6;j++)
      if( c.at(i,j) == 2)
        check=false;
  ASSERT_EQ(check,true);
}
TEST(ConnectXTest, placeOutOfBoundsUpper)
{
  ConnectX c;
  c.placePiece(14); 
  bool check = true;
  for(int i=0;i<7;++i)
    for(int j=0;j<6;j++)
      if( c.at(i,j) == 2)
        check=false;
  ASSERT_EQ(check,true);
}
