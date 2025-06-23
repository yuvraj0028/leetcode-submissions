class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int ans = 0;
        // counting freq of rabbits with same numbers
        for(const int & i: answers)
            mp[i]++;

        for(const auto & i: mp){
            int groupSize = i.first + 1;
            int freq = i.second;

            int num = (freq + groupSize - 1) / groupSize;

            ans += num * groupSize; 
        }
        return ans;
    }
};


/**  0,1,2
    [1,1,2]

    {
        1 -> 2,
        2 -> 1
    }

    ans = 0

    first k,v map -> 
        groupSize = 1 + 1 = 2
        freq = 2

        num = 2 + 1 / 2 = 3 / 2 = 1

        ans =  0 + 2 * 1
        ans = 2

    second k,v map -> 
        groupSize = 2 + 1 = 3
        freq = 1

        num = 3 / 3 = 1

        ans =  2 + 1 * 3
        ans = 5






























    0 : ans[0] + 1

    2 + 2 = 4


    {
        1->2,
        2->1,
    }

    2
    2
    
    R,g,b

    [
        0 -> 2,
        1 -> 2,
        3 -> 3,
    ]

    [
        0 -> 2,
        3 -> 3,
    ]
     op = 5;

    [1,1,2,2,2,2]

    {
        0 : 2,
        1 : 2,
        2 : 3,
        3 : 3,
        4 : 3,
        5 : 3,
    }

    {
        0 : 2,
        2 : 4,
    }

    (0 + 1) x 2 = 6 

    [10,10,10]
    op -> 11;

    {
        10 : 3
    }

    total rabbit group = 10 + 1 = 11
    freq = 3

    total groups = (freq + total rabbit group) - 1 // excluding the one who told there are anothe rabbit

    total groups = 13

    total groups / 11

    1






    op -> 8; 

    1 -> 1+1 [same color]
    2 -> 1+1 [same ]
*/
