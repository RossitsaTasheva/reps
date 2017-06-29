
/*Изпълнение на клас Интерфейс - клиентът получава само този файл
Като предварително компилиран обемен код, запазвайки изпълнението скрито.*/

#include "Interface.h" // Interface class definition
#include "Implementation.h" // Implementation class definition Изпълнение

// // инициализира ptr, за да сочи към Нов обект за внедряване
Interface::Interface( int v ): ptr ( new Implementation( v ) ){}


void Interface::setValue( int v ) 
{ 
   ptr->setValue( v ); 
}
int Interface::getValue() const 
{ 
   return ptr->getValue(); 
}
Interface::~Interface() 
{ 
   delete ptr; 
}

