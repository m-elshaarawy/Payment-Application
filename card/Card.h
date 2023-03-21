
#ifndef CARD_H_
#define CARD_H_

 /* data typs and structs */

typedef struct {

char name[25];     // card holder name 
char ExpDate[6];   // card expiry date mm/yy
char PAN[20];      // card PAN

}ST_cardData_t;


typedef enum {

INVALID_NAME,
INVALID_DATE,
INVALID_PAN,
VALID

}EN_cardError_t;


/* Function prototypes */

EN_cardError_t getCardHolderName(ST_cardData_t* card);
EN_cardError_t getCardExpiryDate(ST_cardData_t* card);
EN_cardError_t getCardPAN(ST_cardData_t* card);



#endif // CARD_H_
