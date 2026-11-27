#ifndef _MESSAGEX_H_
#define _MESSAGEX_H_

#include <iostream>

#include "MAS.h"

#include "MessageBool.h"

using namespace std;

class MessageX : public MessageBool
{
  DEFCLASS(MessageX)

   friend ostream& operator<<(ostream& os, const MessageX& aM);

 public :

   // Allocateurs/Desallocateurs

            MessageX(bool value=true);
            MessageX(const MessageX& aM);
            MessageX& operator=(const MessageX& aM);
   virtual ~MessageX(void);

   // Comparaisons

   friend  bool operator==(const MessageX& aM1, const MessageX& aM2);
   friend  bool operator!=(const MessageX& aM1, const MessageX& aM2);

   // Inspecteurs/modificateurs

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const MessageX& aM) const;

 protected :

             // ###

 private :

             // ###

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const MessageX& aM);
   void _destroy(void);

};

#endif // _MESSAGEX_H_
