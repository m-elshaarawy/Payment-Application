
#include "Server.h"

static unsigned int trans_count=0; // hold transaction number  

// small account database    contain  PAN , account_state , funds 
static ST_accountDatabase_t accountDatabase[6]={
    {"0676362769002729", ACTIVE  ,50000},
    {"7012292292334563", ACTIVE  ,40000},
    {"3899713628095627", BLOCKED ,0},
    {"9804196396743949", ACTIVE  ,100000},
    {"0877553266672886", ACTIVE  ,10000},
    {"3660604046475564", BLOCKED ,0}
    };

// transactions database 
static ST_transDatabase_t transDatabase[200]={0};

