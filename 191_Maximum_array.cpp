#include<bits/stdc++.h>

class Node{
	public:
	Node* link[2];

	void put(int num, Node* temp){
		link[num] = temp;
	}

	bool containsKey(int num){
		return (link[num] != NULL);
	}

	Node* get(int num){
		return link[num];
	}
};

class Trie{
	private:
	Node* root;

	public:
	Trie(){
		root = new Node();
	}

	public:
	void insert(int num){
		Node* node = root;
		for(int i = 31; i >= 0; i--){
			int bit = (num >> i) & 1;
			if(!node -> containsKey(bit)){
				node -> put(bit, new Node());
			}
			
			node = node -> get(bit);
		}
	}

	public:
	int getMax(int num){
		Node* node = root;
		int maxNum = 0;
		for(int i = 31; i >= 0; --i){
			int bit = (num >> i) & 1;
			if(node -> containsKey(!bit)){
				maxNum = maxNum | (1 << i);
				node = node -> get(!bit);
			}
			else	node = node -> get(bit);
		}

		return maxNum;
	}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	vector<pair<int, pair<int, int>>> oQ;
	int q = queries.size();

	for(int i = 0; i < q; i++){
		oQ.push_back({queries[i][1], {queries[i][0], i}});
	}

	sort(oQ.begin(), oQ.end());
	vector<int> res(q, 0);
	sort(arr.begin(), arr.end());

	int index = 0, n = arr.size();
	Trie trie;

	for(auto &it: oQ){
		while(index < n && arr[index] <= it.first){
			trie.insert(arr[index]);
			index++;
		}

		if(index != 0)	res[it.second.second] = (trie.getMax(it.second.first));
		else	res[it.second.second] = -1;
	}

	return res;
}