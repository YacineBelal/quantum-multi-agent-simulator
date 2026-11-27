#ifndef _MESSAGEM_H_
#define _MESSAGEM_H_

#include <iostream>

#include "MAS.h"

#include "MessageBool.h"

using namespace std;

class MessageM : public MessageBool
{
  DEFCLASS(MessageM)

   friend ostream& operator<<(ostream& os, const MessageM& aM);

 public :

   // Allocateurs/Desallocateurs

            MessageM(bool value=true);
            MessageM(const MessageM& aM);
            MessageM& operator=(const MessageM& aM);
   virtual ~MessageM(void);

   // Comparaisons

   friend  bool operator==(const MessageM& aM1, const MessageM& aM2);
   friend  bool operator!=(const MessageM& aM1, const MessageM& aM2);

   // Inspecteurs/modificateurs

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const MessageM& aM) const;

 protected :

             // ###

 private :

             // ###

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const MessageM& aM);
   void _destroy(void);

};

#endif // _MessageM_H_
