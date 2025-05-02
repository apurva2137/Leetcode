class Solution {
public:
    #define ll long long
    bool possible(ll minS, int m, vector<int>& p)
    {
        int n=p.size();
        vector<ll>count(n,0);
        for(int i=0;i<n;i++)
        {
            count[i]=(minS/p[i])+(minS%p[i]!=0);
        }
        count[0]--;
        m--;
        int i=0,j=0;
        while(i<n)
        {
            if(count[i]<=0)
            {
                i++;
            }   
            else
            {
                if(j!=i)
                {
                    m-=(i-j);
                    if(m<0)
                       return false;
                    count[i]--;   
                }
                ll curr=count[i]*2;
                if(m<curr)
                    return false;
                m-=curr;
                if(i<n-1)
                    count[i+1]-=count[i];
                count[i]=0;
                j=i;
                i++;    
            }
        }
        return i>=n;
    }
    long long maxScore(vector<int>& p, int m) 
    {
        ll mx=*max_element(p.begin(), p.end());
        ll l=0,h=mx*m,res=0;
        while(l<=h)
        {
            ll k=(l+h)/2;
            if(possible(k,m,p))
            {
                res=k;
                l=k+1;
            }
            else
                h=k-1;
        }
        return res;
    }
};