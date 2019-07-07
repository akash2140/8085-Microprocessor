//decrement content of register or memory(address specified in HL pair) by 1 
//tested 
void dcr(string command){
    initialize_mask();
    //creating string stream
    stringstream stream(command);
    string word,location,binary;
    bool temp[8]={0,0,0,0,0,0,0,1};
    int i=0;
    int address_in_memory;
    while(stream >> word){
        location=word;
    }
    cout<<location[0]<<endl;
    //memory
    if(location[0]=='M'){
        i=0;
        while(i<8){
            binary+=registers[mask['H']][i]+'0';
            i++;
        }
        i=0;
       
        while(i<8){
            binary+=registers[mask['L']][i]+'0';
            i++;
        }
         cout<<binary<<endl;
        address_in_memory=btod(binary);
        cout<<"address\n"<<address_in_memory<<endl;
        sub_memory(address_in_memory,temp);
    }
    else{
        sub_register(location[0],temp);
    }

}