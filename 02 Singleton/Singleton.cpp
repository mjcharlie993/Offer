#include "Singleton.h"

int main()
{
    const President& president1 = President::getInstance();
    const President& president2 = President::getInstance();

    // same address, point to same object.
    assert(&president1 == &president2);
}