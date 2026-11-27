#include <cmath>
#include <bitset>
#include <string> 
#include<bits/stdc++.h> 

#include "Prog1.h"

#include "MessageX.h"
#include "MessageH.h"
#include "MessageG.h"
#include "MessageM.h"
#include "MessageDecoherence.h"

Prog1::Prog1(bool decoherenceMode): Prog(decoherenceMode)
{

}

Prog1::Prog1(const Prog1& aP): Prog(aP)
{
_copy(aP);
}

Prog1& Prog1::operator=(const Prog1& aP){

  if (this != &aP)
 {
  Prog::operator=(aP);
  _destroy();
  _copy(aP);
 }
 return *this;
}

Prog1::~Prog1(void){
 Prog::_destroy();
}

void Prog1::ExecState1(void)
{
  
  for(size_t j=0;j<_QuBitVector.size();j++)
  {
    Hadamard(_QuBitVector[j],1);  
  }

}
void Prog1::ExecState2(void)
{
     RegisterState();
}
void Prog1::ExecState3(void)
{
     GroverOracle(RecognitionFunction);       
}

void Prog1::ExecState4(void)
{
    MeasureRegister();  
}

ostream& operator<<(ostream& os, const Prog1& aP)
{
 aP.display(os);
 return os;
}

//-- Operators 

bool Prog1::RecognitionFunction(int register_state) // Have to be redefined for each new searched element
{
  return register_state == 5;
}



void Prog1::live(double dt)
{
   (void)dt; // Pour eviter un warning si pas utilise

 if (_QuBitVector.size()==0) { _stateProg = -1; return; }

 // ### : "Comportement" d'un Agent de la classe Prog1
 // #################################################

 cout << "-> " << getName() << "::live" << endl;

 switch (_stateProg)
 {
 // grover algorithm
 case 1 : ExecState1(); _stateProg =  2;
     break;
 case 2 : ExecState2(); _stateProg =  3;  
     break;
 case 3 : ExecState3(); _stateProg =  4; 
     break;
 case 4 : ExecState2(); _stateProg =  5;  
     break;
 case 5 : ExecState4(); _stateProg =  6;  
     break;
 case 6 : ExecState2(); _stateProg =  -1;  
     break;
}
 
 if(_decoherenceMode) Decoherence();
 

 cout << "<- " << getName() << "::live" << endl;
}




void Prog1::display(ostream& os) const
{
(void)os; // Pour eviter un warning si pas utilise

 // Agent::display(os);

 // ### : Affichage des attributs de la classe Prog
 // Exemple : os << _at;

 os << getName() << ":" << endl;
 os << "=======" << endl;
 os << "_stateProg1: " << _stateProg << endl;
 for(size_t i=0;i<_QuBitVector.size();i++)
 {
  cout << *_QuBitVector[i] << endl;
 }
}



