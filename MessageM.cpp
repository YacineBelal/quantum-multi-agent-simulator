#include "MessageM.h"

//--
MessageM::MessageM(bool value) : MessageBool(value)
{
 newMessage();
}

//--
MessageM::MessageM(const MessageM& aM) : MessageBool(aM)
{
 newMessage();
 _copy(aM);
}

//--
MessageM& MessageM::operator=(const MessageM& aM)
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
MessageM::~MessageM(void)
{
 _destroy();
}

//--
bool operator==(const MessageM& aM1, const MessageM& aM2)
{
 return aM1.isEqualTo(aM2);
}

//--
bool operator!=(const MessageM& aM1, const MessageM& aM2)
{
 return !(aM1==aM2);
}

//--
ostream& operator<<(ostream& os, const MessageM& aM)
{
 aM.display(os);
 return os;
}

//--
void MessageM::display(ostream& os) const
{
 (void)os; // Pour eviter un warning si pas utilise

 MessageBool::display(os);

 // ### : Affichage des attributs de la classe MessageM
 // Exemple : os << _at;
}

//--
bool MessageM::isEqualTo(const MessageM& aM) const
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe MessageM
 // Exemple : if (_at != aM._at) return false;

 if (!(MessageBool::isEqualTo(aM))) return false;
 return true;
}

//--
void MessageM::_copy(const MessageM& aM)
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe MessageM
 // Exemple : _at = aM._at;
}

//--
void MessageM::_destroy(void)
{
 // ### : Destruction des attributs de la classe MessageM
 // Exemple : delete _at;
}

