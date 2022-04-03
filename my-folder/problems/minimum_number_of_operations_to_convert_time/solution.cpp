class Solution {
public:
    int convertTime(string current, string correct) {
         int time = ((current[0]-correct[0])*10+(current[1]-correct[1]))*60+(current[3]-correct[3])*10+current[4]-correct[4];
         int steps = 0;
         set<int> s={1,5,15,60}; 
         time = time*(-1); 
         if(time<0)
         {
            time = time+24*60;
         }
         while(time!=0)
         {
             auto it = s.upper_bound(time); 
             it--;
             time = time-*it;
             steps++;
         }
        return steps;
    }
};