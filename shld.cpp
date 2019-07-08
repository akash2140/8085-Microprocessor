//tested
void shld(string command){
    stringstream iss(command);
    string word,data,binary;
    short int i=0,address;

    while(iss >> word){
        data=word;
    }
    cout<<data<<endl;
    binary=htob(data);
    address=btod(binary);

    i=0;
    while(i<8){
        memory[address][i]=registers[mask['L']][i];
        i++;
    }
    address++;
    i=0;
    while(i<8){
        memory[address][i]=registers[mask['H']][i];
        i++;
    }
}