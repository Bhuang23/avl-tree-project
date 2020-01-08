#include <iostream>
#include "avl.h"
using namespace std;
//
// main
//
int main()
{
	avltree<int, int>  avl;
	
	avl.insert(123, 1);
	avl.insert(100, 2);
	avl.insert(124, 5);
	avl.insert(95, 3);
	avl.insert(110, 4);
	avl.insert(94, 6);
	cout << "Distance: " << avl.distance(124,110) << endl;
	avl.clear();
	cout << avl.height() << endl;
  
  return 0;
}