#ifndef _PROG2_H_
#define _PROG2_H_

#include <iostream>



#include "Prog.h"



using namespace std;

class Prog2 : public Prog
{
  DEFCLASS(Prog2)

   friend ostream& operator<<(ostream& os, const Prog2& aP);

 public :

   // Allocateurs/Desallocateurs

            Prog2(bool decoherenceMode = false);
            Prog2(const Prog2& aP);
            Prog2& operator=(const Prog2& aP);
   virtual ~Prog2(void);

       
           
            void ExecState1(void);
            void ExecState2(void);
            void ExecState3(void);
            
            virtual  void live(double dt);
  

  

   // Inspecteurs/modificateurs

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

 

 protected :

             // ###

 private :

             

};

#endif // _PROG_H_
