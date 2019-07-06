void add_to_accumulator(bool temp[]){
    bool sum=0,carry=0;
    short int i=7;
    bool ans[8]={0,0,0,0,1,1,1,1}
    while(i>=0){
        sum=carry ^ temp[i] ^ans[i];
        ans[i]=sum;
        carry=(temp[i] &ans[i]) & ( temp[i] ^ans[i] )&carry;
        i--;
        
    }
    i=0;
    while(i<8){
        cout<<ans[i];
    }


}