class Solution {
public:
    bool areSentencesSimilar(string s, string d) {
        if(s.size()<d.size())
        {
            swap(s,d);
        }
        vector<string>a;
        vector<string>b;
        string temp="";
        for(auto i : s)
        {
           if(i==' ')a.push_back(temp),temp="";
           else temp+=i;
        }
        a.push_back(temp);

        temp="";
        for(auto i : d)
        {
           if(i==' ')b.push_back(temp),temp="";
           else temp+=i;  
        }
        b.push_back(temp);
        int beg=0,end=a.size()-1;
        int bega=0,enda=b.size()-1;
        
        while(beg<=enda)
        {
            if(a[beg]==b[beg])
            {
                cout<<a[beg]<<" "<<b[beg]<<endl;
                beg++;
            }
            else if(a[end]==b[enda])
            {
                
                enda--,end--;
            }
            else 
            {
                
                return 0;
            }
        }
        return 1;
    }
};