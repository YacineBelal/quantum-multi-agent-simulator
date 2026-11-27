#ifndef _MESSAGEBOOL_H_
#define _MESSAGEBOOL_H_

#include <iostream>

#include "MAS.h"

#include "Message.h"

using namespace std;

class MessageBool : public Message
{
  DEFCLASS(MessageBool)

   friend ostream& operator<<(ostream& os, const MessageBool& aM);

 public :

   // Allocateurs/Desallocateurs

            MessageBool(bool value);
            MessageBool(const MessageBool& aM);
            MessageBool& operator=(const MessageBool& aM);
   virtual ~MessageBool(void);

            void setValue(bool value);
            bool getValue(void) const;

   // Comparaisons

   friend  bool operator==(const MessageBool& aM1, const MessageBool& aM2);
   friend  bool operator!=(const MessageBool& aM1, const MessageBool& aM2);

   // Inspecteurs/modificateurs

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const MessageBool& aM) const;

 protected :

             bool _value;

 private :

             // ###

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const MessageBool& aM);
   void _destroy(void);

};

#endif // _MESSAGEBOOL_H_
