#include <cmath>

#include "QuBit.h"
#include "MessageBool.h"
#include "MessageX.h"
#include "MessageH.h"
#include "MessageG.h"
#include "MessageM.h"
#include "MessageDecoherence.h"


// https://www.wikiwand.com/fr/Qubit
// https://www.wikiwand.com/fr/Porte_quantique

//--
QuBit::QuBit(void) : Agent()
{
 newAgent();

 _prob0 = random01();
 _prob1 = 1 - _prob0;

 _setState(); // On defini l'etat du qubit selon les probabilites.
}

//--
QuBit::QuBit(float prob0,float prob1) : Agent(),
                                        _prob0(prob0),_prob1(prob1),
                                        _prob0Next(prob0),_prob1Next(prob1)
{
 if(_prob0 + _prob1 != 1)
   throw  string("Erreur d'intialisation du Qubit. La somme des probabilites doit etre égale a 1");
 newAgent();

 _setState(); // On defini l'etat du qubit selon les probabilites.
}

//--
QuBit::QuBit(const QuBit& aQ) : Agent(aQ)
{
 newAgent();
 _copy(aQ);
}

//--
QuBit& QuBit::operator=(const QuBit& aQ)
{
 if (this != &aQ)
 {
  Agent::operator=(aQ);
  _destroy();
  _copy(aQ);
 }
 return *this;
}

//--
QuBit::~QuBit(void)
{
 _destroy();
}

//--
//-- getteurs and setteurs

float QuBit::getProb0(void) const
{
    return _prob0;
}

float QuBit::getProb1(void) const
{
  return _prob1;
}

float QuBit::getProb(int state) const
{
  if(state) return _prob1; else return _prob0;
}

void QuBit::_setState() // On defini l'etat du qubit selon les probabilites.
{
 _state = _prob0 == 1 ? Calm : _prob1 == 1 ? Excited : Superposition ;
}

QuBitState QuBit::getState(void) const
{
 return _state;
}

string QuBit::getStateString (void) const
{
 switch (_state)
 {
  case 0 : return "Calm";
  case 1 : return "Excited";
  default: return "Superposition";
 }
}

//--
void  QuBit::synchronizeQuBit(void)
{
_prob0 = _prob0Next;
_prob1 = _prob1Next;
_setState();
}

//--
void QuBit::live(double dt)
{
 (void)dt; // Pour eviter un warning si pas utilise
 size_t nb; (void)nb;

 cout << "-> " << getName() << " Begin: " << getStateString() << endl;

 nb = treatAllMessages();
 // if (nb!=0) cout << getName() << " treated " << nb << " message(s)" << endl;

 cout << "<- " << getName() << " End: " << getStateString() << endl;
}

//--
size_t QuBit::treatAllMessages(void)
{
 size_t nbMessages = getNbMessages();

 while (getNbMessages())
 {
  Message* m = getNextMessage();

  if (m->isA("MessageX")) // fliping message 
  {
   X();
  }
  else
  if (m->isA("MessageH")) // superposition state message
  {
   MessageH* MH = dynamic_cast<MessageH*>(m); 
   Hadamard(MH->getSize());
  }
  else
  if (m->isA("MessageG")) // grover operator message
  {
  MessageG* MG = dynamic_cast<MessageG*>(m);
  G(MG->getState());
  }
  else
  if (m->isA("MessageM")) // measuring message
  {
  measure();
  }
  else
  if (m->isA("MessageDecoherence")) // decoherence message
  {
   MessageDecoherence* MD = dynamic_cast<MessageDecoherence*>(m);
  Decoherence(MD->getRate());
  }
  if (m->isA("MessageBool")) { MessageBool* MB = (MessageBool*)m; cout << *MB << endl; }

  delete m;
 }

 return nbMessages;
}

//--
void QuBit::X(void)
{
 cout << "Applying X gate to Qubit " << getName()
      << " , state : " << getStateString() << endl;
 _prob0Next = _prob1;
 _prob1Next = _prob0;
}

//--
void QuBit::Hadamard(int size)
{
cout << "Applying Hadamard gate to Qubit " << getName()
      << " , state : " << getStateString() << endl;
 _prob0Next = 1/ pow(2,size);
 _prob1Next = 1/ pow(2,size);

} 
//--
void QuBit::G(int state)
{
cout << "Applying Grover gate to Qubit " << getName()
      << " , state : " << getStateString() << endl;
 
 float max = _prob0 < _prob1 ? _prob0 : _prob1;
 float r= ( max * ((float)rand() / RAND_MAX));
 if(state)
 {
 _prob0Next -= r;
 _prob1Next += r;
 }else
 {
 _prob0Next += r;
 _prob1Next -= r;
 }
 

} 

void QuBit::Decoherence(float rate) 
{
  if(_prob0 < _prob1 )
    {
    _prob1Next -= rate;
    _prob0Next += rate;   
    }else
    {
    _prob1Next += rate;
    _prob0Next -= rate;  
    }
    
}




//-- The qubit will fall in one of the two basic states after measuring it
void QuBit::measure(void)
 {
  float r = random01();
  
  if(_prob0 < _prob1 )
  {
    if(r <_prob0 )
    { _prob0Next = 1;
      _prob1Next = 0;
    }else
    {
      _prob0Next = 0;
      _prob1Next = 1;
    } 
  }else
  {
    if(r <_prob1 )
    { _prob0Next = 0;
      _prob1Next = 1;
    }else
    {
      _prob0Next = 1;
      _prob1Next = 0;
    }

  }
   

 }

//--
bool operator==(const QuBit& aQ1, const QuBit& aQ2)
{
 return aQ1.isEqualTo(aQ2);
}

//--
bool operator!=(const QuBit& aQ1, const QuBit& aQ2)
{
 return !(aQ1==aQ2);
}

//--
ostream& operator<<(ostream& os, const QuBit& aQ)
{
 aQ.display(os);
 return os;
}

//--
void QuBit::display(ostream& os) const
{
 (void)os; // Pour eviter un warning si pas utilise

 // Agent::display(os);

 // ### : Affichage des attributs de la classe QuBit
 // Exemple : os << _at;

#if 0
 os << "_prob0:" << _prob0 << endl;
 os << "_prob1:" << _prob1 << endl;
 os << "_prob0Next:" << _prob0Next << endl;
 os << "_prob1Next:" << _prob1Next << endl;
 os << "_state: " << getStateString() << endl;
#else
 os << getName() << ": " << getStateString();
 os << "(" << _prob0 << "," << _prob1 << ")";
#endif
}

//--
bool QuBit::isEqualTo(const QuBit& aQ) const
{
 (void)aQ; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe QuBit
 // Exemple : if (_at != aQ._at) return false;

 if (_prob0     != aQ._prob0)     return false;
 if (_prob1     != aQ._prob1)     return false;
 if (_prob0Next != aQ._prob0Next) return false;
 if (_prob1Next != aQ._prob1Next) return false;
 if (_state     != aQ._state)     return false;

 if (!(Agent::isEqualTo(aQ))) return false;
 return true;
}

//--
void QuBit::_copy(const QuBit& aQ)
{
 (void)aQ; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe QuBit
 // Exemple : _at = aQ._at;

 _prob0     = aQ._prob0;
 _prob1     = aQ._prob1;
 _prob0Next = aQ._prob0Next;
 _prob1Next = aQ._prob1Next;
 _state     = aQ._state;
}

//--
void QuBit::_destroy(void)
{
 // ### : Destruction des attributs de la classe QuBit
 // Exemple : delete _at;
}

