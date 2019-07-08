//remove space
void lxi(string command){
    stringstream iss(command);
    string data,word,immediate,binary;
    char destination;
    short int i=0;
    while(iss >> word){
        data=word;
    }
    //cout<<data<<endl;
    destination=data[0];
    immediate=data.substr(2,4);

   // cout<<destination<<" "<<immediate<<endl;
    binary=htob(immediate);

    //cout<<binary<<endl;
    i=0;
    while(i<8){
        registers[mask[destination]][i]=binary[i]-'0';
        i++;
    }
    while(i<16){
        registers[mask[destination]+1][i-8]=binary[i]-'0';
        i++;
    }

}
