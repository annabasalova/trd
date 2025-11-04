vector<pair<double,double>>vyp(vector<pair<double,double>>&a){
    int ind = 0;
    int n = (int)a.size();
    for(int i=0;i<n;i++){
        if(a[i].fi < a[ind].fi){
            ind = i;
            continue;
        }
        if(a[i].fi == a[ind].fi && a[i].se < a[ind].se){
            ind = i;
            continue;
        }
    }
    p0 = a[ind];
    swap(a[0], a[ind]);
    sort(a.begin() + 1, a.end(), comp);
    vector<pair<double,double>>res;
    res.pb(a[0]);
    for(int i=1;i<n;i++){
        pair<double,double>r1,r2;
        while((int)res.size() > 2){
            r1 = {a[i].fi - res.back().fi, a[i].se - res.back().second};
            r2 = {res.back().fi - res[(int)res.size()-2].fi, res.back().se - res[(int)res.size()-2].se};
            if(r1.fi*r2.se - r1.se*r2.fi >= 0){
                res.pop_back();
            }
            else break;
        }
        res.pb(a[i]);
    }
    return res;
}
