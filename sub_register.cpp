//tested
void sub_register(char reg,bool temp[]){
    bool sub=0,borrow=0;
    short int i=0;
    cout<<reg<<endl;
    i=7;
    while(i>=0){
        sub=borrow^ temp[i] ^ registers[mask[reg]][i];
        borrow=(temp[i] && !registers[mask[reg]][i]) | (!(temp[i] ^ registers[mask[reg]][i]) & borrow);
        registers[mask[reg]][i]=sub;
        i--;
    }
}