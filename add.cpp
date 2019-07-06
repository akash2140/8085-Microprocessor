//add content of register or memory(address specified in HL pair) to the accumulator 
//not tested fully
map <char,int> mask;
void initialize_mask(){
    mask['A']=0; mask['B']=1; mask['C']=2; mask['D']=3; mask['E']=4; mask['H']=5; mask['L']=6;
}
void add(string command){
    initialize_mask();
    //creating string stream
    stringstream stream(command);
    string word,location,binary;
    bool temp[8];
    int i=0;
    int address_in_memory;
    while(stream >> word){
        location=word;
    }
    cout<<location[0]<<endl;
    //memory
    if(location[0]=='M'){
        i=0;
        while(i<8)
            binary+=registers[5][i++];

        i=0;
        while(i<8)
            binary+=registers[6][i++];
       // address_in_memory=btod(binary);
        i=0;
        while(i<8){
            temp[i]=memory[address_in_memory][i++];
        }
    }
    else{
    i=0;
        while(i<8){
            temp[i]=registers[mask[location[0]]][i];
            cout<<temp[i];
            i++;
        }
    }
    //take two register and add them
    add_to_accumulator(temp);
}