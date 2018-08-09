#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        //获取行号
        int col = matrix[0].size();
        //获取列号
        vector<int> result;
        //重建一个vector用来保存改完顺序后的元素
        if(row == 0 || col == 0)
        {
            //空二维数组，返回一个空数组
            return result;

        }

        int left = 0;
        int right = col - 1;
        int up = 0;
        int down = row - 1;
        while(left <= right && up <= down)
        {
            int i = 0;
            for(i = left ;i <= right;i++)
            {
                result.push_back(matrix[up][i]);

            }
            if(up < down)
            {
                for(i = up + 1;i <= down;i++)
                {
                    result.push_back(matrix[i][right]);

                }
            }
            if(up < down && left < right)
            {
                for(i = right - 1;i >= left;i--)
                {
                    result.push_back(matrix[down][i]);

                }               

            }
            if(up < down && left < right)
            {
                for(i = down -1;i > left;i--)
                {
                    result.push_back(matrix[i][left]);

                }

            }
            left++;
            right--;
            up++;
            down--;
        }
        return result;


    }

};
