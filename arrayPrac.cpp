/*People don't seem to like c++ arrays because of static initializing
 *ex: int i[] = {1, 2}; -> int i[] = {1,2,3};
 *
 *vs: array<int, 2> i = {1, 2}; -> array<int, 3> i = {1,2,3};
 *
 * There's more things to keep track of for little benefit. 
 * Plus, vectors are cool
 * 
 * Also, vectors are on the heap where array is on the stack
 *
 * Vectors are also better because they are guaranteed to be contiguous in memory
 *
 * Why they are good compared to c-style:
 * 1) avoid raw pointers
 * 2) when data size is small so it's okay to be put on the stack
 * 3) fixed size
 *
 *
 * So, c-style arrays are bad I guess because accessing raw stuff is bad
 */
#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>

using namespace std;
#define MAXSIZE 30

int
main(int argc, char** argv)
{
	array<int, MAXSIZE> myarray = {1, 2};
	int i;

	srand(time(NULL));

	//bare iteration to insert
	for(i = 0; i < MAXSIZE; i++)
		myarray[i] = rand();

	//bare iteration to extract
	for(i = 0; i < MAXSIZE; i++)
		cout << i << ": " << myarray[i] << endl;

	//using an iterator
	for(array<int, MAXSIZE>::iterator it = myarray.begin(); it != myarray.end(); ++it)
		cout << *it << endl;

	//less lines but still using an iterator
	for(auto it = myarray.begin(); it != myarray.end(); ++it)
		cout << *it << endl;
}
