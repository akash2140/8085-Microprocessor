#include<bits/stdc++.h>
using namespace std;
bool memory[65535][8]={0};
bool registers[7][8]={0};
//convert hexa to binary and return a string
//not tested
map <char,string> hexa_converter;
map <char,int> mask;
//convert binary to decimal
//tested
int btod(string binary){
    int end,ans=0,k=0;
    end=binary.length()-1;
    while(end>=0){
        ans+=(binary[end]-'0') * pow(2,k++);
        end--;
    }
    return ans;
}

void initialize_mask(){
    mask['A']=0; mask['B']=1; mask['C']=2; mask['D']=3; mask['E']=4; mask['H']=5; mask['L']=6;
}
void add_to_accumulator(bool temp[]){
    bool sum=0,carry=0;
    short int i=0;
    //bool ans[8]={0,0,0,0,0,0,0,1};
    /*    while(i<8){
        cout<<temp[i];
        i++;
    }
    cout<<endl;
    i=0;
    while(i<8){
        cout<<ans[i];
        i++;
    }
    cout<<endl;
    */

    i=7;
    while(i>=0){
        sum=carry ^ temp[i] ^ registers[mask['A']][i];
        carry=(temp[i] && registers[mask['A']][i]);
        registers[mask['A']][i]=sum;
        //cout<<sum<<" "<<carry<<endl;
        i--;
        
    }
    i=0;
   /*
   cout<<endl;
    while(i<8){
        cout<<ans[i];
        i++;
    }
*/

}
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
    ans+=hexa_converter[hexa[0]];
    ans+=hexa_converter[hexa[1]];
    return ans;
}

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

//subtract content of register or memory(address specified in HL pair) to the accumulator 
//not tested
void sub_from_accumulator(bool temp[]){
    bool sub=0,borrow=0;
    short int i=0;
    //bool ans[8]={0,0,0,0,0,0,0,1};
    /*    while(i<8){
        cout<<temp[i];
        i++;
    }
    cout<<endl;
    i=0;
    while(i<8){
        cout<<ans[i];
        i++;
    }
    cout<<endl;
    */

    i=7;
    while(i>=0){
        sub=borrow ^ temp[i] ^ registers[mask['A']][i];

        borrow=(temp[i] && !registers[mask['A']][i]) | (!(temp[i] ^ registers[mask['A']][i]) & borrow);
        
        registers[mask['A']][i]=sub;
        //cout<<sum<<" "<<carry<<endl;
        i--;
    }
    i=0;
   /*
   cout<<endl;
    while(i<8){
        cout<<ans[i];
        i++;
    }
*/
}
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
    sub_from_accumulator(temp);
}
//increment content of register or memory(address specified in HL pair) by 1 
//not tested 
void add_register(char reg,bool temp[]){
    bool sum=0,carry=0;
    short int i=0;
    cout<<reg<<endl;
    i=7;
    while(i>=0){
        sum=carry ^ temp[i] ^ registers[mask[reg]][i];
        carry=(temp[i] & registers[mask[reg]][i]) | ((temp[i] ^ registers[mask[reg]][i])&carry);
        registers[mask[reg]][i]=sum;
        cout<<sum<<" "<<carry<<endl;
        i--;
    }
}
void add_memory(int location, bool temp[]){
    bool sum=0,carry=0;
    short int i=0;

    i=7;
    while(i>=0){
        sum=carry ^ temp[i] ^ memory[location][i];
        carry=(temp[i] & memory[location][i]) | ((temp[i] ^ memory[location][i])&carry);
        memory[location][i]=sum;
        i--;
    }
    
}
void sub_memory(int location, bool temp[]){
    bool sub=0,borrow=0;
    short int i=0;

    i=7;
    while(i>=0){
        sub=borrow ^ temp[i] ^ memory[location][i];
        borrow=(temp[i] && !memory[location][i]) | (!(temp[i] ^ memory[location][i]) & borrow);
        memory[location][i]=sub;
        i--;
    }
    
}

//tested

void sub_register(char reg,bool temp[]){
    bool sub=0,borrow=0;
    short int i=0;
    cout<<reg<<endl;
    i=7;
    while(i>=0){
        sub=borrow^ temp[i] ^ registers[mask[reg]][i];
        borrow=(temp[i] && !registers[mask[reg]][i]) | (!(temp[i] ^ registers[mask[reg]][i]) & borrow);
        registers[mask[reg]][i]=sub;
        i--;
    }
}
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
void inr(string command){
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
        add_memory(address_in_memory,temp);
    }
    else{
        add_register(location[0],temp);
    }

}
int main(){
    initialize_mask();
    string str;
    registers[mask['A']][7]=1;
    registers[mask['A']][6]=1;
    registers[mask['A']][5]=1;
    registers[mask['A']][4]=1;

    registers[mask['B']][7]=1;
    registers[mask['B']][6]=1;
    registers[mask['B']][5]=1;
    registers[mask['B']][4]=1;

    registers[mask['H']][7]=1;
    registers[mask['L']][0]=1;
    

    bool temp[8]={0,0,0,0,0,0,0,1};

    getline(cin,str);
    dcr(str);
    int i=0;
    cout<<endl;
    while(i<8){
        cout<<registers[mask['A']][i];
        i++;
    }
    i=0;
    cout<<endl;
    while(i<8){
        cout<<memory[384][i];
        i++;
    }


}