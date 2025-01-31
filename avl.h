#pragma once

#include <iostream>
#include <algorithm>  // std::max
#include <cstdlib>    // std::abs
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

template<typename TKey, typename TValue>
class avltree
{
private:
  struct NODE
  {
    TKey   Key;
    TValue Value;
    int    Height;
    NODE*  Left;
    NODE*  Right;
  };

  NODE* Root;  // pointer to root node of tree (nullptr if empty)
  int   Size;  // # of nodes in the tree (0 if empty)

  // 
  // _inorder does the actual inorder traversal and output 
  // to console.  Each key is output to the console followed
  // by " ", including the last key.
  //
  void _clear(NODE* cur)
  {
     if(cur == nullptr)
	 {
		 return;
	 }
	 _clear(cur->Left);
     _clear(cur->Right);
	 delete(cur);
     Size--;
	 
	 Root = nullptr;
  }
  void _inorder(NODE* cur)
  {
    if (cur == nullptr)
      return;
    else
    {
      _inorder(cur->Left);
      cout << "(" << cur->Key << "," << cur->Value << "," << cur->Height << ")" << " ";
      _inorder(cur->Right);
    }
  }
  void _inorder_keys(NODE* cur, std::vector<TKey>& V)
  {
    if (cur == nullptr)
      return;
    else
    {
      _inorder_keys(cur->Left, V);
      V.push_back(cur->Key);
      _inorder_keys(cur->Right, V);
    }
  }

  void _inorder_values(NODE* cur, std::vector<TValue>& V)
  {
    if (cur == nullptr)
      return;
    else
    {
      _inorder_values(cur->Left, V);
      V.push_back(cur->Value);
      _inorder_values(cur->Right, V);
    }
  }

  void _inorder_heights(NODE* cur, std::vector<int>& V)
  {
    if (cur == nullptr)
      return;
    else
    {
      _inorder_heights(cur->Left, V);
      V.push_back(cur->Height);
      _inorder_heights(cur->Right, V);
    }
  }

  //
  // _copytree:
  //
  // Given a tree, inserts the (key, value) pairs into *this* tree.
  //
  void _copytree(NODE* cur)
  {
    if (cur == nullptr)
      return;
    else
    {
      //
      // to copy and build an exact copy, we need to "visit" cur
      // first and insert that (key, value) pair first.  That way
      // all the nodes to the left will properly go to the left,
      // all the node to the right will properly go to the right.
      //
      insert(cur->Key, cur->Value);

      _copytree(cur->Left);
      _copytree(cur->Right);
    }
  }

  //
  // _RightRotate
  // _LeftRotate
  //
  // Rotates the tree around the node N, where Parent is N's parent.  Note that
  // Parent could be null, which means N is the root of the entire tree.  If 
  // Parent denotes a node, note that N could be to the left of Parent, or to
  // the right.  You'll need to take all this into account when linking in the
  // new root after the rotation.  Don't forget to update the heights as well.
  //
  void _RightRotate(NODE* Parent, NODE* N)
  {
    assert(N != nullptr);  // pre-conditions: N and L must exist
    assert(N->Left != nullptr);
   NODE *L = N->Left;
   NODE *B = L->Right;
   N->Left = B; // move b into n left
   L->Right = N; // move n to right of l
   //link L to parent
   if(Parent == nullptr)
   {
      Root = L;
   }
   else if(L->Key < Parent->Key)
   { 
      Parent->Left = L; //make parent's left L
   }
   else
   {
      Parent->Right = L;//make parent's right L
   }
    //
    // TODO
    //
    //recalculate height of N
    if(N->Left == nullptr && N->Right == nullptr)
    {
       N->Height = 0;
    }
    else if(N->Left == nullptr)
    {
       N->Height = 1+N->Right->Height;
    }
    else if(N->Right == nullptr)
    {
       N->Height = 1+N->Left->Height;
    }
    else
    {
       N->Height = 1+ max ( N->Left->Height, N->Right->Height);
    }
    //recalculate height of L 
    if(L->Left == nullptr)
    {
       L->Height = 1+L->Right->Height;
       }
   else
    {
       L->Height = 1+ max ( L->Left->Height, L->Right->Height);
    }
    
  }

