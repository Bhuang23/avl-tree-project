/*test.cpp*/

//
// Lab week 07:
// 
// AVL unit tests based on Catch framework.  We are assuming the AVL class is now
// balancing the trees in these tests.
//

#include <iostream>
#include <vector>

#include "avl.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

TEST_CASE("(1) AVL tree with 4 nodes") 
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(100, -100);
  avl.insert(50, -50);
  avl.insert(150, -150);
  avl.insert(125, -125);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 4);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[0] == 50);
  REQUIRE(values[0] == -50);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 100);
  REQUIRE(values[1] == -100);
  REQUIRE(heights[1] == 2);

  REQUIRE(keys[2] == 125);
  REQUIRE(values[2] == -125);
  REQUIRE(heights[2] == 0);

  REQUIRE(keys[3] == 150);
  REQUIRE(values[3] == -150);
  REQUIRE(heights[3] == 1);
}

TEST_CASE("(2) empty tree") 
{
  avltree<int, int>  avl;

  REQUIRE(avl.size() == 0);
  REQUIRE(avl.height() == -1);
}
TEST_CASE("(3) just one node") 
{
  avltree<int, int>  avl;
	
	avl.insert(123, 88);

  REQUIRE(avl.size() == 1);
  REQUIRE(avl.height() == 0);
	
	vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

	REQUIRE(keys[0] == 123);
	REQUIRE(values[0] == 88);
  REQUIRE(heights[0] == 0);
}
TEST_CASE("(3) case 1") 
{
  avltree<int, int>  avl;
	
	avl.insert(123, 1);
	avl.insert(100, 2);
	avl.insert(124, 5);
	avl.insert(95, 3);
	avl.insert(110, 4);
	avl.insert(94, 6);
  REQUIRE(avl.size() == 6);
  REQUIRE(avl.height() == 2);
	vector<int>  keys, values, heights;
  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(keys[0] == 94);
  REQUIRE(values[0] == 6);
  REQUIRE(heights[0] == 0);
	REQUIRE(keys[1] == 95);
  REQUIRE(values[1] == 3);
  REQUIRE(heights[1] == 1);
	REQUIRE(keys[2] == 100);
  REQUIRE(values[2] == 2);
  REQUIRE(heights[2] == 2);
	REQUIRE(keys[3] == 110);
  REQUIRE(values[3] == 4);
  REQUIRE(heights[3] == 0);
	REQUIRE(keys[4] == 123);
  REQUIRE(values[4] == 1);
  REQUIRE(heights[4] == 1);
	REQUIRE(keys[5] == 124);
  REQUIRE(values[5] == 5);
  REQUIRE(heights[5] == 0);
	
}
TEST_CASE("(3) case 2") 
{
  avltree<int, int>  avl;
	
	avl.insert(123, 1);
	avl.insert(125, 2);
	avl.insert(122, 3);
	avl.insert(124, 4);
	avl.insert(126, 5);
	avl.insert(127, 6);


  REQUIRE(avl.size() == 6);
  REQUIRE(avl.height() == 2);
	
	vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

	REQUIRE(keys[0] == 122);
	REQUIRE(values[0] == 3);
  REQUIRE(heights[0] == 0);
	REQUIRE(keys[1] == 123);
	REQUIRE(values[1] == 1);
  REQUIRE(heights[1] == 1);
	REQUIRE(keys[2] == 124);
	REQUIRE(values[2] == 4);
  REQUIRE(heights[2] == 0);
	REQUIRE(keys[3] == 125);
	REQUIRE(values[3] == 2);
  REQUIRE(heights[3] == 2);
	REQUIRE(keys[4] == 126);
	REQUIRE(values[4] == 5);
  REQUIRE(heights[4] == 1);
	REQUIRE(keys[5] == 127);
	REQUIRE(values[5] == 6);
  REQUIRE(heights[5] == 0);
	
}
TEST_CASE("(3) case 3") 
{
  avltree<int, int>  avl;
	
	avl.insert(123, 1);
	avl.insert(100, 2);
	avl.insert(124, 5);
	avl.insert(95, 3);
	avl.insert(110, 4);
	avl.insert(101, 6);

  REQUIRE(avl.size() == 6);
  REQUIRE(avl.height() == 2);
	
	vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

	REQUIRE(keys[0] == 95);
	REQUIRE(values[0] == 3);
  REQUIRE(heights[0] == 0);
	REQUIRE(keys[1] == 100);
	REQUIRE(values[1] == 2);
  REQUIRE(heights[1] == 1);
	REQUIRE(keys[2] == 101);
	REQUIRE(values[2] == 6);
  REQUIRE(heights[2] == 0);
	REQUIRE(keys[3] == 110);
	REQUIRE(values[3] == 4);
  REQUIRE(heights[3] == 2);
	REQUIRE(keys[4] == 123);
	REQUIRE(values[4] == 1);
  REQUIRE(heights[4] == 1);
	REQUIRE(keys[5] == 124);
	REQUIRE(values[5] == 5);
  REQUIRE(heights[5] == 0);
}
TEST_CASE("(3) case 4") 
{
  avltree<int, int>  avl;
	
	avl.insert(123, 1);
	avl.insert(100, 2);
	avl.insert(126, 5);
	avl.insert(127, 3);
	avl.insert(124, 4);
	avl.insert(125, 6);

  REQUIRE(avl.size() == 6);
  REQUIRE(avl.height() == 2);
	
	vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

	REQUIRE(keys[0] == 100);
	REQUIRE(values[0] == 2);
  REQUIRE(heights[0] == 0);
	REQUIRE(keys[1] == 123);
	REQUIRE(values[1] == 1);
  REQUIRE(heights[1] == 1);
	REQUIRE(keys[2] == 124);
	REQUIRE(values[2] == 4);
  REQUIRE(heights[2] == 2);
	REQUIRE(keys[3] == 125);
	REQUIRE(values[3] == 6);
  REQUIRE(heights[3] == 0);
	REQUIRE(keys[4] == 126);
	REQUIRE(values[4] == 5);
  REQUIRE(heights[4] == 1);
	REQUIRE(keys[5] == 127);
	REQUIRE(values[5] == 3);
  REQUIRE(heights[5] == 0);
}
TEST_CASE("(3) case 5") 
{
  avltree<int, int>  avl;
	avl.insert(123, 1);
	avl.insert(100, 2);
	avl.insert(124, 5);
	avl.insert(125, 7);
	avl.insert(95, 3);
	avl.insert(110, 4);
	avl.insert(94, 6);
	avl.insert(93, 8);
  REQUIRE(avl.size() == 8);
  REQUIRE(avl.height() == 3);
	vector<int>  keys, values, heights;
  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(keys[0] == 93);
  REQUIRE(values[0] == 8);
  REQUIRE(heights[0] == 0);
	REQUIRE(keys[1] == 94);
  REQUIRE(values[1] == 6);
  REQUIRE(heights[1] == 1);
	REQUIRE(keys[2] == 95);
  REQUIRE(values[2] == 3);
  REQUIRE(heights[2] == 0);
	REQUIRE(keys[3] == 100);
  REQUIRE(values[3] == 2);
  REQUIRE(heights[3] == 2);
	REQUIRE(keys[4] == 110);
  REQUIRE(values[4] == 4);
  REQUIRE(heights[4] == 0);
	REQUIRE(keys[5] == 123);
  REQUIRE(values[5] == 1);
  REQUIRE(heights[5] == 3);
	REQUIRE(keys[6] == 124);
  REQUIRE(values[6] == 5);
  REQUIRE(heights[6] == 1);
	REQUIRE(keys[7] == 125);
  REQUIRE(values[7] == 7);
  REQUIRE(heights[7] == 0);
}
TEST_CASE("(3) case 6") 
{
  avltree<int, int>  avl;
	avl.insert(123, 1);
	avl.insert(127, 2);
	avl.insert(121, 5);
	avl.insert(125, 7);
	avl.insert(128, 3);
	avl.insert(120, 4);
	avl.insert(129, 6);
	avl.insert(130, 8);
  REQUIRE(avl.size() == 8);
  REQUIRE(avl.height() == 3);
	vector<int>  keys, values, heights;
  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(keys[0] == 120);
  REQUIRE(values[0] == 4);
  REQUIRE(heights[0] == 0);
	REQUIRE(keys[1] == 121);
  REQUIRE(values[1] == 5);
  REQUIRE(heights[1] == 1);
	REQUIRE(keys[2] == 123);
  REQUIRE(values[2] == 1);
  REQUIRE(heights[2] == 3);
	REQUIRE(keys[3] == 125);
  REQUIRE(values[3] == 7);
  REQUIRE(heights[3] == 0);
	REQUIRE(keys[4] == 127);
  REQUIRE(values[4] == 2);
  REQUIRE(heights[4] == 2);
	REQUIRE(keys[5] == 128);
  REQUIRE(values[5] == 3);
  REQUIRE(heights[5] == 0);
	REQUIRE(keys[6] == 129);
  REQUIRE(values[6] == 6);
  REQUIRE(heights[6] == 1);
	REQUIRE(keys[7] == 130);
  REQUIRE(values[7] == 8);
  REQUIRE(heights[7] == 0);
}