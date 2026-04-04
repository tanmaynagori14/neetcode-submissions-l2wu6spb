// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         int n = hand.size();
//         if(n % groupSize) return false;
//         sort(hand.begin(), hand.end());
//         unordered_map<int,int> m;
//         for(int it: hand) m[it]++;
//         for(int i=0 ; i<hand.size() ; i++) {
//             int num = hand[i];
//             int freqofnum = 0;
//             if(m.count(num) == 1) freqofnum = m[num];
//             if(freqofnum == 0) continue;

//             for(int j=0 ; j<groupSize ; j++) {
//                 int nextnum = num + j;
//                 if(m.count(nextnum)==0 || m[nextnum]<freqofnum) return false;
//                 m[nextnum] -= freqofnum;
//                 if(m[nextnum] == 0) m.erase(nextnum);
//             }
//         }

//         return true;
//     }
// };



class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> freq;
        for (int card : hand) freq[card]++;

        while (!freq.empty()) {
            int start = freq.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                int curr = start + i;
                if (freq[curr] == 0) return false;

                freq[curr]--;
                if (freq[curr] == 0)
                    freq.erase(curr);
            }
        }

        return true;
    }
};