#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() == 0 || numbers.size() > 5)
        {
            return false;
        }
        //先排序
        //然后统计处数组中0出现的次数
        //然后统计出处0外的总间隔数
        //如果总间隔数小于0出现的次数，则满足条件
        //如果数组中有两个元素相等，直接返回错误
        sort(numbers.begin(),numbers.end());

        int count = 0;
        for(size_t i = 0;i < numbers.size();++i)
        {
            if(numbers[i] == 0)
            {
                count++;
            }
        }
        int sub = 0;
        int max_sub = 0;
        int cur = count;
        int next = 0;
       while(next < numbers.size()-1)
       {  
            next = cur + 1;
            if(numbers[cur] == numbers[next])
            {
                 return false;
            }
            sub = numbers[next] - numbers[cur] - 1;
            max_sub += sub;
            cur = next;
        }
        if(count >= max_sub)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    return 0;
}
