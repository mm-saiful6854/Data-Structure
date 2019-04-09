#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int p[30];
set<int>cnt_tree;
set<int>cnt_acorn;
int ranks[30];
void init(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        p[i]=i;
        ranks[i]=0;
    }

}
int find_set(int x)
{
    if(p[x]==x) return x;
    else
        return p[x]=find_set(p[x]);
}

bool IsSameSet(int x,int y)
{
    return find_set(x)==find_set(y);
}

void unions(int x,int y)
{
    int temp1= find_set(x);
    int temp2 = find_set(y);

    if(temp1!=temp2)
    {
        if(ranks[temp1]> ranks[temp2]) p[temp2]=temp1;
        else
        {
            p[temp1]=temp2;
            if(ranks[temp1]==ranks[temp2]) ranks[temp2]++;
        }
    }
}
int tt[2];
int main()
{
    ll t;
    cin>>t;

    while(t--)
    {
        string s;
        int i,j;
        init(28);
        cnt_tree.clear();

        cnt_acorn.clear();
        while(cin>>s)
        {
            if(s[0]=='*')
                break;

            else
            {
                tt[0]=0;
                tt[1]=0;
                for(i=0,j=0; i<s.size(); i++)
                {
                    if(s[i]>='A' && s[i]<='Z')
                    {
                        tt[j] = (s[i]-'A')+1;
                        j++;
                    }
                }
            }
            unions(tt[0],tt[1]);
        }

        cin>>s;

        for(i=0; i<s.size(); i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                int root = find_set((s[i]-'A')+1);
                if(ranks[root]>0)
                {
                   // cout<<"tree "<<s[i]<<" "<<root<<endl;
                    cnt_tree.insert(root);
                }
                else if(ranks[root]==0){
                       // cout<<root<<endl<<s[i]<<endl;
                    cnt_acorn.insert(root);
                }
            }
        }

        printf("There are %d tree(s) and %d acorn(s).\n",cnt_tree.size(),cnt_acorn.size());
    }

    return 0;

}
