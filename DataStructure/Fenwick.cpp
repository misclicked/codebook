vector<int> bit;
int size;
int lowbit(int x){
    return x & (-x);
}
void update(int p, int val){
    while(p <= size){
        bit[p] += val;
        p += lowbit(p);
    }
}
int sum(int p){
    int ans = 0;
    while(p > 0){
        ans += bit[p];
        p -= lowbit(p);
    }
    return ans;
}
vector<int> countSmaller(vector<int>& nums) {
    if(nums.empty()){
        return vector<int>{};
    }
    size = nums.size();
    vector<int> ans(size, 0);
    bit = vector<int>(size + 1, 0);
    vector<int> tmp = nums;
    unordered_map<int, int> m;
    sort(tmp.begin(), tmp.end());
    for(int i = 0;i < size; ++i){
        m[tmp[i]] = i + 1;
    }
    for(int i = size - 1;i >= 0; --i){
        ans[i] = sum(m[nums[i]] - 1);
        update(m[nums[i]], 1);
    }
    return ans;
}
