//convert binary to decimal
//tested
int btod(string binary){
    int end,ans=0,k=0;
    end=binary.length()-1;
    while(end>=0){
        ans+=(binary[end]-'0') * pow(2,k++);
        end--;
    }
    return ans;
}
