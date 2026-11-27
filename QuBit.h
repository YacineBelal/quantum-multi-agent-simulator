#ifndef _QUBIT_H_
#define _QUBIT_H_

#include <iostream>

#include "MAS.h"

#include "Agent.h"

using namespace std;

typedef // état du qubit, soit à 0, soit à 1, soit en superposition.
        enum State { Calm, Excited, Superposition }
        QuBitState;

class QuBit : public Agent
{
  DEFCLASS(QuBit)

   friend ostream& operator<<(ostream& os, const QuBit& aQ);

 public :

   // Allocateurs/Desallocateurs

            QuBit(void);
            QuBit(float prob0,float prob1);
            QuBit(const QuBit& aQ);
            QuBit& operator=(const QuBit& aQ);
   virtual ~QuBit(void);

            float getProb1(void) const;
            float getProb0(void) const;
            float getProb(int state) const;

   private: void      _setState(void);
            void X(void);
            void Hadamard(int size);
            void G(int state);
            void Decoherence(float rate);

   public:  QuBitState getState(void) const;
            string     getStateString(void) const;

            void   synchronizeQuBit(void);
            void  measure(void); // puts the Qubit in the 1 or 0 state then returns its value.

   virtual  void live(double dt);

            size_t treatAllMessages(void);
            
   // Comparaisons

   friend  bool operator==(const QuBit& aQ1, const QuBit& aQ2);
   friend  bool operator!=(const QuBit& aQ1, const QuBit& aQ2);

   // Inspecteurs/modificateurs

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const QuBit& aQ) const;

 protected :

             // ###

 private :

            float _prob0;
            float _prob1;
            float _prob0Next;
            float _prob1Next;
            QuBitState _state;

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const QuBit& aQ);
   void _destroy(void);

};

#endif // _QUBIT_H_
