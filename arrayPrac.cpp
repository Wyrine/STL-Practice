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
#include <cstdlib> //srand
#include <array> //array
#include <cstring> //memcpy
#include <ctime> //time
#include <algorithm> //fill

using namespace std;
#define MAXSIZE 30

void
iterateAndPrint(array<int, MAXSIZE> & myarray)
{
	int i;

	//bare iteration to extract
	//Slightly faster than iterators but mostly negligable
	cout << "Bare iteration:\n";
	for(i = 0; i < MAXSIZE; i++)
		cout << i << ": " << myarray[i] << endl;

	//using an iterator
	cout << "Iterator:\n";
	//slightly slower than using indices but it's worth it
	for(array<int, MAXSIZE>::iterator it = myarray.begin(); it != myarray.end(); ++it)
		cout << *it << endl;

	//less lines through dynamic type but still using an iterator
	cout << "Iterator with auto type:\n";
	for(auto it = myarray.begin(); it != myarray.end(); ++it)
		cout << *it << endl;
}

void
initArray(array<int, MAXSIZE> & myarray)
{
	int i;
	int tmp[MAXSIZE];

	//bare iteration to insert
	for(i = 0; i < MAXSIZE; i++)
		myarray[i] = rand() % MAXSIZE;
	//can also use fill if we want all elements as some nonzero constant
	myarray.fill(rand() % MAXSIZE);
	
	fill(tmp, tmp+MAXSIZE, MAXSIZE); //the c++ memset and apparently it's super fast
	//can copy as such using the data pointer
	memcpy(myarray.data(), tmp, sizeof(int)*MAXSIZE);
}

int
main(int argc, char** argv)
{
	srand(time(NULL));
	//static initialization
	array<int, MAXSIZE> myarray = {1, 2};

	//show that the elements not initialized are set to 0
	iterateAndPrint(myarray);
	initArray(myarray);
	iterateAndPrint(myarray);

	

}
