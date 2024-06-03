#include "request.h"
#include "config.h"


typedef struct {
    char *label;
    char *value;
} Header;

typedef struct {
    int code;
    char *info;
} HttpCode;

typedef struct {
    HttpCode *code;
    int httpminor;
    char *filename;
    Header *headers;
    int headersCount;
} HttpReponse;

typedef struct {
    HttpCode *table[NB_HTTP_CODES];
    int httpminor;
    char *filename;
    Header *headers;
    int headersCount;
} HTTPTable;


uint32_t hash(uint32_t code, uint32_t nbTry);
void initTable(HTTPTable *codes);
void freeTable(HTTPTable *codes);
void addTable(HTTPTable *codes, int code, char *info);
HTTPTable *loadTable();
HttpReponse *getTable(HTTPTable *codes, int code);

void updateHeader(HTTPTable *codes, char *label, char *value);
int configFileMsgBody(char *name, HTTPTable *codes);

message *createMsgFromReponse(HttpReponse rep, unsigned int clientId);
int getRepCode(message req, HTTPTable *codes) ;
message *generateReponse(message req, int opt_code);