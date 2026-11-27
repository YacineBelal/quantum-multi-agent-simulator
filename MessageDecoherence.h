#ifndef _MESSAGEDECOHERENCE_H_
#define _MESSAGEDECOHERENCE_H_

#include <iostream>

#include "MAS.h"

#include "MessageBool.h"

using namespace std;

class MessageDecoherence : public MessageBool
{
  DEFCLASS(MessageDecoherence)

   friend ostream& operator<<(ostream& os, const MessageDecoherence& aM);

 public :

   // Allocateurs/Desallocateurs

            MessageDecoherence(bool value=true,float decoherenceRate = 0);
            MessageDecoherence(const MessageDecoherence& aM);
            MessageDecoherence& operator=(const MessageDecoherence& aM);
   virtual ~MessageDecoherence(void);

   // Comparaisons

   friend  bool operator==(const MessageDecoherence& aM1, const MessageDecoherence& aM2);
   friend  bool operator!=(const MessageDecoherence& aM1, const MessageDecoherence& aM2);

   // Inspecteurs/modificateurs
               void setDecoherenceRate(float rate); 
               float getRate(void) const;
   

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const MessageDecoherence& aM) const;

 protected :

             // ###

 private :

             float _decoherenceRate;
             // ###

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const MessageDecoherence& aM);
   void _destroy(void);

};

#endif // _MessageDecoherence_H_
