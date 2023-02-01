#include <iostream>
using namespace std;
using std::cout;
using std::cin;

int main () {
    int i=5;
	{
		float i=56.6;
		{
			int i=355;
			for (int i=0;i<5;i++) {
				cout << i << endl;
				{ 
					int i=45455;
					cout << i << endl;
				}
			
			}

			cout << i << endl;
		}
		cout << i << endl;
	}
	cout << i << endl;
}

