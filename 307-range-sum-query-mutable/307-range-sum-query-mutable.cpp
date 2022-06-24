class NumArray {
public:
    // Square Root Solution //
    int segment[10001]={0};
    vector<int> temp;
    int n;
    int seg_size;
    
    void sqrt_preprocess(){
        seg_size = sqrt(n);
        int cur_seg = -1;
        for(int i=0; i<n; i++){
            if(i%seg_size == 0){
                cur_seg++;
            }
            segment[cur_seg] += temp[i];
        }
    }
    
    NumArray(vector<int>& nums) {
        for(int x: nums){
            temp.push_back(x);
        }
        n = temp.size();
        sqrt_preprocess();
    }
    
    void update(int index, int val) {
        int seg_no = index/seg_size;
        segment[seg_no] = segment[seg_no] - temp[index] + val;
        temp[index] = val;
    }
    
    int sumRange(int l, int r) {    
        int sum = 0;
        
        while( l<=r && l%seg_size != 0){
            sum += temp[l];
            l++;
        }
        
        while(l+seg_size <= r){
            sum += segment[l/seg_size];
            l = l + seg_size;
        }
        
        while(l<=r){
            sum += temp[l];
            l++;
        }
        
        return sum; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */