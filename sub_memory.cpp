//tested
void sub_memory(int location, bool temp[]){
    bool sub=0,borrow=0;
    short int i=0;

    i=7;
    while(i>=0){
        sub=carry ^ temp[i] ^ memory[location][i];
        borrow=(temp[i] && !memory[location][i]) | (!(temp[i] ^ memory[location][i]) & borrow);
        memory[location][i]=sub;
        i--;
    }
    
}