//subtract content of register or memory(address specified in HL pair) to the accumulator 
//tested fully

void sub(string command){
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
            binary+=registers[mask['H']][i++]+'0';

        i=0;
        while(i<8)
            binary+=registers[mask['L']][i++]+'0';
       address_in_memory=btod(binary);
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
    sub_from_accumulator(temp);
}