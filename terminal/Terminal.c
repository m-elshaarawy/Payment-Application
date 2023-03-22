
#include  "../terminal/Terminal.h"


EN_terminalError_t getTransactionData(ST_terminalData_t* data){

char i=0;
char date[6];
printf("Enter transaction amount : ");
// get transaction amount
scanf("%d",&(data->transAmount));

printf("Enter transaction date  [mm/yy] : ");
// get transDate
scanf("%d",date);
 // check the validity of the date
 if( date[5]!='\0' || date[2]!='/'  || (((date[0]-'0')*10+(date[1]-'0'))>12) || (((date[3]-'0')*10+(date[4]-'0'))>99) ){

 return INVALID_DATA;

 }
// save valid date
for(i=0;i<6;i++){
    data->transDate[i]=date[i];
}

return DONE;
}