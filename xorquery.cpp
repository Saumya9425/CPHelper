#include <bits/stdc++.h>  
using namespace std;
typedef long long ll;
#define repn(i,e) for(ll i = 0; i < e; i++)
#define rep(i,e) for(ll i = 0; i <= e; i++)
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
const ll N = 2e5 + 1;
ll a[N],seg[4*N];
 
void build(ll ind,ll low,ll high)
{
    if(low==high)
    {
        seg[ind] = a[low];
        return;
    }
    ll mid = (low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
}
 
ll query(ll ind,ll low,ll high,ll l,ll r){
    if(low>=l && high<=r)
    {
        return seg[ind];
    }
    if(high<l || low>r)
    return 0;
    ll mid = (low+high)/2;
    ll left = query(2*ind+1,low,mid,l,r);
    ll right = query(2*ind+2,mid+1,high,l,r);
    return left ^ right;
}

void update(ll ind,ll low,ll high,ll i,ll val)
{
    if(low==high)
    {
        seg[ind] =val;
        return;
    }
    ll mid = (low+high)/2;
    if(i<=mid)
    update(2*ind+1,low,mid,i,val);
    else
    update(2*ind+2,mid+1,high,i,val);
    seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
}
 
void solve(){
    ll n,q;
    cin>>n>>q;
    repn(i,n)
    cin>>a[i];
    build(0,0,n-1);
    while(q--)
    {
        ll type,l,r;
        cin>>type>>l>>r;
        if(type==1)
        {
            --l;
            update(0,0,n-1,l,r);
        }
        else{
            --l;
            --r;
            cout<<query(0,0,n-1,l,r)<<endl;
        }
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}
// I know how to print hello world.Do you?