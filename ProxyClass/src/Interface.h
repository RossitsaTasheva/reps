

class Implementation;

class Interface 
{
public:
   Interface( int );
   void setValue( int );
   int getValue() const;
   ~Interface();
private:
   //Изисква предварителна декларация по-рано
   Implementation *ptr;   
};


