
//
// To jest przyk�adowy kod z podrozdzia�u 25.4.1 �Niekontrolowane konwersje� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class Device_driver;

//------------------------------------------------------------------------------

int main()
{
    Device_driver* p = reinterpret_cast<Device_driver*>(0xffb8);
}

//------------------------------------------------------------------------------
