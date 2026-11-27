#ifndef _PROG1_H_
#define _PROG1_H_

#include <iostream>



#include "Prog.h"



using namespace std;

class Prog1 : public Prog
{
  DEFCLASS(Prog1)

   friend ostream& operator<<(ostream& os, const Prog1& aP);

 public :

   // Allocateurs/Desallocateurs

            Prog1(bool decoherenceMode = false);
            Prog1(const Prog1& aP);
            Prog1& operator=(const Prog1& aP);
   virtual ~Prog1(void);

            static bool RecognitionFunction(int register_state);
       
           

            void ExecState1(void);
            void ExecState2(void);
            void ExecState3(void);
            void ExecState4(void);
    
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
