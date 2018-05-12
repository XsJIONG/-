#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

namespace Problem {
    int n,m,x,y,k;
    short a[502][502];
    const int Mx[]={-1,0,1,0},My[]={0,1,0,-1};
    bool walked[502][502];
    int ans;
    bool ch;
    void ReadData() {
        ch=true;
        cin>>n>>m>>x>>y>>k;
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    }
    inline bool block(int x, int y) {
        return x<1||y<1||x>n||y>m||a[x][y]==2;
    }
    void find(int x, int y, int d, int z, int forbid) {
        if (walked[x][y]) return;
        if (d>=k) {
            if (z<ans||ch) {
                ans=z;
                ch=false;
            }
            return;
        }
        walked[x][y]=true;
        z++;
        int qwe,xx,yy;
        for (int i=0;i<4;i++) {
            qwe=0;
            xx=x, yy=y;
            while (!block(xx+Mx[i],yy+My[i])) {
                xx+=Mx[i], yy+=My[i];
                qwe+=a[xx][yy]==1;
            }
            if (xx==x&&yy==y) continue;
            find(xx,yy,d+qwe,z,(i+2)%4);
        }
        walked[x][y]=false;
    }
    void Solve() {
        find(x,y,a[x][y]==1,0,-1);
        if (ch) cout<<"-1"<<endl; else cout<<ans<<endl;
        return;
    }
}

int main() {
    Problem::ReadData();
    Problem::Solve();
    return 0;
}
