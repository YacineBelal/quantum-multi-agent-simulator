#include "MessageX.h"

//--
MessageX::MessageX(bool value) : MessageBool(value)
{
 newMessage();
}

//--
MessageX::MessageX(const MessageX& aM) : MessageBool(aM)
{
 newMessage();
 _copy(aM);
}

//--
MessageX& MessageX::operator=(const MessageX& aM)
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
MessageX::~MessageX(void)
{
 _destroy();
}

//--
bool operator==(const MessageX& aM1, const MessageX& aM2)
{
 return aM1.isEqualTo(aM2);
}

//--
bool operator!=(const MessageX& aM1, const MessageX& aM2)
{
 return !(aM1==aM2);
}

//--
ostream& operator<<(ostream& os, const MessageX& aM)
{
 aM.display(os);
 return os;
}

//--
void MessageX::display(ostream& os) const
{
 (void)os; // Pour eviter un warning si pas utilise

 MessageBool::display(os);

 // ### : Affichage des attributs de la classe MessageX
 // Exemple : os << _at;
}

//--
bool MessageX::isEqualTo(const MessageX& aM) const
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe MessageX
 // Exemple : if (_at != aM._at) return false;

 if (!(MessageBool::isEqualTo(aM))) return false;
 return true;
}

//--
void MessageX::_copy(const MessageX& aM)
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe MessageX
 // Exemple : _at = aM._at;
}

//--
void MessageX::_destroy(void)
{
 // ### : Destruction des attributs de la classe MessageX
 // Exemple : delete _at;
}

