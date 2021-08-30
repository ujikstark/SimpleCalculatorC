#include <iostream>
#include <stack>


using namespace std;

int main() {
	
	char op = '+';
	
	int num;
	
	int res = 0;
	stack<int> s;
	int t = 0;
	
	while (op != '=') {
		cin >> num;
		
		
		if (op == '+') {
			res += num;
			
			if (t > 0)
				s.push(res - num);
			
		} else if (op == '-') {
			res -= num;
			
			if (t > 0)
				s.push(res + num);
			
		} else if (op == '*') {
			
			if (s.empty()) {
				res *= num;
			} else {
				int temp = res - s.top();
				
				temp *= num;
				
				res = s.top() + temp;
			}
			
		} else if (op == '/') {
			
			if (s.empty()) {
				res /= num;
			} else {
				int temp = res - s.top();
				
				temp /= num;
				
				res = s.top() + temp;
			}
			
		} else {
			break;
		}
		
		cin >> op;
		t++;
	}
	
	
	if (res == 0 && t == 1) cout << num;
	else
		cout << res;
	
	return 0;
}
