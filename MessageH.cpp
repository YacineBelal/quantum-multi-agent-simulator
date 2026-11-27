#include "MessageH.h"

//--
MessageH::MessageH(bool value,int size) : MessageBool(value), _size(size)
{
 newMessage();
}

//--
MessageH::MessageH(const MessageH& aM) : MessageBool(aM)
{
 newMessage();
 _copy(aM);
}

//--
MessageH& MessageH::operator=(const MessageH& aM)
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
MessageH::~MessageH(void)
{
 _destroy();
}

//--
bool operator==(const MessageH& aM1, const MessageH& aM2)
{
 return aM1.isEqualTo(aM2);
}

//--
bool operator!=(const MessageH& aM1, const MessageH& aM2)
{
 return !(aM1==aM2);
}

//--
ostream& operator<<(ostream& os, const MessageH& aM)
{
 aM.display(os);
 return os;
}


//--
int MessageH::getSize(void) const
{
return _size;
}
void MessageH::setSize(int size) 
{
_size = size;
}


//--
void MessageH::display(ostream& os) const
{
 (void)os; // Pour eviter un warning si pas utilise

 MessageBool::display(os);

 // ### : Affichage des attributs de la classe MessageH
 // Exemple : os << _at;
}

//--
bool MessageH::isEqualTo(const MessageH& aM) const
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe MessageH
 // Exemple : if (_at != aM._at) return false;

 if (!(MessageBool::isEqualTo(aM)) || aM._size != _size) return false;
 return true;
}

//--
void MessageH::_copy(const MessageH& aM)
{
 (void)aM; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe MessageH
 // Exemple : _at = aM._at;   
 _size = aM._size;
}

//--
void MessageH::_destroy(void)
{
 // ### : Destruction des attributs de la classe MessageH
 // Exemple : delete _at;
}

