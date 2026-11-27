#ifndef _MessageG_H_
#define _MessageG_H_

#include <iostream>

#include "MAS.h"

#include "MessageBool.h"

using namespace std;

class MessageG : public MessageBool
{
  DEFCLASS(MessageG)

   friend ostream& operator<<(ostream& os, const MessageG& aM);

 public :

   // Allocateurs/Desallocateurs

            MessageG(bool value,int state);
            MessageG(const MessageG& aM);
            MessageG& operator=(const MessageG& aM);
   virtual ~MessageG(void);

   // Comparaisons

   friend  bool operator==(const MessageG& aM1, const MessageG& aM2);
   friend  bool operator!=(const MessageG& aM1, const MessageG& aM2);

   // Inspecteurs/modificateurs

   void setState(int size); 
   int getState(void) const;
   

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const MessageG& aM) const;

 protected :

             // ###

 private :

             int _state;

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const MessageG& aM);
   void _destroy(void);

};

#endif // _MessageG_H_
