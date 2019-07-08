//tested
void stax(string command){
    short int i=0,address;
    stringstream iss(command);
    string binary,data,word;
    while(iss >> word){
        data=word;
    }
   // cout<<data<<endl;
    
    i=0;
    while(i<8){
        binary+=registers[mask[data[0]]][i] + '0';
       // cout<<binary<<endl;
        i++;
    }
    i=0;
    while(i<8){
        binary+=registers[mask[data[0]]+1][i] + '0';
        i++;
    }
   // cout<<binary<<endl;
    address=btod(binary);
    //cout<<address<<endl;
    i=0;
    while(i<8){
        memory[address][i]=registers[mask['A']][i];
        i++;
    }
}