  void _LeftRotate(NODE* Parent, NODE* N)
  {
    assert(N != nullptr);  // pre-conditions: N and R must exist
	assert(N->Right != nullptr);
    NODE *L = N->Right;
    NODE *B = L->Left;
   N->Right = B; // move b into n right
   L->Left = N; // move n to Left of l
   //link L to parent
   if(Parent == nullptr)
   {
      Root = L;
   }
   else if(L->Key < Parent->Key)
   { 
      Parent->Left = L; //make parent's left L
   }
   else
   {
      Parent->Right = L;//make parent's right L
   }
    //
    // TODO
    //
    //recalculate height of N
    if(N->Left == nullptr && N->Right == nullptr)
    {
       N->Height = 0;
    }
    else if(N->Left == nullptr)
    {
       N->Height = 1+N->Right->Height;
    }
    else if(N->Right == nullptr)
    {
       N->Height = 1+N->Left->Height;
    }
    else
    {
       N->Height = 1+ max ( N->Left->Height, N->Right->Height);
    }
    //recalculate height of L 
    if(L->Right == nullptr)
    {
       L->Height = 1+L->Left->Height;
       }
   else
    {
       L->Height = 1+ max ( L->Left->Height, L->Right->Height);
    }
  }


public:
  //
  // default constructor:
  //
  // Creates an empty tree.
  //
  avltree()
  {
    Root = nullptr;
    Size = 0;
  }

  //
  // copy constructor:
  //
  avltree(avltree& other)
  {
    Root = nullptr;
    Size = 0;

    _copytree(other.Root);
  }
  //destructor
  ~avltree()
  {
	  _clear(Root);
  }
  // 
  // size:
  //
  // Returns the # of nodes in the tree, 0 if empty.
  //
  int size()
  {
    return Size;
  }

