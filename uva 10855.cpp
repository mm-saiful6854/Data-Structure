#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string>ss;
vector<string>s;

ll findstring(ll N,ll n)
{
    ll i,j,p,q,cnt=0;
    bool flag = true;
    for(i=0; n+i<=N; i++)
    {
        for(j=0; n+j<=N; j++)
        {
            flag=true;
            for(p=0; p<n; p++)
            {
                for(q=0; q<n; q++)
                {
                    if( ss[i+p][j+q]!=s[p][q])
                    {
                        flag = false;
                    }
                }
            }
            if(flag)
                cnt++;
        }
    }
    return cnt;
}

void rotates(ll n)
{
    vector<string>sp;
    int p=-1,i,j;

    for(j=0; j<n; j++)
    {
        p++;
        string temp="";
        for(i=n-1; i>=0; i--)
        {

            temp+=s[i][j];
        }

        sp.push_back(temp);
    }
    for(i=0;i<n;i++)
    {
        s[i]=sp[i];

    }

}


int main()
{
    ll N,n;
    while(cin>>N>>n)
    {

        if(N==0 && n==0)
            break;
       // string ss[N],s[n];
        string temp;
        int i;
        for(i=0; i<N; i++)
        {
            cin>>temp;
            ss.push_back(temp);
        }

        for(i=0; i<n; i++)
        {
            cin>>temp;
            s.push_back(temp);
        }
        ll c=0;
        for(i=0; i<4; i++)
        {
            c   = findstring(N,n);
            cout<<c;
            if(i<3) cout<<" ";
            rotates(n);

        }
        cout<<endl;
        s.clear();
        ss.clear();
    }

    return 0;
}
