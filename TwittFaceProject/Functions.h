#ifndef __FUNCTION_H
#define __FUNCTION_H

class TwittFace;

void printMenu();
void action(int& value, TwittFace& system);
void addUser(TwittFace& system);
void addFanPage(TwittFace& system);
User* findUser(TwittFace& system, const char* name);
void connectUsers(TwittFace& system)


#endif // !__FUNCTION_H

