#include "RandPool.hpp"

#include <iostream>


unsigned int RandPool::objectCount = 0;

/* initialisation of not used crypto parameters used by Salsa20*/
const byte RandPool::emptyIV[8] =       {0, 0, 0, 0, 0, 0, 0, 0};
const byte RandPool::emptyNonce[8] =    {0, 0, 0, 0, 0, 0, 0, 0};
const byte RandPool::emptyMessage[64] = {0, 0, 0, 0, 0, 0, 0, 0,\
                                         0, 0, 0, 0, 0, 0, 0, 0,\
                                         0, 0, 0, 0, 0, 0, 0, 0,\
                                         0, 0, 0, 0, 0, 0, 0, 0,\
                                         0, 0, 0, 0, 0, 0, 0, 0,\
                                         0, 0, 0, 0, 0, 0, 0, 0,\
                                         0, 0, 0, 0, 0, 0, 0, 0,\
                                         0, 0, 0, 0, 0, 0, 0, 0};



RandPool::RandPool (RandSeed *initSeed)
{
  objectCount++;
  //std::cout << "RandPool instance count: " << objectCount << std::endl;
  for (int i = 0; i < __RAND_POOL__SEED_SIZE; i++) {
    streamCipherKey[i] = *initSeed[i];
  }
  streamCipher = new Salsa20::Encryption(streamCipherKey, Salsa20::DEFAULT_KEYLENGTH, emptyIV);
}

RandPool::~RandPool ()
{
  delete streamCipher;
  objectCount--;
  //std::cout << "RandPool instance count: " << objectCount << std::endl;
}

RandSeed* RandPool::getSubObjectSeed () 
{
  //std::cout << "subObjectSeed: " << std::endl;
  streamCipher->ProcessData (childKey, emptyMessage, 32);
  return (&childKey);
  /*byte randData[64];
  randData[10] = 0;
  for (int i = 0; i < 5; i++) {
    streamCipher->ProcessData (randData, emptyMessage, 10);
    for (int j = 0;j < 10; j++) {
      std::cout << (int) randData[j] << " ";
    }
  }*/
}
