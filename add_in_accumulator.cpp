//add content of register or memory(address specified in HL pair) to the accumulator 

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
