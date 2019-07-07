void add_memory(int location, bool temp[]){
    bool sum=0,carry=0;
    short int i=0;

    i=7;
    while(i>=0){
        sum=carry ^ temp[i] ^ memory[location][i];
        carry=(temp[i] & memory[location][i]) | ((temp[i] ^ memory[location][i])&carry);
        memory[location][i]=sum;
        i--;
    }
    
}