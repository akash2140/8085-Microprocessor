//mvi
//tested
//no gap between registers
//in this format
//remove H from last of hexadecimal
void mvi(string command){
    char source,destination;
    string word,data,binary,value;
    stringstream iss(command);
    int i=0,address_in_memory;
    bool temp[8]={0};

    while(iss >> word){
        data=word;
    }
    destination=data[0];
    value=data.substr(2,2);
    cout<<destination<<" "<<value<<endl;
    binary=htob(value);
    cout<<binary<<endl;
    i=0;
    while(i<8){
        temp[i]=binary[i] - '0';
        i++;
    }
    binary.clear();
    if(destination=='M'){
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

        address_in_memory=btod(binary);
        //cout<<address_in_memory<<endl;
        i=0;
        while(i<8){
            memory[address_in_memory][i]=temp[i];
            i++;
        }

    }
    else{
        i=0;
        while(i<8){
        registers[mask[destination]][i]=temp[i];
        i++;
        }
    }
}
