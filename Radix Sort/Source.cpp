#include<iostream>
#include<list>
#include<string>
using namespace std;
//utility function to calculate the min length among the strings passed to it
int minLength(const string s[], int size) {
	int min = s[0].length();
	for (int i = 1;i < size; i++) {
		if (s[i].length() < min) min = s[i].length();
	}
	return min;
}
//radix sort to sort the strings in O(n)
void radixSort(string s[], int size) {
	//first we calculate the min length of the shortest string in the array
	int min = minLength(s, size);
	//array of lists for each alphabet
	list<string> lists[27];
	//this outer loop will execute only constant time i.e. the length of shortest string
	for (int i = min - 1;i >= 0;i--) {
		//this inner loop will run n times
		for (int j = 0;j < size;j++) {
			int ind;
			if (s[j][i] == ' ') ind = 26;
			ind = s[j][i] - 97;
			if (ind < 0) ind += 32;
			lists[ind].push_back(s[j]);
		}
		//this inner loop will also execute only constant time i.e. number of alphabets 
		for (int k = 0, n = 0;k < 27;k++) {
			while (!lists[k].empty()) {
				s[n] = lists[k].front();
				n++;
				lists[k].pop_front();
			}
		}
	}
}
int main() {
	const int size = 5;
	string names[size] = { "Hammad", "Abdul Rehman", "Ali", "Aasim", "faq" };
	cout << "Before Sorting :\t";
	for (int i = 0;i < size;i++) {
		cout << names[i] << "\t\t";
	}
	cout << endl;
	radixSort(names, size);
	cout << "After Sorting :\t\t";
	for (int i = 0;i < size;i++) {
		cout << names[i] << "\t\t";
	}
	cout << endl;
	return 0;
}