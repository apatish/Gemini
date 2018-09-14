#include "AddressValidator.h"
#include "Menu.h"
#include "Jobcoinmixer.h"

JobCoinMixer jcm;

int main()
{
    AddressValidator av;
    Menu<AddressValidator> menu;
    menu.run(av);
    return 0;
}