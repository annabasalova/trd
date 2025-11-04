// for one

int func(int n){
    int ans = n;
    for(int i=2;i*i<=n;i++){
        if(n % i == 0){
            while(n%i == 0){
                n/=i;
            }
            ans -= ans/i;
        }
    }
    if(n > 1)ans -=ans/(n);
    return ans;
}

//for many
vi p;
vi d;
 
void er(int n){
    d.assign(n+1,0);
    for(int i=2;i<=n;i++){
        if(!d[i]){
            p.pb(i);
            d[i] = i;
            for(int j=i*i;j<=n;j+=i)d[j] = i;
        }
    }
}
 
vi f;
 
int func(int n){
    int nn = n;
    int x = d[n];
    int ans = x-1;
    n/=x;
    while(n%x == 0){
        n/=x;
        ans *=(x);
    }
    ans *= f[n];
    f[nn] = ans;
    return ans;
}

