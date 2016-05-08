#include <iostream>
#include <string>

#include <cstdint>

#include "RandPool.hpp"

int main (void)
{
    RandSeed seed;
    for (unsigned char i = 0; i < 32; i++) {
        seed[i] = i;
    }
    /*{
      RandPool highest_object (seed);
      }*/
    RandPool *r1 = new RandPool (&seed);
    RandPool *r2 = new RandPool (r1->getSubObjectSeed ());
    uint32_t failed_mem = 0;
    //std::string *a;
    /*for (int i = 1; i <= 1000000; i++) {
      a = new std::string ("bla");
      if (i % 1000 == 0) {
      //std::cout << i << " " << std::flush;
      }
      }*/
    std::cout << 1 << std::endl << std::flush;
    for (int i = 0; i < 1000000; i++) {
        r2 = new RandPool (r1->getSubObjectSeed ());
    }
    RandPool highest_object (&seed);
    RandPool highest_object2 (highest_object.getSubObjectSeed ());
    std::cout << 2 << std::flush;
    /*for (int i = 0; i < 10000000; i++) {
      (void) r2->getSubObjectSeed();
      }*/
    //for (i = 0; i < 64; i++) {
    //  highes_object.getSubObjectSeed ();
    //}

    //highest_object.getSubObjectSeed ();
    std::cout << "f: " << failed_mem << std::endl;
    return (0);
}
