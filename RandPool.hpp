#ifndef __RAND_POOL_H__
#define __RAND_POOL_H__

#include <cstdint>

#include <cryptopp/salsa.h>

using namespace CryptoPP;

#define __RAND_POOL__SEED_SIZE 32

//class RandSeed
//{
//  byte seed[__RAND_POOL__SEED_SIZE];

typedef byte RandSeed[64];

class RandPool
{
public:
    RandPool (RandSeed *initSeed);
    ~RandPool ();

    template <typename T>
    T getRand ();
    void getRandArray (uint32_t arraySize);
    RandSeed* getSubObjectSeed ();

private:
    static unsigned int objectCount;

    static const byte emptyIV[Salsa20::IV_LENGTH];
    static const byte emptyNonce[8];
    static const byte emptyMessage[64];

    RandSeed childKey;
    RandSeed streamCipherKey;
    //class CryptoPP::Salsa20 streamCipher;
    Salsa20::Encryption *streamCipher;
};

#endif
