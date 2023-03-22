    string minWindow(string s, string t) {
        vector<int> freqT(256,0);
        vector<int> freqSubstr(256);
        
        for(int i=0;i<(int)t.size();i++)
        {
            freqT[t[i]]++;
        }
        int start_idx=-1,end_idx=1e5;
        int i=0;
        for(int j=0;j<(int)s.size();j++)
        {
            freqSubstr[s[j]]++;
            while(is_safe(freqT,freqSubstr))
            {
                if(j-i+1 < end_idx-start_idx+1)
                {
                    start_idx=i;
                    end_idx=j;
                }
                freqSubstr[s[i]]--;
                i++;
            }
        }
        if(start_idx!=-1) return s.substr(start_idx,end_idx-start_idx+1);
        else return "";
    }
};