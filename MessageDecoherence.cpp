#include "MessageDecoherence.h"

//--
MessageDecoherence::MessageDecoherence(bool value, float rate) : MessageBool(value), _decoherenceRate(rate)
{
 newMessage();
}

//--
MessageDecoherence::MessageDecoherence(const MessageDecoherence& aM) : MessageBool(aM)
{
 newMessage();
 _copy(aM);
}

//--
MessageDecoherence& MessageDecoherence::operator=(const MessageDecoherence& aM)
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
MessageDecoherence::~MessageDecoherence(void)
{
 _destroy();
}

//--
 void MessageDecoherence::setDecoherenceRate(float rate)
 {
 _decoherenceRate = rate;
 }

float MessageDecoherence::getRate(void) const
{
return _decoherenceRate;
}




//--
bool operator==(const MessageDecoherence& aM1, const MessageDecoherence& aM2)
{
 return aM1.isEqualTo(aM2);
}

//--
bool operator!=(const MessageDecoherence& aM1, const MessageDecoherence& aM2)
{
 return !(aM1==aM2);
}

//--
ostream& operator<<(ostream& os, const MessageDecoherence& aM)
{
 aM.display(os);
 return os;
}

//--
void MessageDecoherence::display(ostream& os) const
{
 (void)os; // Pour eviter un warning si pas utilise

 MessageBool::display(os);

 // ### : Affichage des attributs de la classe MessageDecoherence
 // Exemple : os << _at;
}

//--
bool MessageDecoherence::isEqualTo(const MessageDecoherence& aM) const
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe MessageDecoherence
 // Exemple : if (_at != aM._at) return false;

 if (!(MessageBool::isEqualTo(aM)) ||  _decoherenceRate!= aM.getRate()) return false;
 return true;
}

//--
void MessageDecoherence::_copy(const MessageDecoherence& aM)
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe MessageDecoherence
 // Exemple : _at = aM._at;
_decoherenceRate = aM.getRate();
}

//--
void MessageDecoherence::_destroy(void)
{
 // ### : Destruction des attributs de la classe MessageDecoherence
 // Exemple : delete _at;
}

