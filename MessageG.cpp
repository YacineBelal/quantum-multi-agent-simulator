#include "MessageG.h"

//--
MessageG::MessageG(bool value,int state) : MessageBool(value), _state(state)
{
 newMessage();
}

//--
MessageG::MessageG(const MessageG& aM) : MessageBool(aM)
{
 newMessage();
 _copy(aM);
}

//--
MessageG& MessageG::operator=(const MessageG& aM)
{
 if (this != &aM)
 {
  MessageBool::operator=(aM);
  _destroy();
  _copy(aM);
 }
 return *this;
}

//--
MessageG::~MessageG(void)
{
 _destroy();
}

//--
bool operator==(const MessageG& aM1, const MessageG& aM2)
{
 return aM1.isEqualTo(aM2);
}

//--
bool operator!=(const MessageG& aM1, const MessageG& aM2)
{
 return !(aM1==aM2);
}

//--
ostream& operator<<(ostream& os, const MessageG& aM)
{
 aM.display(os);
 return os;
}


//--
int MessageG::getState(void) const
{
return _state;
}
void MessageG::setState(int state) 
{
_state = state;
}


//--
void MessageG::display(ostream& os) const
{
 (void)os; // Pour eviter un warning si pas utilise

 MessageBool::display(os);

 // ### : Affichage des attributs de la classe MessageG
 // Exemple : os << _at;
}

//--
bool MessageG::isEqualTo(const MessageG& aM) const
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe MessageG
 // Exemple : if (_at != aM._at) return false;

 if (!(MessageBool::isEqualTo(aM)) || aM._state != _state) return false;
 return true;
}

//--
void MessageG::_copy(const MessageG& aM)
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe MessageG
 // Exemple : _at = aM._at;   
 _state = aM._state;
}

//--
void MessageG::_destroy(void)
{
 // ### : Destruction des attributs de la classe MessageG
 // Exemple : delete _at;
}

