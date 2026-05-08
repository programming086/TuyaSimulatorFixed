
#ifndef __THINGDEFINES_H__
#define __THINGDEFINES_H__

#define UNINITIALIZED -1

#define ThingP2PSDK_version "3.9.3"

typedef enum{
    kThingP2PErrCode_ParamsInvalid          = -20002
}ThingP2PErrCode;

typedef struct tagC2C_CMD_P2P_AUTHORIZATION{
    int mark;                                                   // Custom identifier
    int requestId;                                              // Client-defined request ID, used as a unique identifier
    char username[32];
    char password[64];
}C2C_CMD_P2P_AUTHORIZATION;
#define Thing_CUSTOM_HEADER_MARK       0x12345678

#endif // __THINGDEFINES_H__
