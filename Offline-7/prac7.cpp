#include <iostream>
#include <random>
#include <string>
#include <time.h>
using namespace std;

const int nalphas = 26;
const string emptystring = "";
default_random_engine e((unsigned)time(0));
uniform_int_distribution<int> u(0, nalphas - 1);

string randomword(int length);


int main()
{
	for (int counter = 1; counter <= 64; counter++)
		cout << randomword(4) << endl;

	system("pause");
	return 0;
}
