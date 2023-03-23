# Payment-Application

C project in Embedded Systems Professional Track provided by `egFWD` powered by `Udacity` in collaboration with `Sprints`.
The project is developed using `Visual Studio Code` `+` `GNU GCC Compiler`.

## System Description

-It is a simulation for the Mini pay device or(ATMs) Transactions.

-I implemented the SALE transaction only by simulating the card, terminal(ATM), and server using the `C programming language`.

-Card Module is responsible for storing the card data which is Card Holder Name, Primary Account Number, and Card Expiry Date.

-Terminal (ATM) Module is responsible for user interfacing. The module stores the transaction date and checks whether the card is expired or valid. Also, it stores the transaction amount and checks if it exceeds the max limit allowed for the ATM.

-Server Module is responsible for authentication and account verification. It checks if the account is found within the server database if the account state whether Active , Blocked  or Invalid_Account  and if the account has a sufficient amount to withdraw or not.

## System Constraints
### Card Module

-Card Holder Name must be Uppercase chars  and 24 chars maximum .

-Card Expiry Date must be in form MM/YY.

-Primary Account Number must be 16 chars all numbers  .

### Terminal Module

-Transaction Date must be in form MM/YY.

-Transaction Amount must be a positive non-zero value.

-Terminal Max Amount must be set as an initialization for the Terminal or through the configuration in the Terminal.h file .

### Server Module

-No constraints on input data.

## Flowchart

![flowchart](https://user-images.githubusercontent.com/35842023/227143597-7e62001d-0c4a-4666-878d-f45c7f7f5ab5.jpg)
