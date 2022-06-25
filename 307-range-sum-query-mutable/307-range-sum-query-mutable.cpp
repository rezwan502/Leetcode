class NumArray {
public:
     // Segment Tree Solution //
    
    int segment[4*100000]={0};
    vector<int> temp;
    int n;
    
    void build(int index, int low, int high) {
        if(low == high){
            segment[index] = temp[low];
            return;
        }
        
        int mid = (low + high)/2;
        
        build(2*index + 1, low, mid);
        build(2*index + 2, mid + 1, high);
        
        segment[index] = segment[2*index + 1] + segment[2*index + 2];
    }
    
    void update_segment(int index, int low, int high, int id, int value){
        
        if(id > high || id < low) return;
        
        if(low >= id && high <= id){
            segment[index] = value;
            return;
        }
        
        int mid = (high + low)/2;
        
        update_segment(2*index + 1, low, mid, id, value);
        update_segment(2*index + 2, mid + 1, high, id, value);
        
        segment[index] = segment[2*index + 1] + segment[2*index + 2];
        
    }
    
    int query(int index, int low, int high, int l, int r){
        if(low >= l && high <= r){
            return segment[index];
        }
        if(high < l || low > r) return 0;
        
        int mid =(low + high)/2;
        
        int left = query(2*index + 1, low, mid, l, r);
        int right = query(2*index + 2, mid + 1, high, l, r);
        
        return left + right;
    }
    
        
    NumArray(vector<int>& nums) {
        for(auto x: nums){
            temp.push_back(x);
        }
        n = temp.size();
        build(0, 0, n-1);
    }

    void update(int index, int val) {
        update_segment(0, 0, n-1, index, val);
    }

    int sumRange(int l, int r) {    
        return query(0, 0, n-1, l, r); 
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */