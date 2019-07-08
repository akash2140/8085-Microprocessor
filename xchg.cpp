//not tested
void xchg(){
    short int i=0;

    while(i<8){
        registers[mask['D']][i]=registers[mask['H']][i];
        i++;
    }
    i=0;
    while(i<8){
        registers[mask['E']][i]=registers[mask['L']][i];
        i++;
    }
}