  //
  // height
  //
  // Returns the height of tree; the height of an empty tree is
  // defined as -1.
  //
  int height()
  {
    if (Root == nullptr)
      return -1;
    else
      return Root->Height;
  }
  //clear function
  void clear()
  {
	   _clear(Root);
  }
  // 
  // search:
  //
  // Searches the tree for the given key, returning a pointer to the 
  // value if found and nullptr if not.  We return a pointer so the caller
  // may update the underlying value if needed.
  //
  TValue* search(TKey key)
  {
    NODE* cur = Root;
    while (cur != nullptr)
    {
      if (key == cur->Key)  // already in tree
      {
        return &cur->Value;
      }

      if (key < cur->Key)  // search left:
      {
        cur = cur->Left;
      }
      else
      {
        cur = cur->Right;
      }
    }//while  

    // if get here, not found
    return nullptr;
  }
  //finds distance from root
int distanceFromRoot(NODE* n, int num) 
{ 
    if (n->Key == num) 
        return 0; 
    else if (n->Key > num) 
        return 1 + distanceFromRoot(n->Left, num); 
    return 1 + distanceFromRoot(n->Right, num); 
} 
  
// Returns minimum distance between k1 and k2. 
// This function assumes that k1 and k2 exist 
// in Avl tree. 
int distanceBetween2(NODE* root, int k1, int k2) 
{ 
    if (!root) 
        return 0; 
  
    // Both keys lie in left 
    if (root->Key > k1 && root->Key > k2) 
        return distanceBetween2(root->Left, k1, k2); 
  
    // Both keys lie in right 
    else if (root->Key < k1 && root->Key < k2) // same path 
        return distanceBetween2(root->Right, k1, k2); 
  
    // Lie in opposite directions (Root is 
    // LCA of two nodes) 
    else if (root->Key >= k1 && root->Key <= k2) 
        return distanceFromRoot(root, k1) +  
               distanceFromRoot(root, k2); 
	else{
		return 0;
	}
} 
  //finds distance between k1 and k2
  int distance(int k1, int k2)
  {
	if(k1 == k2 && search(k1) != nullptr)//same key
	{
		return 0;
	}
	else if(search(k1) == nullptr || search(k2) == nullptr)//not in tree
	{
		return -1;
	}
	else
	{
		if(k1 < k2)//k1 is smaller than k2
		{
			return distanceBetween2(Root, k1, k2);
		}
		else //k2 is smaller than k1
		{
			return distanceBetween2(Root, k2, k1);
		}
	}
}
//rotate with 4 cases RR, LRR, RLL, LR checking the right and left subtrees of N
  void _RotatetoFix(NODE* Parent, NODE* N)
  {
	  assert(N != nullptr);
	  int HL, HR;
	  if(N->Left == nullptr)
		  HL = -1;
	  else{
		  HL = N->Left->Height;}
	  if(N->Right == nullptr)
	  {
		  HR = -1;
		  }
	  else{
	      HR = N->Right->Height;
		  }
	  assert(std::abs(HL-HR) > 1);
	  if (HL>HR)  //case 1 and 2
	  {
// 			assert(N->Left->Left != nullptr);
// 			assert(N->Left->Right != nullptr);
 			int Ll, LR;
		if(N->Left->Left == nullptr && N->Left->Right != nullptr){
			Ll = -1;
			LR = N->Left->Right->Height;}
		else if(N->Left->Right == nullptr && N->Left->Left != nullptr){
			LR = -1;
			Ll = N->Left->Left->Height;}
		else
		{
			Ll = N->Left->Left->Height;
			LR = N->Left->Right->Height;
		}
			if(Ll > LR)
			{
				_RightRotate(Parent, N);  
			}
			else//case 2
			{
				_LeftRotate(N, N->Left);  
				_RightRotate(Parent, N); 
			} 
	}
    // Right Right Case  
    else
	{
		int Rl, RR;
		if(N->Right->Left == nullptr && N->Right->Right != nullptr){
			Rl = -1;
			RR = N->Right->Right->Height;}
		else if(N->Right->Right == nullptr && N->Right->Left != nullptr){
			RR = -1;
			Rl = N->Right->Left->Height;}
		else
		{
			Rl = N->Right->Left->Height;
			RR = N->Right->Right->Height;
		}
			
// 		assert(N->Right->Left == nullptr);
// 		assert(N->Right->Right = nullptr);
		if(Rl > RR)//case 3
		{
		    _RightRotate(N, N->Right); 
			_LeftRotate(Parent, N); 
		}
		else//case 4
		{ 
			_LeftRotate(Parent, N);
		}
        
	}
 
  }
  //
  // insert
  //
  // Inserts the given (key, value) pair into the tree; if the key has 
  // already been inserted then the function returns without changing 
  // the tree.
  //
  void insert(TKey key, TValue value)
  {
    NODE* prev = nullptr;
    NODE* cur = Root;
    //
    // stack the nodes we visit so we can walk back up
    // the search path later, adjusting heights:
    //
    stack<NODE*> nodes;
    //
    // 1. Search to see if tree already contains key:
    //
    while (cur != nullptr)
    {
      if (key == cur->Key)  // already in tree
        return;

      nodes.push(cur);  // stack so we can return later:

      if (key < cur->Key)  // search left:
      {
        prev = cur;
        cur = cur->Left;
      }
      else
      {
        prev = cur;
        cur = cur->Right;
      }
    }//while

    //
    // 2. if we get here, key is not in tree, so allocate
    // a new node to insert:
    // 
    NODE* newNode;
    newNode = new NODE();
    newNode->Key = key;
    newNode->Value = value;
    newNode->Height = 0;  // leaf node -> sub-tree of height 0:
    newNode->Left = nullptr;
    newNode->Right = nullptr;

    //
    // 3. link in the new node:
    //
    // NOTE: cur is null, and prev denotes node where
    // we fell out of the tree.  if prev is null, then
    // the tree is empty and the Root pointer needs 
    // to be updated.
    //
    if (prev == nullptr)
      Root = newNode;
    else if (key < prev->Key)
      prev->Left = newNode;
    else
      prev->Right = newNode;

    // 
    // 4. update size:
    //
    Size++;
    //
    // 5. walk back up tree using stack and update heights.
    //
    while (!nodes.empty())
    {
      cur = nodes.top();
      nodes.pop();

      int hL = (cur->Left == nullptr) ? -1 : cur->Left->Height;
      int hR = (cur->Right == nullptr) ? -1 : cur->Right->Height;
      int hCur = 1 + std::max(hL, hR);

      if (cur->Height == hCur)  // didn't change, so no need to go further:
        break;
	  else if(std::abs(hL-hR) <= 1)
	  {
		  cur->Height = hCur;
	  }
      else{ // height changed, update and keep going:
	  
		  if(!nodes.empty()){
			  NODE* parent = nodes.top();
			  _RotatetoFix(parent, cur);}
		  else{
			  NODE* parent = nullptr;
			  _RotatetoFix(parent, cur);
		  }
	  
	  }
	 
        
    }//while

    //
    // done!
    //
  }
  // inorder:
  //
  // Performs an inorder traversal of the tree, outputting
  // the keys to the console.
  //
  void inorder()
  {
    cout << "Inorder: ";

    _inorder(Root);

    cout << endl;
  }

  std::vector<TKey> inorder_keys()
  {
    std::vector<TKey>  V;

    _inorder_keys(Root, V);

    return V;
  }

  std::vector<TValue> inorder_values()
  {
    std::vector<TValue>  V;

    _inorder_values(Root, V);

    return V;
  }

  std::vector<int> inorder_heights()
  {
    std::vector<int>  V;

    _inorder_heights(Root, V);

    return V;
  }

};
