#include <iostream>
#include <stack>
using namespace std;
int postfix(string s)
{
	
	stack<int> stack;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9') {
			stack.push(s[i] - '0');
		}
		else
		{
			int x = stack.top();
			stack.pop();
			int y = stack.top();
			stack.pop();
			if (s[i] == '+')
				stack.push(y + x);
			else if (s[i] == '-')
				stack.push(y - x);
			else if (s[i] == '*')
				stack.push(y * x);
			else if (s[i] == '/')
				stack.push(y / x);
		}
	}
	return stack.top();
}

int main()
{
	string s;
	cin>>s;
	cout << postfix(s);
}
