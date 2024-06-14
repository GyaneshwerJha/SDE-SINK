class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        priority_queue<int> pq1(seats.begin(), seats.end());
        priority_queue<int> pq2(students.begin(), students.end());
        
        int minMoves = 0;

        for(int i = 0; i < n; i++){
            minMoves += abs(pq1.top() - pq2.top());
            pq1.pop();
            pq2.pop();
        }

        return minMoves;
    }
};