struct piece_data{
  int32_t n;      //4 bytes - wrong align, when using just int, could be dwd align or something.
  float x;        //4 bytes
  char msg[20];   //20 bytes
};

//template receive function. Usage: receive<piece_data>() or receive<int32_t> - would work
template<typename T>
T receive(){
  T result;
  Serial.readBytes((char*)&result, sizeof(T));
  return result;
}

piece_data reply;

void  setup() {
    Serial.begin(9600);
    //Serial.readBytes((char*)&reply, sizeof(piece_data));
}

void loop() {
    while(Serial.available()==0)
      delay(1);
    reply = receive<piece_data>();
    Serial.write((char*)&reply,sizeof(piece_data));
}
