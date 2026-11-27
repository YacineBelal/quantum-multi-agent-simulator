#include <cmath>
#include <bitset>
#include <string> 
#include<bits/stdc++.h> 

#include "Prog.h"
#include "MessageX.h"
#include "MessageH.h"
#include "MessageG.h"
#include "MessageM.h"
#include "MessageDecoherence.h"

//--
Prog::Prog(bool decoherenceMode) : Agent(), _decoherenceMode(decoherenceMode)
{
 newAgent();
 
 vector<Agent*> v; getAllAgents("QuBit",v);

 _QuBitVector.clear();
 for(size_t i=0;i<v.size();i++)
 {
  _QuBitVector.push_back((QuBit*)v[i]);
 }

 _stateProg = 1;
 _numberQubits = v.size();
}

//--
Prog::Prog(const Prog& aP) : Agent(aP)
{
 newAgent();
 _copy(aP);
}

//--
Prog& Prog::operator=(const Prog& aP)
{
 if (this != &aP)
 {
  Agent::operator=(aP);
  _destroy();
  _copy(aP);
  
 }
 return *this;
}

//--
Prog::~Prog(void)
{
 _destroy();
}

void Prog::X(QuBit* qubit)
{
 MessageX m;
 sendMessageTo(m,qubit);
}

void Prog::MeasureQubit(QuBit* qubit)
{
 MessageM m;
 sendMessageTo(m,qubit);
}

void Prog::Hadamard(QuBit* qubit,int size)
{
 MessageH m (true,size);
 sendMessageTo(m,qubit);
}


void Prog::CNOT(QuBit* qubit, QuBit* res_qubit)
{

    if(qubit->getState() == 1 ) // excited o
        {
        MessageX m;
        sendMessageTo(m,res_qubit);
        }

}

void Prog::CNOTN(vector<QuBit*> qubits, QuBit* res_qubit)
{
    int state =1;
    for(size_t i=0;i<qubits.size();i++)
    {
        state *= qubits[i]->getState();
        if(!state) break;
    }
    if(state == 1) // excited
        {
        MessageX m;
        sendMessageTo(m,res_qubit);
        }



}

void Prog::Decoherence() {
 
 MessageDecoherence m;
 for(size_t i=0;i<_QuBitVector.size();i++)
  {
    // generate a random rate of decoherence 
    float rate = random01() / 10 ;
    m.setDecoherenceRate(rate);
    cout << " **** The qubit " << _QuBitVector[i]->getName()  << " suffered environmental decoherence with a rate of : " << rate  << " ****   " << endl;
    sendMessageTo(m,_QuBitVector[i]);
  }

}

void Prog::RegisterState()
{
    
     cout << " **** Putting the qubits together in a register and therefore allowing intrication ! ****   " << endl;
    
    float coef;
    string res;
 for(size_t i=0;i<pow(2,_QuBitVector.size());i++)
    {
     coef=1;   
     bitset<10> Register(i);

     for(size_t j=0;j<_QuBitVector.size();j++)
     {
     coef = coef * _QuBitVector[j]->getProb((int)Register[j]);   
     }
     res = Register.to_string().substr(Register.size()-_QuBitVector.size());
     reverse(res.begin(),res.end());
     cout << coef << " * |" << res << ">  " ;
    
   } 
    cout << endl;
} 

void Prog::GroverOracle(bool (*x)(int)) // can take any recognition function as argument and therefore can be used for different algorithms
{ 
 
 
   cout << " **** Applying the Grover oracle to the register in order to streghten the signal of the searched states ! ****   " << endl;
 for(size_t i=0;i<pow(2,_QuBitVector.size());i++)
 {
   if(x(i)) // elements we're looking for
   {
      bitset<10> Register(i);

      // we tell every qubit what state it needs to streghten in order to get close to the register states we're looking for
      // in order to do that, we send a messageG (grover message) containing it the state it needs to stregthen

      for(size_t j=0;j<_QuBitVector.size();j++)
       {
       MessageG m(true,(int)Register[j]);
       sendMessageTo(m,_QuBitVector[j]);  
       }
   }
 }

}

void Prog::MeasureRegister()
{
     cout << " **** Measuring the register state which implies measuring all qubits ! ****   " << endl;

    for(size_t j=0;j<_QuBitVector.size();j++) 
       {
       MeasureQubit(_QuBitVector[j]);
       }
} 


void Prog::ExecState1(void)
{

  int size = _QuBitVector.size();
  (void)size;
  for(size_t j=0;j<_QuBitVector.size();j++)
  {
    Hadamard(_QuBitVector[j]);  
  }

}

void Prog::ExecState2(void)
{

  RegisterState();
}






//--
void Prog::live(double dt)
{
 (void)dt; // Pour eviter un warning si pas utilise

 if (_QuBitVector.size()==0) { _stateProg = -1; return; }

 // ### : "Comportement" d'un Agent de la classe Prog
 // #################################################

 cout << "-> " << getName() << "::live" << endl;

 switch (_stateProg)
 {
 case 1 : ExecState2(); _stateProg =  2;
     break;
 case 2 : ExecState2(); _stateProg =  -1;  
     break;
 }
 if(_decoherenceMode) Decoherence();
 

 cout << "<- " << getName() << "::live" << endl;
}

bool Prog::isFinished(void) const
{
 return _stateProg == -1;
}

//--
bool operator==(const Prog& aP1, const Prog& aP2)
{
 return aP1.isEqualTo(aP2);
}

//--
bool operator!=(const Prog& aP1, const Prog& aP2)
{
 return !(aP1==aP2);
}

//--
ostream& operator<<(ostream& os, const Prog& aP)
{
 aP.display(os);
 return os;
}

//--
void Prog::display(ostream& os) const
{
 (void)os; // Pour eviter un warning si pas utilise

 // Agent::display(os);

 // ### : Affichage des attributs de la classe Prog
 // Exemple : os << _at;

 os << getName() << ":" << endl;
 os << "=======" << endl;
 os << "_stateProg: " << _stateProg << endl;
 for(size_t i=0;i<_QuBitVector.size();i++)
 {
  cout << *_QuBitVector[i] << endl;
 }
}

//--
bool Prog::isEqualTo(const Prog& aP) const
{
 (void)aP; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe Prog
 // Exemple : if (_at != aP._at) return false;

 if (_stateProg != aP._stateProg)     return false;
 if (_QuBitVector != aP._QuBitVector) return false;

 if (!(Agent::isEqualTo(aP))) return false;
 return true;
}

//--
void Prog::_copy(const Prog& aP)
{
 (void)aP; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe Prog
 // Exemple : _at = aP._at;
 
 _stateProg   = aP._stateProg;
 _QuBitVector = aP._QuBitVector;
 _decoherenceMode = aP._decoherenceMode;
}

//--
void Prog::_destroy(void)
{
 // ### : Destruction des attributs de la classe Prog
 // Exemple : delete _at;

 _QuBitVector.clear();
}
