#include <iostream>
#include "split.h"
using namespace std;

void function_two (Node* in1, Node* in2);

Node* function_one (Node* in)
{
  if (in == NULL) return NULL;
  Node* out = NULL;
   if (in->next != NULL)
   {
       out = function_one (in->next);
       function_two (in, out);
       in->next = NULL;
       return out;
   }
   return in;

}
void function_two (Node* in1, Node* in2)
{
   if (in2->next != NULL) 
   {
       function_two (in1, in2->next);
       return;
   }
   in2->next = in1;
}

int main(int argc, char* argv[])
{
	
	Node* five = new Node(5, NULL);
	Node* four = new Node(4, five);
	Node* three = new Node(3,four);
	Node* two = new Node(2, three);
	Node* in = new Node(1, two);

	cout << "here" << endl;
	function_one(in);

	cout << five->next->value << endl;
	cout << four->next->value << endl;
	cout << three->next->value << endl;
	cout << two->next->value << endl;

  return 0;
}