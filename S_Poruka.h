#ifndef S_PORUKA_H_INCLUDED
#define S_PORUKA_H_INCLUDED

enum Tip{
    KoSi,
    Normalna,
    JaSam
};

struct S_Poruka{
    char nadimak[20];
    char poruka[256];
    Tip tip;
};

#endif // S_PORUKA_H_INCLUDED
