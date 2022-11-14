#include <iostream>
using namespace std;

// Single Inheritance : Bir clasdan  bashqa class toreye biler.
//Class Son Class Father.den toreyib.

class Father {};

class Son : public Father {};


// Multi level inheritance : Bir clasdan xetti ardicilliqla bashqa class ve diger classlar toreye biler. 
//Class GrandChild Class Son.dan , Class Son Class Father.den toreyib.

class Father {};

class Son : public Father {};

class GrandChild : public Son {};

// Multiple inheritance  : Bir neche classdan  bir class toreye biler.
//Class Son Class Father ve Class Mother.den toreyib.

class Father {};

class Mother {};

class Son : public Mother, public Father {};

// Hierarchy : Bir classdan bir neche class , ve hemin classlardan da bir neche class ve bu qanunauygunluqla classlar  toreye biler.
// Father.den Class Daughter ve Class Son Class ,
// Class Son.dan Class GrandSon1 ve Class GrandDaughter1 , 
// Daughter.dan Class GrandSon2 ve Class GrandDaughter2 Class toreyib.

class Father {};

class Son : public Father {};

class Daughter : public Father {};

class GrandSon1 : public Son {};

class GrandDaughter1 : public Son {};

class GrandSon2 : public Daughter {};

class GrandDaughter2 : public Daughter {};