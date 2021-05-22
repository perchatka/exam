#include <stack>
#include <map>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	//	{aaaa{iwerhqiwh(a)sdfsdf}aa}[aa]
	std::stack <char> st;
	std::map <char, char> mp = { {'{' , '}'}, {'(',')'}, {'[',']'}, {'<','>'} };
	std::string str;
	std::getline(std::cin, str);
	bool found = false;
	bool ans = true;
	for (char a : str)
	{
		for (auto i : mp)
		{
			if (i.first == a || i.second == a)
			{
				found = 1;
				break;
			}
		}
		if (found)
		{
			if (mp.find(a) == mp.end())
			{
				if (st.empty())
				{
					ans = 0;
					break;
				}
				ans = (mp[st.top()] == a);

				if (!ans) { break; }
				else
				{
					st.pop();
				}
			}
			else
			{
				st.push(a);
			}
		}
		found = 0;
	}
	ans && st.empty() ? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl;
	return 0;
}