#include <iostream>

using namespace std;

int main(int argc, char* arg[]) {
	int n = 0;
  (argc < 2) return 1;
  int arr[atoi(arg[1])];
  float  sum = 0.00;
  n = atoi(arg[1]);//number of arguments in the array
  for (int i = 0; i < n; i++) {
          arr[i] = atoi(arg[i+2]);
  }
	int size = sizeof(arr)/sizeof(int);
	float avg = 0.00;
	for (int j = 0; j < size; j++) {
		sum += arr[j];
	}
	avg = sum/n;

        cout << "Sum is " <<  sum << "\n" << "Avg is " << avg << endl;
        return 0;
}

