//add immediate data to accumulator
//not tested
void adi(string command){
    //creating string stream
    stringstream stream(command);
    string word,immediate_data,binary;
    bool temp[8];
    int i=0;
    while(stream >> word){
        immediate_data=word;
    }
    binary=htob(immediate_data);
    cout<<binary<<endl;
    i=0;
    while(i<8){
            temp[i]=binary[i]-'0';
            cout<<temp[i];
            i++;
        }
    cout<<endl;
    
    //take one register and add it to accumulator
    add_to_accumulator(temp);
}