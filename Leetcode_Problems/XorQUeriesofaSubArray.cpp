// problem link
// https://leetcode.com/problems/xor-queries-of-a-subarray/description/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int tab[32][n], temp[n];

        for(int i = 0;i < n;i++){
            temp[i] = arr[i];
        }

        for(int i = 0; i< 32;i++){
            int count = 0;
            for(int j = 0;j < n;j++){
                if((arr[j] & 1) != 0){
                    count++;
                    tab[i][j] = count;
                }else{
                    tab[i][j] = count;
                }
                arr[j] >>= 1;
            }
        }
        int n1 = queries.size(), val = 0;
        vector<int> res;

        for(int i = 0;i < n1;i++){
            val = 0;
            int start = queries[i][0], end = queries[i][1];
            if(start == 0){
                for(int j = 0;j < 32;j++){
                    if((tab[j][end])%2 == 1){
                        val += (1 << j);
                    }
                }

                res.push_back(val);
            }else if(start == end){
                val = temp[end];
                res.push_back(val);
            }
            else{
                for(int j = 0;j < 32;j++){
                    int count = tab[j][end] - tab[j][start-1];
                    if(count % 2 == 1){
                        val += (1 << j);
                    }
                }

                res.push_back(val);
            }
        }

        return res;

    }
};
