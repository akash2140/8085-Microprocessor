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
