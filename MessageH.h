#ifndef _MESSAGEH_H_
#define _MESSAGEH_H_

#include <iostream>

#include "MAS.h"

#include "MessageBool.h"

using namespace std;

class MessageH : public MessageBool
{
  DEFCLASS(MessageH)

   friend ostream& operator<<(ostream& os, const MessageH& aM);

 public :

   // Allocateurs/Desallocateurs

            MessageH(bool value,int size);
            MessageH(const MessageH& aM);
            MessageH& operator=(const MessageH& aM);
   virtual ~MessageH(void);

   // Comparaisons

   friend  bool operator==(const MessageH& aM1, const MessageH& aM2);
   friend  bool operator!=(const MessageH& aM1, const MessageH& aM2);

   // Inspecteurs/modificateurs

   void setSize(int size); 
   int getSize(void) const;
   

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const MessageH& aM) const;

 protected :

             // ###

 private :

             int _size;

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const MessageH& aM);
   void _destroy(void);

};

#endif // _MESSAGEH_H_
