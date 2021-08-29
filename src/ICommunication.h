/**
 * @file    ICommunication.h
 * @brief   Interface for communication protocols
 * @author  m2enu
 * @date    2021/08/29
 * @par     License
 *          https://github.com/m2enu/clang_interface/blob/main/LICENSE
 */
#ifndef I_COMMUNICATION_H_INCLUDED
#define I_COMMUNICATION_H_INCLUDED

#define IC_CAST(p)      ((ICommunication *)(&(p)))

struct CommunicationMethods;

typedef struct ICommunication
{
    const struct CommunicationMethods * p_methods;
} ICommunication;

typedef struct CommunicationMethods
{
    void (*open)(ICommunication * const);
    void (*close)(ICommunication * const);
} CommunicationMethods;

void IC_Open(ICommunication * const);
void IC_Close(ICommunication * const);

#endif  /* I_COMMUNICATION_H_INCLUDED */
