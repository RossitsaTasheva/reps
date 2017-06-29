// Fig. 10.24: Implementation.h
// Header file for class Implementation

class Implementation 
{
public:
	// инициализира стойността с v
   Implementation( int v ): value( v )
   {}

   void setValue( int v ){value = v;}
   int getValue() const{return value;}

private:
   int value;
};
