#ifndef UNTITLED8_MAIN_H
#define UNTITLED8_MAIN_H

using namespace std;

const string Base64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

void write(int j, char* simbol){
    int k=0;
    while (k < j+1){
        cout <<simbol[k];
        k++;}
}

void Codding(const string &Base64Table, const string &inp) {
    int longs;
    char* simbol = new char[500];
    int i=0, j=0, bytes, ch=0;

    longs = inp.size();
    while ((longs / 3) > ch) {
        ch ++;
        bytes = int (inp[i] >> 2);
        simbol[j] = Base64Table[bytes];

        j++;
        bytes = ((int (inp[i] << 4)) & 0x30) + (int (inp[i+1] >> 4));

        simbol[j] = Base64Table[bytes];
        i++;
        j++;
        bytes = ((int (inp[i] << 2)) & 0x3F) + (int (inp[i+1] >> 6));
        simbol[j] = Base64Table[bytes];
        i++;
        j++;
        bytes = int (inp[i] & 0x3F);
        simbol[j] = Base64Table[bytes];
        j++;
        i++;}
    if (i<longs) {
        bytes = int (inp[i] >> 2);
        simbol[j] = Base64Table[bytes];
        if (i+1<longs) {j++;
            bytes = ((int (inp[i] << 4)) & 0x30) + (int (inp[i+1] >> 4));
            simbol[j] = Base64Table[bytes];
            i++;
            j++;
            bytes = (int (inp[i] << 2)) & 0x3F;
            simbol[j] = Base64Table[bytes];
            j++;
            simbol[j] = Base64Table[64];
        } else {
            j++;
            bytes = (int (inp[i] << 4)) & 0x30;
            simbol[j] = Base64Table[bytes];
            j++;
            simbol[j] = Base64Table[64];
            j++;
            simbol[j] = Base64Table[64];}
    } else {j--;}
    write(j, simbol);
   // return simbol;
}


int getInt(const string &Base64Table, const string &inp, int i) {
    int j ;
    j = 0;
    while (Base64Table[j] != inp[i]) {
        j++;
    }
    return j;
}

char* Decodding(const string &Base64Table, const string &inp) {
    int longs;
    int i = 0, j = 0, bytes, ch = 1;
    char *simbol = new char[500];

    longs = inp.size();
    while ((longs / 4) > ch) {
        ch++;
        bytes = (getInt(Base64Table, inp, i) << 2) + ((getInt(Base64Table, inp, i + 1) >> 4));
        simbol[j] = char(bytes);
        j++;
        i++;

        bytes = ((getInt(Base64Table, inp, i) << 4)) + (getInt(Base64Table, inp, i + 1) >> 2);
        simbol[j] = char(bytes);
        i++;
        j++;

        bytes = ((getInt(Base64Table, inp, i) << 6)) + (getInt(Base64Table, inp, i + 1));
        simbol[j] = char(bytes);
        i = i + 2;
        j++;
    }

    bytes = (getInt(Base64Table, inp, i) << 2) + ((getInt(Base64Table, inp, i + 1) >> 4));
    simbol[j] = char(bytes);
    i++;
    if (inp[i + 1] != '=') {
        j++;
        bytes = ((getInt(Base64Table, inp, i) << 4)) + (getInt(Base64Table, inp, i + 1) >> 2);
        simbol[j] = char(bytes);
        i++;
        if (inp[i + 1] != '=') {
            j++;
            bytes = ((getInt(Base64Table, inp, i) << 6)) + (getInt(Base64Table, inp, i + 1));
            simbol[j] = char(bytes);
        }


        write(j, simbol);

       
    }
}
#endif //UNTITLED8_MAIN_H
