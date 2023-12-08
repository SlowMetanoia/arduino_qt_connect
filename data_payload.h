#ifndef DATA_PAYLOAD_H
#define DATA_PAYLOAD_H



struct incoming_data{

};

//todo: commands structure, replys structure, unification.

struct Payload{
    char start0 = '\0';
    char start1 = '\0';
    incoming_data data;
    char end0 = '\0';
    char end1 = '\0';
};



struct piece_data{
    int32_t n;      //4 bytes - wrong align, when using just int, could be dwd align or something.
    float x;        //4 bytes
    char msg[20];   //20 bytes
};





#endif // DATA_PAYLOAD_H
