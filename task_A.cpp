#include <iostream>
#include <cmath>

int main()
{
    int a, b;
    std::cin>>a>>b;
    int mx = a, cnt = 0;
    int cur = a;
    while(cur <= b)
    {
        if(std::abs(cur) % 16 == 11 && std::abs(cur) % 6 != 0)
        {
            int del = abs(cur);
            while(del >= 16)
            {
                del /= 16;
            }
            if(del == 12)
            {
                ++cnt;
                if(cur > mx)
                    mx = cur;
                cur += 16;
            }
            else
                ++cur;
        }
        else
            ++cur;
    }
    if(cnt == 0)
        std::cout<<"0 0 ";
    else
    std::cout<<cnt<<' '<<mx<<' ';

    return 0;
}
