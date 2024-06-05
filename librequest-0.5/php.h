#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "config.h"
#include <arpa/inet.h>
#include "fastcgi.h"

int createConnexion();
void send_begin_request(int sock, unsigned short requestId);
char *generateFileName(const char *filename);
void encode_name_value_pair(const char *name, const char *value, unsigned char *buffer, int *len);
char *getScriptName(const char *filename);
char *getScriptFilename(const char *filename);
void send_params(int sock, unsigned short requestId, const char *name, const char *value);
void send_empty_params(int sock, unsigned short requestId);
void send_stdin(int sock, unsigned short requestId, const char *data) ;
FCGI_Header *receive_response(int sock, char* HexData);