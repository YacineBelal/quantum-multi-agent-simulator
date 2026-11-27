#include "MessageBool.h"

//--
MessageBool::MessageBool(bool value) : Message(),_value(value)
{
 newMessage();
}

//--
MessageBool::MessageBool(const MessageBool& aM) : Message(aM)
{
 newMessage();
 _copy(aM);
}

//--
MessageBool& MessageBool::operator=(const MessageBool& aM)
{
 if (this != &aM)
 {
  Message::operator=(aM);
  _destroy();
  _copy(aM);
 }
 return *this;
}

//--
MessageBool::~MessageBool(void)
{
 _destroy();
}

//--
void MessageBool::setValue(bool value)
{
_value = value;
}

bool MessageBool::getValue(void) const
{
return _value;
}


//--
bool operator==(const MessageBool& aM1, const MessageBool& aM2)
{
 return aM1.isEqualTo(aM2);
}

//--
bool operator!=(const MessageBool& aM1, const MessageBool& aM2)
{
 return !(aM1==aM2);
}

//--
ostream& operator<<(ostream& os, const MessageBool& aM)
{
 aM.display(os);
 return os;
}

//--
void MessageBool::display(ostream& os) const
{
 (void)os; // Pour eviter un warning si pas utilise

 // Message::display(os);

 // ### : Affichage des attributs de la classe MessageBool
 // Exemple : os << _at;

 if (_value) os << "true";
 else        os << "false";
}

//--
bool MessageBool::isEqualTo(const MessageBool& aM) const
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe MessageBool
 // Exemple : if (_at != aM._at) return false;

 if (_value != aM._value) return false;

 if (!(Message::isEqualTo(aM))) return false;
 return true;
}

//--
void MessageBool::_copy(const MessageBool& aM)
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe MessageBool
 // Exemple : _at = aM._at;

 _value = aM._value;
}

//--
void MessageBool::_destroy(void)
{
 // ### : Destruction des attributs de la classe MessageBool
 // Exemple : delete _at;
}

