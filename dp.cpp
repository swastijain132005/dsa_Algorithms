//lis (binary search)

for(auto &p :b){
            int x=p.second;
            auto it=lower_bound(s.begin(),s.end(),x);
            if(it==s.end()){
                s.push_back(x);
            }
            else {
                *it=x;
            }
        }
        return s.size();
