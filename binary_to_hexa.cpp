//convert binary to hexadecimal
//tested[*]
map <string,char> convert;
void initialize(){
    convert["0000"]='0';
    convert["0001"]='1';
    convert["0010"]='2';
    convert["0011"]='3';
    convert["0100"]='4';
    convert["0101"]='5';
    convert["0110"]='6';
    convert["0111"]='7';
    convert["1000"]='8';
    convert["1001"]='9';
    convert["1010"]='A';
    convert["1011"]='B';
    convert["1100"]='C';
    convert["1101"]='D';
    convert["1110"]='E';
    convert["1111"]='F';
}
string btoh(string binary){
    initialize();
    string str,ans;
    int len,i=0;
    len=binary.length();
    while(i<len){
        cout<<convert[binary.substr(i,4)];
        i+=4;
    }
    return ans; 
}   
