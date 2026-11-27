#ifndef _PROG_H_
#define _PROG_H_

#include <iostream>

#include "MAS.h"

#include "Agent.h"

#include "QuBit.h"

using namespace std;

class Prog : public Agent
{
  DEFCLASS(Prog)

   friend ostream& operator<<(ostream& os, const Prog& aP);

 public :

   // Allocateurs/Desallocateurs

            Prog(bool decoherenceMode = false);
            Prog(const Prog& aP);
            Prog& operator=(const Prog& aP);
   virtual ~Prog(void);

            void X(QuBit* qubit);
            void Hadamard(QuBit* qubit,int size = 1);
            void CNOT(QuBit* qubit, QuBit* res_qubit);
            void CNOTN(vector<QuBit*> qubit, QuBit* res_qubit);
            void MeasureQubit(QuBit* qubit);
            void GroverOracle(bool (*RecognitionFunction)(int));
           
            void Decoherence();
            void RegisterState();
            void MeasureRegister();  
            virtual void ExecState1(void);
            virtual void ExecState2(void);
            
           
   virtual  void live(double dt);
            bool isFinished(void) const;

   // Comparaisons

   friend  bool operator==(const Prog& aP1, const Prog& aP2);
   friend  bool operator!=(const Prog& aP1, const Prog& aP2);

   // Inspecteurs/modificateurs

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const Prog& aP) const;

 protected :

             // ###

 protected :

             vector<QuBit*> _QuBitVector; // To do getAllAgents("QuBit",_QuBitVector);
             int _stateProg;              // -1: Finished
             int _numberQubits;
             bool _decoherenceMode;



   // Methodes protégées d'allocation/desallocation

   void _copy(const Prog& aP);
   void _destroy(void);
   
   

};

#endif // _PROG_H_
