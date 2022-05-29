class Solution {
public: 
    string discountPrices(string sentence, int discount) {
        string ans; 
        for(int i=0;i<sentence.size();i++)
        {
            if((i==0 or sentence[i-1]==' ') and sentence[i]=='$')
            {
                ans.push_back(sentence[i]);
                i++;
                string num;
                while(sentence[i]>='0' and sentence[i]<='9')
                {   
                    num.push_back(sentence[i]);
                    i++;
                }
                i--;
                if(!num.empty() and (i+1==sentence.length() or sentence[i+1]==' ')){
                double y;
                y = stod(num); 
                double anss = ((100.0-discount)*y)/100.0; 
                cout<<fixed<<setprecision(2); 
                std::ostringstream out;
                out.precision(2);
                out << std::fixed << anss; 
                ans.append(out.str());}
                if(i+1!=sentence.length() and sentence[i+1]!=' '){
                ans.append(num);}
            }
            else
            {
                ans.push_back(sentence[i]);
            }
        }
        return ans;
    }
};