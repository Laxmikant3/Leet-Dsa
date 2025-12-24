class Solution {
public:


    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total_apple=0,count=0;
        for(int i=0;i<apple.size();i++){
            total_apple += apple[i];

        }
        sort(capacity.begin(),capacity.end(),greater<int>());

        for (int i=0;i<capacity.size();i++) {
            if (total_apple <= 0) {
                break;
            }
            int apples_in_box = min(total_apple, capacity[i]);
            total_apple -= apples_in_box;
            count++;
        }
        return count;
    }
};