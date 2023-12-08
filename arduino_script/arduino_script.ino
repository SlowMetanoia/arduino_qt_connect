

struct piece_data{
  int32_t n;      //4 bytes - wrong align, when using just int, could be dwd align or something.
  float x;        //4 bytes
  char msg[20];   //20 bytes
  };
/*
piece_data rcv_pd(){
  char result[sizeof(piece_data)];
  Serial.readBytes((char*)&result, sizeof(piece_data));
  return (piece_data)result;
}
*/
piece_data pd = piece_data{121,37.7,"Hollow world"};

int a = 420;
String reply = "old";
void setup() {
    Serial.begin(9600);
    while(Serial.available()==0){
      delay(100);
    }
    reply = Serial.readString();
}

// the loop routine runs over and over again forever:
void loop() {
  /*
  if(Serial.available()>0){
    //stability delay. todo: try removing
    delay(2);
    //if there is some trash in chanel, pop it off until reading '\0' - our start/stop byte.
    while(Serial.read()!= '\0');
    }*/
    
  // print out the value you read:
  //Serial.println("#"+reply+"#");
  Serial.write((char*)&pd,sizeof(pd));
  delay(1000);        // delay in between reads for stability
}
