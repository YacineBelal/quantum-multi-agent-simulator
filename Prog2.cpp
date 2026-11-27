#include <cmath>
#include <bitset>
#include <string> 
#include<bits/stdc++.h> 

#include "Prog2.h"

#include "MessageX.h"
#include "MessageH.h"
#include "MessageG.h"
#include "MessageM.h"
#include "MessageDecoherence.h"

Prog2::Prog2(bool decoherenceMode): Prog(decoherenceMode)
{

}

Prog2::Prog2(const Prog2& aP): Prog(aP)
{
_copy(aP);
}

Prog2& Prog2::operator=(const Prog2& aP){

  if (this != &aP)
 {
  Prog::operator=(aP);
  _destroy();
  _copy(aP);
 }
 return *this;
}

Prog2::~Prog2(void){
 Prog2::_destroy();
}

void Prog2::ExecState1(void)
{
 
  for(size_t j=0;j<_QuBitVector.size();j++)
  {
    Hadamard(_QuBitVector[j]);  
  } 
}
void Prog2::ExecState2(void)
{
     RegisterState();
}
void Prog2::ExecState3(void)
{
     cout << " **** Mesuring the first qubit, which will make him loose his quantum state : **** "  << endl;
     MeasureQubit(_QuBitVector[0]);
}

void Prog2::live(double dt)
{
    (void)dt; // Pour eviter un warning si pas utilise

 if (_QuBitVector.size()==0) { _stateProg = -1; return; }

 // ### : "Comportement" d'un Agent de la classe Prog
 // #################################################

 cout << "-> " << getName() << "::live" << endl;

 switch (_stateProg)
 {
 case 1 : ExecState1(); _stateProg =  2;
     break;
 case 2 : ExecState2(); _stateProg =  3;  
     break;
 case 3 : ExecState3(); _stateProg =  4; 
     break;
 case 4 : ExecState2(); _stateProg = -1;  
     break;
}
 if(_decoherenceMode) Decoherence();
 

 cout << "<- " << getName() << "::live" << endl;
}


ostream& operator<<(ostream& os, const Prog2& aP)
{
 aP.display(os);
 return os;
}


void Prog2::display(ostream& os) const
{
(void)os; // Pour eviter un warning si pas utilise

 // Agent::display(os);

 // ### : Affichage des attributs de la classe Prog
 // Exemple : os << _at;

 os << getName() << ":" << endl;
 os << "=======" << endl;
 os << "_stateProg2: " << _stateProg << endl;
 for(size_t i=0;i<_QuBitVector.size();i++)
 {
  cout << *_QuBitVector[i] << endl;
 }
}



