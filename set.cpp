void set_(string command){
    
    stringstream iss(command);
    string data,word,destination,value,binary;
    short int address,i=0;
    
    while(iss >> word){
        data=word;
    }
    
    destination=data.substr(0,4);
    value=data.substr(5,2);
    cout<<destination<<" "<<value<<endl;

    binary=htob(destination);
    address=btod(binary);

    value=htob(value);

    i=0;
    while(i<8){
        memory[address][i]=value[i]-'0';
        i++;
    }

}