int n,m,i,a,b,c;
int ans[MAXN<<2],add[MAXN<<2],inp[MAXN<<2];
 
inline int ls(const int&p){
    return p<<1;
}
 
inline int rs(const int&p){
    return p<<1|1;
}
 
inline int Max(const int&x,const int&y){
    return x>y?x:y;
}
 
inline void push_up(const int&p,const int&tag){
    ans[p]=Max(ans[ls(p)],ans[rs(p)])+tag;
}
 
void build(const int l=1,const int r=n,const int p=1){
    if(l==r){
        get(ans[p]);
        inp[l]=ans[p];
        return;
    }
    int mid=(l+r)>>1;
    build(l, mid, ls(p));
    build(mid+1,r,rs(p));
    push_up(p,0);
}
 
inline void update(const int&x,const int&y,const int&k,const int&l=1,const int&r=n,const int&p=1){
    if(l>=x&&r<=y){
        add[p]+=k;
        ans[p]+=k;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid){
        update(x,y,k,l, mid, ls(p));
    }
    if(y>mid){
        update(x,y,k,mid+1,r,rs(p));
    }
    push_up(p,add[p]);
}
 
inline int query(const int &x,const int &y,const int &tag=0,const int &l=1,const int &r=n,const int &p=1){
    if(l>=x&&r<=y){
        return ans[p]+tag;
    }
    int mx=-1;
    int mid=(l+r)>>1;
    if(x<=mid){
        mx=Max(mx,query(x,y,tag+add[p],l, mid, ls(p)));
    }
    if(y>mid){
        mx=Max(mx,query(x,y,tag+add[p],mid+1,r,rs(p)));
    }
    return mx;
}
