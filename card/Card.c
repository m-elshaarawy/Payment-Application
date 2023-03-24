

#include "Card.h"



EN_cardError_t getCardHolderName(ST_cardData_t* card){
 
 char counter=0 , i=0; 
 char data[25];
 printf("Enter name as on card [<=24 (char+' ')]: ");
 fflush(stdin);
 scanf("%[^\n]%*c",data);

for(i=0;data[i];i++){
//checking for lowercase chars
if( data[i] >= 'a' && data[i] <= 'z'){

return INVALID_NAME;

  }
counter++;
}

// checking for overflow 
if(counter>24){
return INVALID_NAME; 
}

// copying  valid name 
for(i=0;i<=counter;i++){
card->name[i]=data[i];
}

return VALID;
}



EN_cardError_t getCardExpiryDate(ST_cardData_t* card){

 char data[6];
 char i=0;
 printf("Enter expiry date as on card [mm/yy] : ");
 fflush(stdin);
 gets(data);
 
 // check the validity of the date
 if( data[5]!='\0' || data[2]!='/'  || (((data[0]-'0')*10+(data[1]-'0'))>12) || (((data[3]-'0')*10+(data[4]-'0'))>99) ){

 return INVALID_DATE;

 }

 // copy valid date
 for(i=0;i<6;i++){

 card->ExpDate[i]=data[i];

 }

 return VALID;
}



EN_cardError_t getCardPAN(ST_cardData_t* card){

  char count=0, i=0;
  char data[17];

  printf("Enter PAN as on card [16 number] : ");
  fflush(stdin);
  scanf(" %s",data);

  for ( i = 0; data[i] ; i++)
  {
     // check if all data are numbers 
     if(!((data[i]>='0')&&(data[i]<='9'))){

       return INVALID_PAN;
     }

     count++;
  }
  
  // check for overflow
 if(count!=16){
    
    return INVALID_PAN;
 }

  // copy valid PAN
  for ( i = 0; i <= count; i++)
  {
    card->PAN[i]=data[i];
  }

 return VALID;
}
