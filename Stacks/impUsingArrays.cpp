class stack
{
private:
	vector<int> array;

public:
	stack();
	~stack();
	void push(int val){
		array.push_back(val);
	}

	int pop(){
		int temp = array.back();
		array.pop_back();
		return temp;
	}

	int top(){
		return array.back();
	}

	int size(){
		return array.size();
	}

	bool empty(){
		return array.empty();
	}
};
