#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//set<int>tree[160005];
 int lazy[40000005];
vector<pair<int,int> >vi;
void update(int att,int L,int R,int l,int r,int poster)
{
    if(lazy[att]!=0)
    {
       // tree[att].insert(lazy[att]);

        if(L!=R)
        {
            lazy[2*att+1]= lazy[att];
            lazy[2*att+2]= lazy[att];
           // cout<<"up "<<poster<<" "<<L<<" "<<R<<" "<<att<<" "<<endl;
            lazy[att]=0;
        }

    }

    if(r<L || l>R) return ;

    if(L>=l && R<=r){
        //tree[att].insert(poster);
        lazy[att]= poster;
        //cout<<"LOw "<<poster<<" "<<L<<" "<<R<<" "<<att<<" "<<endl;
        if(L!=R)
        {
            lazy[2*att+1]=poster;
            lazy[2*att+2]=poster;
        }
        return ;
    }


    int mid = (L+R)/2;
    update(2*att+1,L,mid,l,r,poster);
    update(2*att+2,mid+1,R,l,r,poster);

    //set_union(tree[2*att+1].begin(),tree[2*att+1].end(),tree[2*att+2].begin(),tree[2*att+2].end(),inserter(tree[att],tree[att].begin()));
}
set<int>res;
set<int> :: iterator it;

void query(int att,int L,int R)
{
    if(lazy[att]!=0)
    {
        res.insert(lazy[att]);
        //cout<<L+1<<" "<<R+1<<" "<<att<<lazy[att]<<endl;
        lazy[att]=0;
        return ;

    }
    if(L==R){
        if(lazy[att]!=0){
            res.insert(lazy[att]);
           // cout<<L+1<<" "<<R+1<<" "<<att<<lazy[att]<<endl;
            lazy[att]=0;
        }
        return ;
    }

    int mid = (L+R)/2;
    query(2*att+1,L,mid);
    query(2*att+2,mid+1,R);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(),cout.tie();

    int t,i,n,l,r;
    cin>>t;
    int maxn=-1;

    while(t--)
    {
        cin>>n;
        res.clear();
        vi.clear();

        maxn=-1;
        for(i=0;i<n;i++)
        {
           cin>>l>>r;
           vi.push_back(make_pair(l,r));
                //update(0,0,10000002,l-1,r-1,i+1);
                maxn =max(maxn,r);
        }
         l = vi.size();
        for(i=0;i<l;i++) update(0,0,maxn-1,vi[i].first-1,vi[i].second-1,i+1);

        query(0,0,maxn-1);

       // for(it=res.begin();it!=res.end();it++) cout<<*it<< " ";
       // cout<<endl;
        cout<<res.size()<<endl;
        memset(lazy,0,sizeof(lazy));

    }

    return 0;
}
