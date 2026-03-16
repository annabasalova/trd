struct sparse{
    vector<vector<int>> dp;
    vector<int> fstbit;
    vector<int> a;
    sparse(vector<int>& v){
        a = v;
        ll n = a.size();
        ll sz = 1;
        ll hgt = 0;
        while(sz < n){
            sz *= 2;
            hgt++;
        }
        dp.assign(hgt,vector<int>(sz,INF));
        fstbit.assign(2*sz,0);
        fstbit[1] = 0;
        for(int i = 2; i < sz;i++)
            fstbit[i] = fstbit[i >> 1] + 1;
        a.resize(sz,INF);
        
        for(int h = 0; h < hgt;h++){
            int len = (1 << h);
            for(int mid = len; mid < sz; mid += 2*len){
                dp[h][mid] = mid;
                for(int i = mid+1;i < mid+len;i++)
                    if(a[dp[h][i-1]] > a[i])
                        dp[h][i] = i;
                    else
                        dp[h][i] = dp[h][i-1];
 
                dp[h][mid-1] = mid-1;
                for(int i = mid-2; i > mid-len-1;i--)
                    if(a[dp[h][i+1]] > a[i])
                        dp[h][i] = i;
                    else
                        dp[h][i] = dp[h][i+1];
            }
        }
    }
    ll get_min(ll l, ll r){
        // if(l == r) return dp[0][l];
        ll h = 63 - __builtin_clzll((l^r));
        if(a[dp[h][l]] > a[dp[h][r]])
            return dp[h][r];
        return dp[h][l];
    }
};
