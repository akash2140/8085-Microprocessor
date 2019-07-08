//convert hexa to binary and return a string
//tested
map <char,string> hexa_converter;

void initialize_hexa(){
    hexa_converter['0']="0000";
    hexa_converter['1']="0001";
    hexa_converter['2']="0010";
    hexa_converter['3']="0011";
    hexa_converter['4']="0100";
    hexa_converter['5']="0101";
    hexa_converter['6']="0110";
    hexa_converter['7']="0111";
    hexa_converter['8']="1000";
    hexa_converter['9']="1001";
    hexa_converter['A']="1010";
    hexa_converter['B']="1011";
    hexa_converter['C']="1100";
    hexa_converter['D']="1101";
    hexa_converter['E']="1110";
    hexa_converter['F']="1111";
}
string htob(string hexa){
    initialize_hexa();
    string ans;
    short int len=hexa.size(),i=0;
    while(i<len){
        ans+=hexa_converter[hexa[i]];
        i++;
    }
    return ans;
}