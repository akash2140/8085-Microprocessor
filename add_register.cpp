//tested

void add_register(char reg,bool temp[]){
    bool sum=0,carry=0;
    short int i=0;
    cout<<reg<<endl;
    i=7;
    while(i>=0){
        sum=carry ^ temp[i] ^ registers[mask[reg]][i];
        carry=(temp[i] & registers[mask[reg]][i]) | ((temp[i] ^ registers[mask[reg]][i])&carry);
        registers[mask[reg]][i]=sum;
        i--;
    }
}