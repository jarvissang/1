#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <functional>   
#include <string>

using namespace std;

// Huffman Encoding

void encode(string str) {

	map<char, vector<int>> codeTable;
	map<char, int> freqTable;
	
	// Min-heap based on frequency
	priority_queue<pair<int, vector<char>>, vector<pair<int, vector<char>>>, greater<pair<int, vector<char>>>> pq;

	// Count frequencies
	for (char c : str) {
		freqTable[c] += 1;
	}

	cout << "Char | Freq" << endl;
	for (auto i : freqTable) {
		cout << i.first << "   -> " << i.second << endl;
	}
	cout << "\n\n" << endl;

	// Push all unique characters into the priority queue
	for (auto i : freqTable) {
		vector<char> v;
		v.push_back(i.first);
		pq.push({i.second, v});
	}

	// Build the Huffman Tree
	while (pq.size() > 1) {
		auto a = pq.top(); // Smallest
		pq.pop();
		auto b = pq.top(); // Second smallest
		pq.pop();

		for (char c : a.second) {
			codeTable[c].insert(codeTable[c].begin(), 1); // Insert at front
		}
		for (char c : b.second) {
			codeTable[c].insert(codeTable[c].begin(), 0); // Insert at front
			a.second.push_back(c); // Merge characters
		}
		a.first += b.first; // Merge frequencies

		pq.push(a);
	}

	// Print the generated codes
	cout << "Char | Code" << endl;
	for (auto k : codeTable) {
		cout << k.first << " -> ";
		for (auto i : k.second) {
			cout << i;
		}
		cout << endl;
	}
	cout << "\n\n" << endl;
}

int main() {
	cout << "HW!" << endl;

	string str = "ABRACADABRA";
	encode(str);

	return 0;
}
