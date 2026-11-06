#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <functional>   

// Write a program to implement 
// Huffinan Encoding using a greedy strategy.


using namespace std;


void encode(string str) {

	map<char, vector<int>> codeTable;
	map<char, int> freqTable;
	
	priority_queue<pair<int, vector<char>>, vector<pair<int, vector<char>>>, greater<pair<int, vector<char>>>> pq;

	for (char c : str) {
		freqTable[c] += 1;
	}

	cout << "Char | Freq" << endl;
	for (auto i : freqTable) {
		cout << i.first << "   -> " << i.second << endl;
	}
	cout << "\n\n" << endl;

	for (auto i : freqTable) {
		vector<char> v;
		v.push_back(i.first);
		pq.push({i.second, v});
	}

	while (pq.size() > 1) {
		auto a = pq.top();
		pq.pop();
		auto b = pq.top();
		pq.pop();

		for (char c : a.second) {
			codeTable[c].push_back(1);
		}
		for (char c : b.second) {
			codeTable[c].push_back(0);
			a.second.push_back(c);
		}
		a.first += b.first;

		pq.push(a);
	}

	cout << "Char | Code" << endl;
	for (auto k : codeTable) {
		cout << k.first << " -> ";
		for (auto i : k.second) {
			cout << i;
		}
		cout << endl;
	}
	cout << "\n\n" << endl;

	

	return;
}


int main() {
	cout << "HW!" << endl;

	string str = "ABRACADABRA";
	encode(str);

	return 1;
}
