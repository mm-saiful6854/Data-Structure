#include<bits/stdc++.h>
using namespace std;



//vector<int>values;

typedef pair<int, int> ii;

typedef vector<ii> vii;


//vector<pair<int,int> >vp[10002];
//vector<vii> vp, transpose;

vector<pair<int,int> >vp[10003];
vector<pair<int,int> >transpose[10003];


int main()
{
   //freopen("input.txt","r",stdin);

    //freopen("output.txt","w",stdout);
    int m,n;
    string temp;
    int index[1003];
    int i,r,y,row,x,val;
    while(scanf("%d %d", &m, &n) != EOF)
    {

//        vp.assign(m,vector<pair<int,int> >());
//
//       transpose.assign(n,vector<pair<int,int> >());

    for(i=0;i<=n+2;i++) transpose[i].clear();

       for(x=0;x<m;x++)
        {
            vp[x].clear();
            cin>>r;

            if(r==0)
            {
                getline(cin,temp);
                continue;
            }
            for(i=0; i<r; i++)
            {
                cin>>y;
                index[i]=y;
            }
            for(i=0; i<r; i++)
            {
                cin>>val;
                vp[x].push_back(ii(val,index[i]-1));
            }
        }

        //index.clear();

//        for(row=0;row<m;row++)
//        {
//            cout<<vp[row].size()<<endl;
//            for(x = 0;x<(int)vp[row].size();x++)
//            {
//
//                pair<int,int>p = vp[row][x];
//                cout<<p.first<<" "<<p.second<<endl;
//               // transpose[p.second].push_back(ii(p.first,row+1));
//            }
//            //vp[row].clear();
//        }


        cout<<n<<" "<<m<<endl;

        for(row=0;row<m;row++)
        {
           // cout<<vp[row].size()<<endl;
            for(x = 0;x<(int)vp[row].size();x++)
            {

                pair<int,int>p = vp[row][x];
                //cout<<p.first<<" "<<p.second<<endl;
                transpose[p.second].push_back(ii(p.first,row+1));
            }
            //vp[row].clear();
        }



        for(row = 0;row<n;row++)
        {
            cout<<transpose[row].size();
            for(x = 0;x<(int)transpose[row].size();x++)
            {
                pair<int,int> p = transpose[row][x];
               // values.push_back(p.first);
                //index.push_back(p.second);
                //cnt++;
                cout<<" "<<p.second;
            }
           // transpose[row].clear();
           cout<<endl;

           for(x = 0;x<(int)transpose[row].size();x++)
            {
                pair<int,int> p = transpose[row][x];
                cout<<p.first;
                if(x<transpose[row].size()-1)cout<<" ";
            }
           cout<<endl;
          // transpose[x].clear();

        }

    }
    return 0;
}

